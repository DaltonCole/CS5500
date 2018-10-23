#ifndef HELPER_H
#define HELPER_H

#include "quad.h"
#include "graph.h"
#include <map>

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
		cout << endl;
	}
}

void optimize_blocks(vector<vector<Quad> >& blocks) {
	for(int i = 0; i < blocks.size(); i++) {
		vector<Quad> pre_opti;
		vector<Quad> post_opti = blocks[i];
		do {
			pre_opti = post_opti; // Could use move if this is slow
			post_opti = optimize_block(blocks[i]);
		} while(pre_opti != post_opti);
		blocks[i] = post_opti;
	}
}

vector<Quad> optimize_block(vector<Quad>& block) {
	// --- Make graph --- //
	map<

}

void constant_folding(vector<Quad>& block) {

}

#endif