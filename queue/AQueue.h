#pragma once
#include"queue_ADT.h"
#include <string>
#include <iostream>
#define  DefualtSize  1024
using namespace std;
/**************************************************************
|			*Created-time: 2016-9-23
|			*Created-by: ACJ
|			*Description: Array-based queue
**************************************************************/
template <typename Elem> //Array-based queue
class AQueue : public Queue<Elem> {
private:
	int maxSize;           //Maximum Size of queue
	int front;                 // Index of front element
	int rear;                  // Index of rear element
	Elem* queueArray;     //Array hoding queue
	string errInfo;       //error information
public:
	AQueue(int size = DefualtSize);
	~AQueue();
	void clear();

	bool enqueue(const Elem&);
	bool dequeue(Elem&);
	bool frontValue(Elem&);

	int length() const;
	void print() const;
	void showErr() const;

	template <typename Elem>
	friend ostream & operator <<(ostream &output, const AQueue<Elem>&);
};

template<typename Elem>
inline AQueue<Elem>::AQueue(int size = DefualtSize) {
	maxSize = size;
	queueArray = new Elem[maxSize];
	front = rear = 0;
	errInfo = "";
}

template<typename Elem>
inline AQueue<Elem>::~AQueue() {
	delete[] queueArray;
	queueArray = NULL;
}

template<typename Elem>
inline void AQueue<Elem>::clear() {
	front = rear = 0;
}

template<typename Elem>
bool AQueue<Elem>::enqueue(const Elem & item) {
	if ((rear +1 )% maxSize == front ) {
		errInfo = "cann't enqueue: Queue is full!";
		return false;
	}
	queueArray[rear] = item;
	rear = (rear + 1) % maxSize;
	return true;
}

template<typename Elem>
bool AQueue<Elem>::dequeue(Elem & item) {
	if (rear == front) {
		errInfo = "cann't dequeue: Queue is empty!";
		return false;
	}
	item = queueArray[front];
	front = (front + 1) % maxSize; 
	return true;
}

template<typename Elem>
bool AQueue<Elem>::frontValue(Elem &item) {
	if (rear == front) {
		errInfo = "cann't frontValue: Queue is empty!";
		return false;
	}
	item = queueArray[front];
	return true;
}



template<typename Elem>
inline int AQueue<Elem>::length() const {
	return ((rear + maxSize) - front ) % maxSize;
}

template<typename Elem>
void AQueue<Elem>::print() const {
	cout << *this << endl;
}

template<typename Elem>
inline void AQueue<Elem>::showErr() const {
	cout << errInfo << endl;
}

template<typename Elem>
ostream & operator<<(ostream & output, const AQueue<Elem>& AQueue1)
{
	cout << '[';
	int i = 0;

	if (AQueue1.length() == 0) {
		cout << ']';
		return output;
	}
	cout << AQueue1.queueArray[AQueue1.front];
	for (i = AQueue1.front +1; i != AQueue1.rear ; i = (i+1) % AQueue1.maxSize ) {
		cout << ',';
		cout << "  " << AQueue1.queueArray[i];
	}
	cout << ']';
	return output;
}