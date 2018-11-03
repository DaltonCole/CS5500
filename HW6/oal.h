#ifndef OAL_H
#define OAL_H

#include <string>
#include <unordered_map>
#include <vector>

struct Instruction {
	string opCode;
	int addr;
	string jump_addr;

	Instruction() {
		opCode = "";
		addr = -1;
		jump_addr = "";
	}

	Instruction(string op) {
		opCode = op;
		addr = -1;
		jump_addr = "";
	}

	Instruction(string op, int address) {
		opCode = op;
		addr = address;
		jump_addr = "";
	}

	Instruction(string op, string jump_address) {
		opCode = op;
		addr = -1;
		jump_addr = jump_address;
	}

	string make_string() {
		if(opCode.size() > 0 && opCode[0] != 'L') {
			opCode = "  " + opCode;
		}

		if(addr == -1 && jump_addr == "") {
			return opCode;
		} else if(addr == -1) {
			return opCode + " " + jump_addr;
		} else {
			if(opCode == "  la") {
				return opCode + " " + to_string(addr) + ", 0";
			} else {
				return opCode + " " + to_string(addr);
			}
		}
	}
};

class Oal {
	public:
		// Instruction list
		vector<Instruction> insts;
		// Variable to memory address
		unordered_map<string, int> var_to_addr;

		// Current label
		static int label;
		// Current variable addr to add
		static int addr;

		Oal() {
			insts.push_back(Instruction());
		}

		void push_back(const Instruction& inst) {
			insts.push_back(inst);
		}

		void pop_back() {
			if(insts.size() > 1) {
				insts.pop_back();
			}
		}

		void make_header() {
			//   init L.0, 20, L.1, L.2, L.3
			string header = "init L.0, 20, L.1, L.2, L.3";
			header += "\nL.0:";
			header += "\n  bss " + to_string(20 + var_to_addr.size());
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
			string n_lab = "L." + to_string(label) + ":";
			Oal::label++;
			return n_lab;
		}

		void add_addr(string var) {
			var_to_addr[var] = addr;
			Oal::addr++;
		}

		bool var_exists(string var) {
			if(var_to_addr.find(var) != var_to_addr.end()) {
				return true;
			}
			return false;
		}

		int find_var(string s) {
			return var_to_addr[s];
		}

		bool last_inst(string s) {
			return insts.back().opCode == s;
		}
};

// Current label
// 0-3 used for init
int Oal::label = 3;
int Oal::addr = 20;

#endif