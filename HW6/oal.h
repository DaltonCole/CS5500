#ifndef OAL_H
#define OAL_H

#include <string>
#include <unordered_map>
#include <vector>
#include <memory>

struct Instruction {
	string opCode;
	int addr;
	string jump_addr;
	int la_level;

	Instruction() {
		opCode = "";
		addr = -999999;
		jump_addr = "";
		la_level = 0;
	}

	Instruction(string op) {
		opCode = op;
		addr = -999999;
		jump_addr = "";
		la_level = 0;
	}

	Instruction(string op, int address) {
		opCode = op;
		addr = address;
		jump_addr = "";
		la_level = 0;
	}

	Instruction(string op, string jump_address) {
		opCode = op;
		addr = -999999;
		jump_addr = jump_address;
		la_level = 0;
	}

	Instruction(string op, int address, int level) {
		opCode = op;
		addr = address;
		jump_addr = "";
		la_level = level;
	}

	string make_string() {
		if(opCode.size() > 0 && opCode[0] != 'L') {
			opCode = "  " + opCode;
		} else if(opCode != "L.1:\n  bss 500\n  end") {
			opCode += ":";
		}

		if(addr == -999999 && jump_addr == "") {
			return opCode;
		} else if(addr == -999999) {
			return opCode + " " + jump_addr;
		} else {
			if(opCode == "  la" || opCode == "  save" || opCode == "  push" || opCode == "  pop") {
				return opCode + " " + to_string(addr) + ", " + to_string(la_level);
			} else {
				return opCode + " " + to_string(addr);
			}
		}
	}
};

struct Proc_tree {
	string proc_id;
	int level;
	vector<shared_ptr<Proc_tree> > children;
	shared_ptr<Proc_tree> parent;

	Proc_tree() {
		proc_id = "";
		level = 0;
		parent = nullptr;
	}

	shared_ptr<Proc_tree> add_new_node_from_base(string name, int lv, shared_ptr<Proc_tree> par) {
		if(level == lv - 1) {
			shared_ptr<Proc_tree> left(new Proc_tree());
			left -> proc_id = name;
			left -> level = lv;
			left -> parent = par;
			children.push_back(left);
			return left;
		}
		return children.back() -> add_new_node_from_base(name, lv, children.back());
	}

	bool check_current_level(string proc) {
		for(auto i : children) {
			if(i -> proc_id == proc) {
				return true;
			}
		}
		return false;
	}

	int find_level_difference(string proc) {
		if(level == 0) {
			return 0;
		}
		if(level != 0) {
			for(auto i : parent -> children) {
				if(i -> proc_id == proc) {
					return level - 1;
				}
			}
		}
		return parent -> find_level_difference(proc);
	}
};

class Oal {
	public:
		// Instruction list
		vector<Instruction> insts;
		// Procedure list
		vector<Instruction> proc;
		// Variable to memory address
		vector<unordered_map<string, int> > var_to_addr;
		// Current variable addr to add
		vector<int> addr;
		// Variable to procedure
		unordered_map<string, string> var_to_proc;
		// In proc or main
		bool in_proc;
		//
		shared_ptr<Proc_tree> p_tree;
		shared_ptr<Proc_tree> current_p_tree;

		// Remember original addr size
		int original_addr_size;

		// Current label
		static int label;

		Oal() {
			insts.push_back(Instruction());
			var_to_addr.push_back(unordered_map<string, int>());
			addr.push_back(20);
			p_tree = shared_ptr<Proc_tree>(new Proc_tree());
			current_p_tree = p_tree;
		}

		void begin_proc(string s) {
			var_to_proc[s] = new_label();
			in_proc = true;
			addr.push_back(0);
			var_to_addr.push_back(unordered_map<string, int>());
			var_to_addr.back()[s] = var_to_addr.size() - 1;

			current_p_tree = p_tree -> add_new_node_from_base(s, addr.size() - 1, current_p_tree);
		}
		void end_proc() {
			in_proc = false;
			for(auto inst : proc) {
				insts.push_back(inst);
			}
			proc.clear();
			push_back(Instruction("ji"));
			addr.pop_back(); // Rest addr
			var_to_addr.pop_back();

			current_p_tree = current_p_tree -> parent;
		}

