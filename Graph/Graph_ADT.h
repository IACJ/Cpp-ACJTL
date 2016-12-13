#pragma once

//This ADT assumes that the number of vertices is fixed

class Graph {
private:
	void operator = (const Graph&) {}
	Graph(const Graph&) {}
public:
	Graph() {}
	virtual ~Graph(){}

	//Initialize a graph of n vertices
	virtual void Init(int n) = 0;

	//@Return: the number of vertices and edges
	virtual int n() const= 0;
	virtual int e() const= 0;

	//@Return: v's first neighbor
	virtual int first(int v) = 0;

	//@Return: v's next neighbor
	virtual int next(int v, int w) = 0;

	//set the weight for an edge
	virtual void addEdge(int v1, int v2, int wght) = 0;

	//delete an edge
	virtual void delEdge(int v1, int v2) = 0;

	
	//Get and Set the mark value for a vertex
	virtual int getMark(int v) = 0;
	virtual void setMark(int v, int val) = 0;

};
