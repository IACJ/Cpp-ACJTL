#pragma once
#include"queue_ADT.h"
#include <string>
#include <iostream>

using namespace std;
/**************************************************************
|			*Created-time: 2016-9-23
|			*Created-by: ACJ
|			*Description: Doubly-linked queue
**************************************************************/
template <typename Elem> // Doubly-linked  node
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

template <typename Elem> //Doubly-linked queue
class LQueue : public Queue<Elem> {
private:
	int m_length;                  //Actual elem count
	Link<Elem>* head;    //Point to  header
	Link<Elem>* tail;       //Point to last Elem
	string errInfo;       //error information
public:
	LQueue();
	~LQueue();
	void clear();

	bool enqueue(const Elem&);
	bool dequeue(Elem&);
	bool frontValue(Elem&);

	int length() const;
	void print() const;
	void showErr() const;

	template <typename Elem>
	friend ostream & operator <<(ostream &output, const LQueue<Elem>&);
};

template<typename Elem>
LQueue<Elem>::LQueue(){
	head = tail  = new Link<Elem>;
	m_length = 0;
	errInfo = "";
}

template<typename Elem>
LQueue<Elem>::~LQueue(){
	this->clear();
	delete head;
	tail = head = NULL;
}

template<typename Elem>
void LQueue<Elem>::clear() {
	Link<Elem>*  temp;
	tail = head->next;
	while (tail != NULL) {
		temp = tail;
		tail = tail->next;
		delete temp;
	}
	tail = head;
	m_length = 0;
	head->next = NULL;
}

template<typename Elem>
bool LQueue<Elem>::enqueue(const Elem & item) {
	tail = tail->next = new Link<Elem>(item, tail, NULL);
	m_length++;
	return true;
}



template<typename Elem>
bool LQueue<Elem>::dequeue(Elem & item) {
	if (m_length == 0) {
		errInfo = "cann't dequeue: empty Queue!";
		return false;
	}
	if (head->next == tail) {
		item = tail->element;
		delete tail;
		tail = head;
		head->next = NULL;
		m_length--;
		return true;
	}
	Link<Elem>* temp = head->next;
	item = temp->element;
	head->next = head->next->next;
	head->next->prev = head;
	delete temp;
	m_length--;
	return true;
}

template<typename Elem>
bool LQueue<Elem>::frontValue(Elem & item){
	if (m_length == 0) {
		errInfo = "cann't get frontValue: empty Queue!";
		return false;
	}
	item = head->next->element;
	return true;
}

template<typename Elem>
inline int LQueue<Elem>::length() const {
	return m_length;
}

template<typename Elem>
inline void LQueue<Elem>::print() const {
	cout << *this << endl;
}

template<typename Elem>
inline void LQueue<Elem>::showErr() const {
	cout << errInfo << endl;
}

template<typename Elem>
ostream & operator<<(ostream & output, const LQueue<Elem>& LQueue1)
{
	cout << '[';
	Link<Elem>* iterator = LQueue1.head;

	if (LQueue1.m_length == 0) {
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