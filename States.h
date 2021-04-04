#include <cstdlib> 
#include <iostream>
#include <stdlib.h>
#include <fstream>
using namespace std;
#pragma once

class states {

public:
	int array[3][3];
	int emptySpacei = 0;
	int emptySpacej = 0;

	//constructor reads Initial State from file
	states() {
		ifstream fin("Initial State.txt");
		if (fin.is_open()) {
			char buff[8];
			char otherBuff[2];
			int i = 0, j = 0, m = 0;
			while (!fin.eof()) {
				fin.getline(buff, 8);
				j = 0;
				m = 0;
				for (int k = 0; k < 8; k++) {
					if (buff[k] != ',' && buff[k] != ' ' && buff[k] != '\0') {
						otherBuff[m] = buff[k];
						m++;
					}
					else {
						if (i < 3 && j < 3) {
							array[i][j] = atoi(otherBuff);
							if (array[i][j] == -1) {
								emptySpacei = i;
								emptySpacej = j;

							}
							otherBuff[0] = '\0';
							otherBuff[1] = '\0';
							m = 0;
							j++;
						}
					}
				}
				i++;
			}
			fin.close();
		}
		else {
			cout << "Couldn't Open File to Retrieve Initial State. Terminating!!" << endl;
			exit(EXIT_FAILURE);
		}

	};

	states(const states& other) {
		emptySpacei = other.emptySpacei;
		emptySpacej = other.emptySpacej;

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++)
			{
				array[i][j] = other.array[i][j];
			}
		}
	}

	void print() {
		//cout << emptySpacei << " " << emptySpacej << endl;

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				cout << array[i][j] << " ";
			}
			cout << endl;
		}
	}

};
