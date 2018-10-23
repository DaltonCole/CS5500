#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include "quad.h"

struct Node {
	int instruction_number;
	string value;
	string label;

	Node(const Quad& q) {
		value = q.op;
		label = q.result;
	}

	Node(const Quad& q, const int& num) {
		value = q.op;
		label = q.result;
		instruction_number = num;
	}
};

struct Graph {
	vector<vector<bool> > matrix;
	vector<Node> points;

	Graph() {
		matrix = vector<vector<bool> > (1000, vector<bool>(1000, false));
	}

	bool has_edge(int i, int j) {
		return matrix[i][j];
	}

	void make_edge(int i, int j) {
		matrix[i][j] = true;
	}
};

struct Node {
	
}

struct Graph {
	vector<Node> nodes;

	Graph(const vector<Quad>& block) {

	}
}

#endif