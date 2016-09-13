#pragma once
#include"list_ADT.h"
#include <string>
#include <iostream>
#define  DefualtListSize  1024
using namespace std;
/**************************************************************
|			*Created-time: 2016-9-13
|			*Created-by: ACJ
|			*Description: Doubly-linked list 
**************************************************************/
template <typename Elem> // Doubly-linked list link node
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


template <typename Elem> //Doubly Linked List
class LList /*: public List<Elem> */{
private:
	int m_length;                  //Actual elem count
	int m_leftLength;            //Actual elem count
	Link<Elem>* fence;	   //Position of fence
	Link<Elem>* head;    //Point to list header
	Link<Elem>* tail;       //Point to last Elem
	string errInfo;            //error information
public:
	LList();
	LList(LList<Elem>&);
	~LList();
	void clear();
	bool setPos(int pos);

	bool append(const Elem&);
	bool insert(const Elem&);
	bool pop(Elem&);
	bool remove(Elem&);
	bool getValue(Elem&);

	void setStart();
	void setEnd();
	bool prev();
	bool next();
	int leftLength() const;
	int length() const;
	void print() const;
	void showErr() const;

	LList<Elem>& operator =(const LList<Elem>&);
	template <typename Elem>
	friend ostream & operator <<(ostream &output, const LList<Elem>&);
};

template<typename Elem>
inline LList<Elem>::LList() {
	fence = tail = head = new Link<Elem>;
	m_length = m_leftLength = 0;
	errInfo = "";
}

template<typename Elem>
LList<Elem>::LList(LList<Elem> &LList2) {
	m_length = LList2.m_length;
	m_leftLength = LList2.m_leftLength;
	errInfo = LList2.errInfo;
	fence = tail = head = new Link<Elem>;
	for (Link<Elem>* temp = LList2.head->next; temp !=NULL ; temp = temp->next) {
		this->append(temp->element);
	}
	setPos(m_leftLength);
}


template<typename Elem>
inline LList<Elem>::~LList() {
	this->clear();
	delete head;
	fence = tail = head = NULL;
}

template<typename Elem>
inline void LList<Elem>::clear() {
	Link<Elem>*  temp;
	fence = head->next;
	while (fence != NULL) {
		temp = fence;
		fence = fence->next;
		delete temp;
	}
	tail = fence = head;
	m_leftLength = m_length = 0;
	head->next = NULL;
}

template<typename Elem>
bool LList<Elem>::setPos(int pos) {
	if (pos<0 || pos >m_length) {
		errInfo = "cann't setPos to a wrong position!";
		return false;
	}
	fence = head;
	for (int i = 0; i < pos; i++) {
		fence = fence->next;
	}
	m_leftLength = pos;
	return true;
}

template<typename Elem>
bool LList<Elem>::append(const Elem & item) {
	tail = tail->next = new Link<Elem>(item, tail, NULL);
	m_length++;
	return true;
}

template<typename Elem>
bool LList<Elem>::insert(const Elem & item) {
	if (fence == tail) {
		append(item);
		return true;
	}
	fence->next = new Link<Elem>(item, fence, fence->next);
	fence->next->next->prev = fence->next;
	m_length++;
	return true;
}

template<typename Elem>
bool LList<Elem>::pop(Elem &item){
	if (m_length == 0){
		errInfo = "can't pop : empty list!";
		return false;
	}
	if (fence == tail) {
		fence = fence->prev;
		m_leftLength--;
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
bool LList<Elem>::remove(Elem & item) {
	if (fence == tail) {
		errInfo = "cann't remove: fence is at the end of the list!";
		return false;
	}
	if (fence->next == tail) {
		return pop(item);
	}
	Link<Elem>* temp = fence->next;
	item = temp ->element;
	fence->next = fence->next->next;
	fence->next->prev = fence;
	delete temp;
	m_length--;
	return true;
}

template<typename Elem>
bool LList<Elem>::getValue(Elem &item) {
	if (fence == tail) {
		errInfo = "cann't getValue: fence is at the end of the list!";
		return false;
	}
	item = fence->next->element;
	return true;
}

template<typename Elem>
inline void LList<Elem>::setStart() {
	fence = head;
	m_leftLength = 0;
}

template<typename Elem>
inline void LList<Elem>::setEnd() {
	fence = tail;
	m_leftLength = m_length;
}

template<typename Elem>
bool LList<Elem>::prev() {
	if (fence == head) {
		errInfo = "cann't prev(): fence is at the first of the list!";
		return false;
	}
	fence = fence->prev;
	m_leftLength--;
	return true;
}

template<typename Elem>
bool LList<Elem>::next() {
	if (fence == tail) {
		errInfo = "cann't next(): fence is at the end of the list!";
		return false;
	}
	fence = fence->next;
	m_leftLength++;
	return true;
}

template<typename Elem>
inline int LList<Elem>::leftLength() const {
	return m_leftLength;
}

template<typename Elem>
inline int LList<Elem>::length() const {
	return m_length;
}

template<typename Elem>
void LList<Elem>::print() const {
	cout << *this << endl;
}

template<typename Elem>
inline void LList<Elem>::showErr() const {
	cout << errInfo << endl;
}

template<typename Elem>
LList<Elem>& LList<Elem>::operator=(const LList<Elem>& LList2) {
	this->clear();
	m_length = LList2.m_length;
	m_leftLength = LList2.m_leftLength;
	errInfo = LList2.errInfo;
	for (Link<Elem>* temp = LList2.head->next; temp != NULL; temp = temp->next) {
		this->append(temp->element);
	}
	setPos(m_leftLength);
	return *this; 
}

template<typename Elem>
ostream & operator<<(ostream & output, const LList<Elem>& LList1)
{
	cout << '[';
	Link<Elem>* iterator = LList1.head;
	if (LList1.fence == iterator) {
		cout << " @ ";
	}
	if (LList1.m_length == 0) {
		cout << ']';
		return output;
	}
	iterator = iterator->next;
	cout << iterator->element;
	if (LList1.fence == iterator) {
		cout << "  @";
	}

	while (iterator = iterator->next) {
		cout << ", " << iterator->element;
		if (LList1.fence == iterator) {
			cout << "  @";
		}
	}
	cout << ']';
	return output;
}
