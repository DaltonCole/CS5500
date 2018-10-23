#ifndef QUAD_H
#define QUAD_H

#include <string>
#include <iostream>
using namespace std;

struct Quad {
	string op;
	string arg1;
	string arg2;
	string result;

	static int temp;
	static int label;

	void print() const {
		if(op == "" || op == "+" || op == "*" ||
			op == ">" || op == "<" || op == "<=" ||
			op == ">=" || op == "!=" || op == "==") {
			cout << result << " = " << arg1 << " " << op << " " << arg2; 
		} else if(op == "[]") { // Print array
			cout << result[0] << "[" << arg1 << "] = " << arg2;
		} else if(op == "rhs[]") { // Print rhs array
			cout << result << " = " << arg1[0] << "[" << arg2 << "]";
		} else if(op == ":") { // Label
			cout << result << ":";
		} else if(op == "if_goto") { // if goto
			cout << "if " << arg1 << " == false goto " << result;
		} else if(op == "goto") {
			cout << "goto " << result;
		}


		cout << endl;

		return;
	}

	void clear() {
		op = arg1 = arg2 = result = "";
		return;
	}

	void add_arg(const char a) {
		if(arg1 == "") {
			arg1 = a;
		} else {
			arg2 = a;
		}
	}

	void add_arg(string a) {
		if(arg1 == "") {
			arg1 = a;
		} else {
			arg2 = a;
		}
	}

	void add_arg(const char* a) {
		if(arg1 == "") {
			arg1 = string(a);
		} else {
			arg2 = string(a);
		}
	}

	void add_arg(int i) {
		if(arg1 == "") {
			arg1 = to_string(i);
		} else {
			arg2 = to_string(i);
		}
	}

	void remove_arg() {
		if(arg2 != "") {
			arg2 = "";
		} else {
			arg1 = "";
		}
	}

	void add_temp_result() {
		result = "t" + to_string(temp);
		temp++;
	}

	void add_label_result() {
		result = "L" + to_string(label);
		label++;
		op = ":";
	}

	char* get_temp_result() {
		return (char*)result.c_str();
	}

	/*
	void str_to_int(string var) {

	}
	*/
};

int Quad::temp = 1;
int Quad::label = 1;

#endif