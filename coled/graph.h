// Dalton Cole

#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <memory>
#include <string>
#include "quad.h"
using namespace std;

bool is_number(const std::string& s);

struct Node {
	int instruction_number;
	string value; // ex: 2, r, * 	(op or result if no label)
	string label; // ex: t1, z		(result)

	shared_ptr<Node> left; // z = LEFT * RIGHT
	shared_ptr<Node> right;

	// Set value
	Node(const Quad& inst) {
		value = inst.result;
		label = "";
		left = nullptr;
		right = nullptr;
		instruction_number = -1;
	}

	// Set value
	Node(const string& val) {
		value = val;
		label = "";
		left = nullptr;
		right = nullptr;
		instruction_number = -1;
	}

	// Set value - Shouldn't be needed
	Node(const int& val) {
		value = to_string(val);
		label = "";
		left = nullptr;
		right = nullptr;
		instruction_number = -1;
	}

	// Set value, label, and instruction_number
	// Make left and right point to their respective nodes
	Node(const Quad& inst, shared_ptr<Node>& lhs, shared_ptr<Node>& rhs, const int& inst_num) {
		value = inst.op;
		label = inst.result;
		instruction_number = inst_num;

		left = shared_ptr<Node>(lhs);
		right = shared_ptr<Node>(rhs);
	}

	void print() const {
		if(instruction_number != -1) {
			cout << instruction_number << " ";
		} else {
			cout << "~ ";
		}
		cout << value << " \t" << label;
		if(left != nullptr) {
			cout << " \t-> (" << left -> value;
			if(right != nullptr) {
				cout << ", " << right -> value;
			}
			cout << ")";
		}
		cout << endl;
	}

	bool operator ==(const Node& rhs) {
		if(instruction_number == rhs.instruction_number &&
			value == rhs.value && label == rhs.label &&
			left == rhs.left && right == rhs.right) {
			return true;
		}
		return false;
	}

	bool pointer_compare(const Node& rhs) {
		// If const int, return false
		if(left != nullptr && is_number(left -> value) && right == nullptr) {
			return false;
		}

		// l == l, r == r
		if(left == rhs.left && right == rhs.right && (left != nullptr && right != nullptr)) {
			return true;
		} 
		// l == r, r == l
		else if(left == rhs.right && right == rhs.left && (left != nullptr && right != nullptr)) {
			return true;
		}
		return false;
	}

};

struct Graph {
	vector<shared_ptr<Node> > nodes; // Should make finding instructions 1,2,3... easier
										// Could use a sorted map instead, but more work
	unordered_map<string, shared_ptr<Node> > name_to_node;

	Graph(const vector<Quad>& block) {
		// Instruction count
		int inst_num = 1;

		// For each instruction
		for(int i = 0; i < block.size(); i++) {
			Quad inst = block[i];
			shared_ptr<Node> lhs = nullptr;
			shared_ptr<Node> rhs = nullptr;

			// If there is a first argument
			if(inst.arg1 != "") {
				// If argument's node has been created
				if(name_to_node.find(inst.arg1) != name_to_node.end()) {
					lhs = name_to_node[inst.arg1];
				} else {
					// Make node
					lhs = shared_ptr<Node>(new Node(inst.arg1));
					// Add node to vector and map
					nodes.push_back(lhs);
					name_to_node[inst.arg1] = lhs;
				}
			}

			// If there is a second argument
			if(inst.arg2 != "") {
				// If argument's node has been created
				if(name_to_node.find(inst.arg2) != name_to_node.end()) {
					rhs = name_to_node[inst.arg2];
				} else {
					// Make node
					rhs = shared_ptr<Node>(new Node(inst.arg2));
					// Add node to vector and map
					nodes.push_back(rhs);
					name_to_node[inst.arg2] = rhs;
				}
			}

			// Generate instruction's node
			shared_ptr<Node> new_node(new Node(inst, lhs, rhs, inst_num));
			nodes.push_back(new_node);
			name_to_node[inst.result] = new_node;
			// Increment instruction count
			inst_num++;
		}
	}

	void print() {
		for(int i = 0; i < nodes.size(); i++) {
			nodes[i] -> print();
		}
		cout << endl;
	}

