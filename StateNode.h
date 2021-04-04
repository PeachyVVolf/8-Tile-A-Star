#pragma once
#include "States.h"
using namespace std;


class StateNode {
public:
	states* current;
	StateNode* parent;
	int g = 0;
	int h = 0;


	StateNode() { //default constructor
		current = new states();
		parent = NULL;
	}

	StateNode(states other) { //copy constructor
		current = new states(other);
		parent = NULL;
	}

};