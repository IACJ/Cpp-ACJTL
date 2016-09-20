#pragma once
#include"stack_ADT.h"
#include <string>
#include <iostream>
#define  DefualtSize  1024
using namespace std;
/**************************************************************
|			*Created-time: 2016-9-20
|			*Created-by: ACJ
|			*Description: Array-based stack
**************************************************************/
template <typename Elem> // Array-based stack
class AStack : public Stack<Elem> {
private:
	int maxSize;           //Maximum Size of stack
	int top;                  // The position to insert the new element
	Elem* stackArray;  //Array hoding stack
	string errInfo;       //error information
public:
	AStack(int size = DefualtSize);
	~AStack();

	void clear();
	bool push(const Elem&);
	bool pop(Elem&);
	bool topValue(Elem&);
	int length() const;

	void print() const;
	void showErr() const;

	template <typename Elem>
	friend ostream & operator <<(ostream &output, const AStack<Elem>&);
};

template<typename Elem>
inline AStack<Elem>::AStack(int size = DefualtSize) {
	maxSize = size;
	top = 0;
	stackArray = new Elem[maxSize];
}


template<typename Elem>
inline AStack<Elem>::~AStack() {
	delete[] stackArray;
	stackArray = NULL;
}

template<typename Elem>
inline void AStack<Elem>::clear() {
	top = 0;
	errInfo = "";
}

template<typename Elem>
bool AStack<Elem>::push(const Elem & item) {
	if (top == maxSize) {
		errInfo = "cann't push: stack is full!";
		return false;
	}
	stackArray[top++] = item;
	return true;
}

template<typename Elem>
bool AStack<Elem>::pop(Elem & item) {
	if (top == 0) {
		errInfo = "cann't pop: stack is empty!";
		return false;
	}
	item = stackArray[--top];
	return true;
}

template<typename Elem>
bool AStack<Elem>::topValue(Elem & item) {
	if (top == 0) {
		errInfo = "cann't get topValue: stack is empty!";
		return false;
	}
	item = stackArray[top - 1];
	return true;
}

template<typename Elem>
inline int AStack<Elem>::length() const {
	return top;
}

template<typename Elem>
void AStack<Elem>::print() const {
	cout << *this << endl;
}

template<typename Elem>
inline void AStack<Elem>::showErr() const {
	cout << errInfo << endl;
}


template<typename Elem>
ostream & operator<<(ostream & output, const AStack<Elem>& AStack1)
{
	cout << '[';
	int i = 0;

	if (AStack1.top == 0) {
		cout << ']';
		return output;
	}
	cout << AStack1.stackArray[i];
	for (i = 1; i < AStack1.top; i++) {
		cout << ',';

		cout << "  " << AStack1.stackArray[i];
	}

	cout << ']';
	return output;
}