#pragma once
#include "StateNode.h"
#include <list>
using namespace std;

#define totalSize  1000

class AStarPuzzle {

	StateNode* root;
	StateNode* FinalState;
	list <StateNode*> openList[totalSize];
	list <StateNode*> closeList[totalSize];

	int openIndex = 0;
	int closeIndex = 0;

	AStarPuzzle() {
		root = new StateNode();
		makeFinalState();
		pushInOpen(root, NULL);
	}

private:
	void makeFinalState();
	void calculateGH (StateNode* ToPush, StateNode* parent);
	void pushInOpen(StateNode* ToPush, StateNode* parent);
	bool searchInClosed(StateNode* ToFind);
	void popAndExplore();
};