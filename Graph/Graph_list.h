#pragma once

#include <iostream>
#include <vector>
#include <list>
using namespace std;

#define NOT_FIND_int -1;
#define NOT_FIND_Edge Edge(-1,0);

class Edge {
	int vert, wt;
public:
	Edge() {
		vert = -1;
		wt = 0;
	}
	Edge(int v, int w) {
		vert = v;
		wt = w;
	}
	
	int getVert() {
		return vert;
	}
	int getWt() {
		return wt;
	}
	void setWt(int w) {
		wt = w;
	}
};


class Graph_list  {
private:
	int numVertex;
	int numEdge;
	vector< list<Edge> > lists;
	vector<int> mark;

public:
	Graph_list(int numVert) {
		Init(numVert);
	}

	//Get info
	int n() const {
		return numVertex;
	}
	int e() const {
		return numEdge;
	}
	void showLists()  {    // knowledge: there cann't be a "const" , Or  we can't get the changable "Iterator j"
		cout << "----------------" << endl;
		for (int i = 0; i < lists.size(); i++) {
			for (list<Edge>::iterator j = lists[i].begin(); j !=lists[i].end(); j++) {
				cout <<j->getVert() <<' ' << (*j).getWt() << '\t';
			}
			cout << endl;
		}
		cout << "----------------" << endl;
	}

	//@Return v's first neighbor 
	int first(int v) {
		if (lists[v].size() == 0) {
			return NOT_FIND_int;
		}else {
			return lists[v].front().getVert();
		}
		
	}

	//@Return v's next neighbor after w
	int next(int v, int w) {

		list<Edge>::iterator j = lists[v].begin();

		while (j != lists[v].end() && j->getVert() != w);

		if (j->getVert() == w) {
			j++;
		}

		if (j == lists[v].end()) {
			return NOT_FIND_int;
		}
		else {
			return (*j).getVert();
		}
	}

	bool isConnectTo(int v1, int v2) {

		list<Edge>::iterator j = lists[v1].begin();

		while (j != lists[v1].end() && j->getVert() != v2) {
			j++;
		}

		if (j == lists[v1].end()) {
			return false;
		}else {
			return true;
		}
	}



	//Opration of Edges
	void addEdge(int v1, int v2, int wt) {

		if (!isConnectTo(v1, v2)) {
			numEdge++;
			lists[v1].push_back(Edge(v2, wt));
		}else {

			list<Edge>::iterator j = lists[v1].begin();
			while ((*j).getVert() != v2) {
				j++;
			}
			(*j).setWt(wt);

		}
	}
	void delEdge(int v1, int v2) {
		if (!isConnectTo(v1, v2)) {
			return;
		}
		else {

			list<Edge>::iterator j = lists[v1].begin();
			while ((*j).getVert() != v2) {
				j++;
			}
			lists[v1].erase(j);
		}
	}
	Edge getEdge(int v1, int v2) {
		if (!isConnectTo(v1, v2)) {
			return NOT_FIND_Edge;
		}
		else {

			list<Edge>::iterator j = lists[v1].begin();
			while ((*j).getVert() != v2) {
				j++;
			}
			return (*j);
		}
	}

	//Opration of marks
	void initMark(int flag = 0) {
		mark.clear();
		mark.insert(mark.begin(), numVertex, flag);
	}
	void setMark(int v, int flag) {
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
		lists.insert(lists.begin(), n, list<Edge>() );
	}

};