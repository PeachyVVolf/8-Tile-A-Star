#include "AStarPuzzle.h"

void AStarPuzzle::makeFinalState()
{
	FinalState->current->array[0][0] = 1;
	FinalState->current->array[0][1] = 2;
	FinalState->current->array[0][2] = 3;
	FinalState->current->array[1][0] = 4;
	FinalState->current->array[1][1] = -1;
	FinalState->current->array[1][2] = 5;
	FinalState->current->array[2][0] = 6;
	FinalState->current->array[2][1] = 7;
	FinalState->current->array[2][2] = 8;

	FinalState->current->emptySpacei = 1;
	FinalState->current->emptySpacej = 1;

	FinalState->h = 0;
	FinalState->g = 0;

	FinalState->parent = NULL;
}

void AStarPuzzle::calculateGH(StateNode* ToPush, StateNode* parent)
{
	int parentG = 0;
	if (parent != NULL) {
		parentG = parent->g;
	}

	ToPush->g += 1;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (ToPush->current->array[i][j] != FinalState->current->array[i][j]) {
				ToPush->h++;
			}
		}
	}
}

void AStarPuzzle::pushInOpen(StateNode* ToPush, StateNode* parent)
{
	openList->push_back(ToPush);
	openIndex++;

	calculateGH(ToPush, parent);
}

bool AStarPuzzle::searchInClosed(StateNode* ToFind)
{
	//ToFind->current->array[firstIndex][secondIndex] == 

	list<StateNode*>::iterator it;
	
	for (it = closeList->begin(); it!=closeList->end(); it++) {
		StateNode something = it;

		for (int firstIndex = 0; firstIndex < 3; firstIndex++) {
			for (int secondIndex = 0; secondIndex < 3; secondIndex++) {
				if (it == ToFind) {

				}
			}
		}
	}
}

void AStarPuzzle::popAndExplore()
{
	if (!openList->empty()) {
		StateNode* some = openList->front();
		openList->pop_front();
		openIndex--;
		

	}

}
