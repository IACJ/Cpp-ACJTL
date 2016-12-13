#include <iostream>
#include "Graph_matrix.h"
#include "Graph_list.h"
using namespace std;

int main() {
	cout << "test begins ---------------------" << endl;
	Graph_matrix g(8);
	g.addEdge(1, 5, 3);
	cout << g.getEdge(1, 5) << endl;
	cout << g.getEdge(2, 5) << endl;

	g.showMatrix();

	cout << "test2 begins ---------------------" << endl;

	Graph_list g2(9);
	g2.addEdge(2, 5, 3);
	g2.showLists();
	cout << g2.getEdge(1, 5).getVert() << endl;
	cout << g2.getEdge(2, 5).getVert() << endl;

}