		void la(string var) {
			push_back(Instruction("la", find_var(var), find_level(var)));
		}

		int find_level(string var) {
			for(int i = var_to_addr.size() - 1; i >= 0; i--) {
				if(var_to_addr[i].find(var) != var_to_addr[i].end()) {
					return i;
				}
			}
			return -1;
		}

		void push_back(const Instruction& inst) {
			if(in_proc == false) {
				insts.push_back(inst);
			} else {
				proc.push_back(inst);
			}
		}

		string get_proc(string s) {
			return var_to_proc[s];
		}

		/*
		void pop_back() {
			if(insts.size() > 1) {
				insts.pop_back();
			}
		}
		*/

		void make_header() {
			//   init L.0, 20, L.1, L.2, L.3
			string header = "init L.0, 20, L.1, L.2, L.3";
			header += "\nL.0:";
			header += "\n  bss ";
			if(original_addr_size != 0) {
				header += to_string(original_addr_size);
			} else {
				header += to_string(addr[0]);
			}
			header += "\nL.2:";
			Instruction head(header);
			// Insert header to front of insts
			insts[0] = header;
			// Make tail
			make_tail();
		}

		void make_tail() {
			string tail = "L.1:\n  bss 500\n  end";
			Instruction ta(tail);
			insts.push_back(ta);
		}

		void print() {
			for(auto inst : insts) {
				cout << inst.make_string() << endl;
			}
		}

		static string new_label() {
			string n_lab = "L." + to_string(label);
			Oal::label++;
			return n_lab;
		}

		void add_addr(string var) {
			var_to_addr.back()[var] = addr.back();
			addr.back()++;
		}


		void add_addr(string var, int lower_bound, int upper_bound) {
			/*
			var_to_addr.back()[var] = addr.back() - (1 + upper_bound - lower_bound) - 1;
			addr.back() += (upper_bound - lower_bound + 1); // ??
			*/

			var_to_addr.back()[var] = addr.back() - lower_bound;
			addr.back() += (upper_bound - lower_bound + 1);
		}

		bool var_exists(string var) {
			if(var_to_addr.back().find(var) != var_to_addr.back().end()) {
				return true;
			}
			return false;
		}
		int find_var(string s) {
			for(int i = var_to_addr.size() - 1; i >= 0; i--) {
				if(var_to_addr[i].find(s) != var_to_addr[i].end()) {
					return var_to_addr[i][s];
				}
			}
			return -999999;
		}

		string find_proc(string s) {
			return var_to_proc[s];
		}

		void add_asp() {
			if(in_proc == true) {
				if(addr.back() != 0) {
					push_back(Instruction("asp", to_string(addr.back())));
				}
			}
		}

		void remove_asp() {
			if(in_proc == true) {
				if(addr.back() != 0) {
					push_back(Instruction("asp", "-" + to_string(addr.back())));
				}
			}
		}

		void js(string ident) {

			if(in_proc == false) {
				push_back(Instruction("js", find_proc(ident)));
			} else if(current_p_tree -> check_current_level(ident)) {
				push_back(Instruction("js", find_proc(ident)));
			} else {
				//int level = find_level(ident);

				int level = current_p_tree -> find_level_difference(ident);

				for(int i = var_to_addr.size() - 1; i > level; i--) {
					push_back(Instruction("push", i));
				}
				
				push_back(Instruction("js", find_proc(ident)));

				for(int i = level + 1; i < var_to_addr.size(); i++) {
					push_back(Instruction("pop", i));
				}
			}

		}

		/*
		bool last_inst(string s) {
			return insts.back().opCode == s;
		}
		*/
};

// Current label
// 0-3 used for init
int Oal::label = 4;

#endif