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
	openList[openIndex] = ToPush;
	openIndex++;

	calculateGH(ToPush, parent);
}

bool AStarPuzzle::searchInClosed(StateNode* ToFind)
{
	bool check = false;
	
	for (int i = 0; i < closeIndex; i++) {
		StateNode* something = closeList[i];

		for (int firstIndex = 0; firstIndex < 3; firstIndex++) {
			for (int secondIndex = 0; secondIndex < 3; secondIndex++) {
				if (something->current->array[firstIndex][secondIndex] == ToFind->current->array[firstIndex][secondIndex]) {
					check = true;
				}
				else {
					check = false;
					break;
				}
			}
			if (check == false) {
				break;
			}
		}
		if (check == true) {
			return true;
		}
	}
	return false;
}

void AStarPuzzle::MoveBlankToLeft(StateNode* root)
{
	int indexI = root->current->emptySpacei;
	int indexJ = root->current->emptySpacej;

	StateNode* newNode = new StateNode(*root);

	int emptySpace = newNode->current->array[indexI][indexJ];
	int number = newNode->current->array[indexI][indexJ - 1];

	newNode->current->array[indexI][indexJ - 1] = emptySpace;
	newNode->current->array[indexI][indexJ] = number;

	newNode->current->emptySpacej -= 1;

	newNode->parent = root;

	pushInOpen(newNode, root);
}

void AStarPuzzle::MoveBlankToRight(StateNode* root)
{
	int indexI = root->current->emptySpacei;
	int indexJ = root->current->emptySpacej;

	StateNode* newNode = new StateNode(*root);

	int emptySpace = newNode->current->array[indexI][indexJ];
	int number = newNode->current->array[indexI][indexJ + 1];

	newNode->current->array[indexI][indexJ + 1] = emptySpace;
	newNode->current->array[indexI][indexJ] = number;

	newNode->current->emptySpacej += 1;

	newNode->parent = root;

	pushInOpen(newNode, root);
}

void AStarPuzzle::MoveBlankToUp(StateNode* root)
{
	int indexI = root->current->emptySpacei;
	int indexJ = root->current->emptySpacej;

	StateNode* newNode = new StateNode(*root);

	int emptySpace = newNode->current->array[indexI][indexJ];
	int number = newNode->current->array[indexI - 1][indexJ];

	newNode->current->array[indexI - 1][indexJ] = emptySpace;
	newNode->current->array[indexI][indexJ] = number;

	newNode->current->emptySpacei -= 1;

	newNode->parent = root;

	pushInOpen(newNode, root);
}

void AStarPuzzle::MoveBlankToDown(StateNode* root)
{
	int indexI = root->current->emptySpacei;
	int indexJ = root->current->emptySpacej;

	StateNode* newNode = new StateNode(*root);

	int emptySpace = newNode->current->array[indexI][indexJ];
	int number = newNode->current->array[indexI + 1][indexJ];

	newNode->current->array[indexI + 1][indexJ] = emptySpace;
	newNode->current->array[indexI][indexJ] = number;

	newNode->current->emptySpacei += 1;

	newNode->parent = root;

	pushInOpen(newNode, root);
}

void AStarPuzzle::popAndExplore(int indexToPop)
{
	if (!openList == NULL) {
		StateNode* some = openList[indexToPop];

		if (!searchInClosed(some)) {
			if (some->current->emptySpacej > 0) //move left
			{
				MoveBlankToLeft(some);
			}
			if (some->current->emptySpacej < 2) { //move right
				MoveBlankToRight(some);
			}
			if (some->current->emptySpacei > 0) { //move Up
				MoveBlankToUp(some);
			}
			if (some->current->emptySpacei < 2) { //Move Down
				MoveBlankToDown(some);
			}


			openList[indexToPop] = NULL;
			closeList[closeIndex] = some;
			closeIndex++;

			StateNode* min = NULL;
			int minIndex = 0;
			for (int i = 0; i < openIndex; i++) {
				if (openList[i]->h <= some->h) {
					if (min != NULL && min->h <= openList[i]->h) {
						min = openList[i];
						minIndex = i;
					}
				}
			}

			popAndExplore(i);
		}
	}

}

bool AStarPuzzle::isFinal(StateNode* ToCheck)
{
	bool check = false;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (ToCheck->current->array[i][j] == FinalState->current->array[i][j]) {
				check = true;
			}
			else {
				check = false;
				return check;
			}
		}
	}
	return check;
}