	vector<Quad> graph_to_block() {
		vector<Quad> block;
		for(auto node : nodes) {
			if(node -> instruction_number != -1) {
				Quad temp;
				temp.op = node -> value;
				temp.result = node -> label;

				if(node -> left != nullptr) {
					if(node -> left -> label == "") {
						temp.arg1 = node -> left -> value;
					} else {
						temp.arg1 = node -> left -> label;
					}
				}
				if(node -> right != nullptr) {
					if(node -> right -> label == "") {
						temp.arg2 = node -> right -> value;
					} else {
						temp.arg2 = node -> right -> label;
					}
				}

				block.push_back(temp);
			}
		}

		return block;
	}

	void constant_folding() {
		// Mark nodes that point to a constant value (ex x = 5)
		vector<shared_ptr<Node> > marked_nodes;

		// Find nodes that point to constants
		for(auto& node : nodes) {
			if(node -> left != nullptr) {
				if(is_number(node -> left -> value) && node -> right == nullptr) {
					marked_nodes.push_back(node);
				} 
				// RHS is array
				else if(node -> value == "[]" && node -> right != nullptr && is_number(node -> right -> value)) {
					marked_nodes.push_back(node);
				}
			}
		}

		// Any node that points to a marked node now points to the constant
		for(auto& node : nodes) {
			// If left exists
			if(node -> left != nullptr) {
				// Go through all marked nodes
				for(auto& marked : marked_nodes) {
					// If node's left branch == marked node
					if(*node -> left == *marked) {
						// Replace with marked_nodes constant value
						node -> left = node -> left -> left;
						break;
					}
				}
			}
			if(node -> right != nullptr) {
				// Go through all marked nodes
				for(auto& marked : marked_nodes) {
					// If node's right branch == marked node
					if(*node -> right == *marked) {
						// Replace with marked_nodes constant value
						node -> right = node -> right -> left;
						break;
					}
				}
			}
		}
	}

	void algebraic_simp() {
		for(auto& node : nodes) {
			// If both branches exist
			if(node -> left != nullptr && node -> right != nullptr) {
				// If the operator is a "+"
				if(node -> value == "+") {
					// If rhs is a 0
					if(node -> right -> value == "0") {
						node -> right = nullptr;
						node -> value = "";
					}

					// If lhs is a 0
					else if(node -> right -> value == "0") {
						node -> left = node -> right;
						node -> right = nullptr;
						node -> value = "";
					}
				}

				// If the operator is a "*"
				if(node -> value == "*") {
					// If rhs is a 1
					if(node -> right -> value == "1") {
						node -> right = nullptr;
						node -> value = "";
					}

					// If lhs is a 1
					else if(node -> left -> value == "1") {
						node -> left = node -> right;
						node -> right = nullptr;
						node -> value = "";
					}
				}
			}
		}
	}

	void common_subexpression_elimination() {
		for(int i = 0; i < nodes.size(); i++) {

			for(int j = i + 1; j < nodes.size(); j++) {
				// If we encounter someone else with our same variable name, break
				if(nodes[i] -> label == nodes[j] -> label) {
					break;
				}
				// If they have the same left and right edges
				if(nodes[i] -> pointer_compare(*nodes[j])) {
					nodes[j] -> left = nodes[i];
					nodes[j] -> right = nullptr;
					nodes[j] -> value = "";
				}
			}
		}
	}

	void dead_code() {
		vector<shared_ptr<Node> > new_nodes;
		for(int i = 0; i < nodes.size(); i++) {
			// If temprary variable with no uses and no right edge, don't add to node list
			if(nodes[i] -> label.size() > 1 && nodes[i] -> label[0] == 't'
				&& nodes[i] -> right == nullptr && nodes[i].use_count() <= 2) {
				continue;
			}

			new_nodes.push_back(nodes[i]);
		}
		swap(new_nodes, this -> nodes);
	}
};

// Took from stackoverflow
bool is_number(const std::string& s)
{
    return !s.empty() && std::find_if(s.begin(), 
        s.end(), [](char c) { return !std::isdigit(c); }) == s.end();
}

#endif