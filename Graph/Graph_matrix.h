#pragma once
#include <iostream>
#include <vector>
#include "Graph_ADT.h"
using namespace std;

#define NOT_FIND_int -1;

class Graph_matrix :public Graph {
private:
	int numVertex;
	int numEdge;
	vector< vector<int>> matrix;
	vector<int> mark;

public:
	Graph_matrix(int numVert) {
		Init(numVert);
	}

	//Get info
	int n() const {
		return numVertex;
	}
	int e() const {
		return numEdge;
	}
	void showMatrix() const {
		for (int i = 0; i < matrix.size(); i++) {
			for (int j = 0; j < matrix[i].size(); j++) {
				cout << matrix[i][j] << ' ';
			}
			cout << endl;
		}
	}

	//@Return v's first neighbor 
	int first(int v) {
		for (int i = 0; i < numVertex; i++) {
			if (matrix[v][i] != 0) {
				return i;
			}
		}
		return NOT_FIND_int;
	}

	//@Return v's next neighbor after w
	int next(int v, int w) {
		for (int i = w + 1; i < numVertex; i++) {
			if (matrix[v][i] != 0) {
				return i;
			}
		}
		return NOT_FIND_int;
	}

	//Opration of Edges
	void addEdge(int v1, int v2, int wt) {
		if (matrix[v1][v2] == 0) {
			numEdge++;
		}
		matrix[v1][v2] = wt;
	}
	void delEdge(int v1, int v2) {
		if (matrix[v1][v2] != 0) {
			numEdge--;
		}
		matrix[v1][v2] = 0;
	}
	int getEdge(int v1, int v2) {
		return matrix[v1][v2];
	}

	//Opration of marks
	void initMark(int flag= 0) {
		mark.clear();
		mark.insert(mark.begin(), numVertex, flag);
	}
	void setMark(int v,int flag) {
		mark[v] = flag;
	}
	int getMark(int v) {
		return mark[v];
	}

private:
	void Init(int n) {
		numVertex = n;
		numEdge = 0;

		mark.insert(mark.begin(), n, 0);
		matrix.insert(matrix.begin(), n, vector<int>(n, 0));
	}

};