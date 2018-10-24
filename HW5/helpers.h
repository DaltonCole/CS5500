// Dalton Cole

#ifndef HELPER_H
#define HELPER_H

#include "quad.h"
#include "graph.h"
#include <map>
#include <algorithm>
using namespace std;

vector<vector<Quad> > make_blocks(const vector<Quad>& instructions);
void print_blocks(const vector<vector<Quad> >& blocks);
void optimize_blocks(vector<vector<Quad> >& blocks);
bool check_equality(const vector<Quad>& x, const vector<Quad>& y);
vector<Quad> optimize_block(vector<Quad>& block);
void constant_folding(vector<Quad>& block);


vector<vector<Quad> > make_blocks(const vector<Quad>& instructions) {
	// List of blocks
	vector<vector<Quad> > blocks;
	// Block of instructions being developed 
	vector<Quad> current_block;

	for(int i = 0; i < instructions.size(); i++) {
		// If next inst is a label, end last block
		if(instructions[i].op == ":") {
			blocks.push_back(current_block);
			current_block.clear();
		}

		// Add instruction to curr_blocks
		current_block.push_back(instructions[i]);

		if(instructions[i].op == "goto" || instructions[i].op == "if_goto") {
			blocks.push_back(current_block);
			current_block.clear();
		}
	}
	blocks.push_back(current_block);

	return blocks;
}

void print_blocks(const vector<vector<Quad> >& blocks) {
	int count = 0;

	for(int i = 0; i < blocks.size(); i++) {
		for(int j = 0; j < blocks[i].size(); j++) {
			cout << "(" << count << ") ";
			blocks[i][j].print();
			count++;
		}
	}
}

void optimize_blocks(vector<vector<Quad> >& blocks) {
	// For each block
	for(int i = 0; i < blocks.size(); i++) {
		vector<Quad> pre_opti;
		vector<Quad> post_opti = blocks[i];
		// Do until pre and post are equal
		do {
			swap(pre_opti, post_opti);
			post_opti = optimize_block(pre_opti);
		} while(!check_equality(pre_opti, post_opti));
		blocks[i] = post_opti;
	}
}

bool check_equality(const vector<Quad>& x, const vector<Quad>& y) {
	if(x.size() != y.size()) {
		return false;
	}

	for(int i = 0; i < x.size(); i++) {
		if(x[i] != y[i]) {
			return false;
		}
	}

	return true;
}

vector<Quad> optimize_block(vector<Quad>& block) {
	// --- Make graph --- //
	Graph g(block);

	// Optimize
	g.constant_folding();
	g.algebraic_simp();
	g.common_subexpression_elimination();
	g.dead_code();

	return g.graph_to_block();
}

#endif