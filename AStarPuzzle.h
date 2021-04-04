#pragma once
#include "StateNode.h"
using namespace std;

#define totalSize  1000

class AStarPuzzle {

	StateNode* root;
	StateNode* FinalState;
	StateNode* openList[totalSize];
	StateNode* closeList[totalSize];

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
	void MoveBlankToLeft(StateNode* root);
	void MoveBlankToRight(StateNode* root);
	void MoveBlankToUp(StateNode* root);
	void MoveBlankToDown(StateNode* root);
	void popAndExplore(int indexToPop);
	bool isFinal(StateNode* ToCheck);
};