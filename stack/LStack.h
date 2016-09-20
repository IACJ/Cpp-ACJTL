#pragma once
#include"stack_ADT.h"
#include <string>
#include <iostream>
#define  DefualtSize  1024
using namespace std;
/**************************************************************
|			*Created-time: 2016-9-21
|			*Created-by: ACJ
|			*Description: Doubly-linked stack
**************************************************************/
template <typename Elem> // Doubly-linked stack link node
class Link {
public:
	Elem element;  // Value for this node
	Link *next;    // Pointer to next node 
	Link *prev;    // Pointer to previous node
	Link(const Elem& e, Link* prevp = NULL, Link* nextp = NULL) {
		element = e;  prev = prevp;  next = nextp;
	}
	Link(Link* prevp = NULL, Link* nextp = NULL) {
		prev = prevp;  next = nextp;
	}
};

template <typename Elem> //Doubly - linked stack
class LStack : public Stack<Elem> {
private:
	int m_length;                  //Actual elem count
	Link<Elem>* head;    //Point to stack header
	Link<Elem>* tail;       //Point to last Elem
	string errInfo;       //error information
public:
	LStack();
	~LStack();

	void clear();
	bool push(const Elem&);
	bool pop(Elem&);
	bool topValue(Elem&);
	int length() const;

	void print() const;
	void showErr() const;

	template <typename Elem>
	friend ostream & operator <<(ostream &output, const LStack<Elem>&);
};

template<typename Elem>
inline LStack<Elem>::LStack() {
	tail = head = new Link<Elem>;
	m_length =  0;
	errInfo = "";
}

template<typename Elem>
inline LStack<Elem>::~LStack() {
	this->clear();
	delete head;
	tail = head = NULL;
}

template<typename Elem>
void LStack<Elem>::clear() {
	Link<Elem>*  temp;
	tail = head->next;
	while (tail != NULL) {
		temp = tail;
		tail = tail->next;
		delete temp;
	}
	tail = head;
	m_length = 0;
	errInfo = "";
	head->next = NULL;
}

template<typename Elem>
bool LStack<Elem>::push(const Elem & item) {
	tail = tail->next = new Link<Elem>(item, tail, NULL);
	m_length++;
	return true;
}

template<typename Elem>
bool LStack<Elem>::pop(Elem &item) {
	if (m_length == 0) {
		errInfo = "can't pop : empty Stack!";
		return false;
	}
	Link<Elem>* temp = tail;
	item = temp->element;
	tail = tail->prev;
	tail->next = NULL;
	delete temp;
	m_length--;
	return true;
}

template<typename Elem>
bool LStack<Elem>::topValue(Elem &item) {
	if (m_length == 0) {
		errInfo = "cann't get topValue: empty Stack!";
		return false;
	}
	item = tail->element;
	return true;
}

template<typename Elem>
inline int LStack<Elem>::length() const {
	return m_length;
}

template<typename Elem>
void LStack<Elem>::print() const {
	cout << *this << endl;
}

template<typename Elem>
inline void LStack<Elem>::showErr() const {
	cout << errInfo << endl;
}

template<typename Elem>
ostream & operator<<(ostream & output, const LStack<Elem>& LStack1)
{
	cout << '[';
	Link<Elem>* iterator = LStack1.head;

	if (LStack1.m_length == 0) {
		cout << ']';
		return output;
	}
	iterator = iterator->next;
	cout << iterator->element;

	while (iterator = iterator->next) {
		cout << ", " << iterator->element;
	}
	cout << ']';
	return output;
}
