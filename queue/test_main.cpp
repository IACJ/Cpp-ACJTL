#include <iostream>
#include "AQueue.h"
#include "LQueue.h"
using namespace std;
int main() {
	cout << "-------------------AQueue test1 begins-------------" << endl;
	AQueue<int> temp1;
	temp1.print();
	temp1.enqueue(1);
	cout << temp1 << endl;
	temp1.enqueue(2);
	temp1.enqueue(3);
	temp1.enqueue(4);
	temp1.enqueue(5);
	cout << temp1 << endl;
	int AInt;
	temp1.dequeue(AInt);
	temp1.dequeue(AInt);
	cout << AInt << endl;
	cout << temp1 << endl;
	cout << temp1.length() << endl;
	temp1.clear();
	cout << temp1 << endl;
	cout << temp1.length() << endl;
	if (!temp1.dequeue(AInt)) {
		temp1.showErr();
	}
	if (!temp1.frontValue(AInt)) {
		temp1.showErr();
	}
	cout << "-------------------AQueue test1 ends-------------" << endl;

	cout << "-------------------AQueue test2 begins-------------" << endl;
	AQueue<string>* p1 = new AQueue<string>;
	cout << *p1 << endl;
	p1->enqueue("foo");
	p1->enqueue("bar");
	cout << *p1 << endl;
	string	AString;
	p1->frontValue(AString);
	cout << AString << endl;
	cout << *p1 << endl;
	cout << p1->dequeue(AString) << endl;
	cout << p1->dequeue(AString) << endl;
	cout << p1->dequeue(AString) << endl;
	cout << p1->dequeue(AString) << endl;
	p1->showErr();
	cout << p1->length() << endl;
	p1->print();
	delete p1;
	cout << "-------------------AQueue test2 ends-------------" << endl;


	cout << "-------------------LQueue test1 begins-------------" << endl;
	LQueue<int> temp2;
	temp2.print();
	temp2.enqueue(1);
	cout << temp2 << endl;
	temp2.enqueue(2);
	temp2.enqueue(3);
	temp2.enqueue(4);
	temp2.enqueue(5);
	cout << temp2 << endl;
	AInt = 0;
	temp2.dequeue(AInt);
	temp2.dequeue(AInt);
	cout << AInt << endl;
	cout << temp2 << endl;
	cout << temp2.length() << endl;
	temp2.clear();
	cout << temp2 << endl;
	cout << temp2.length() << endl;
	if (!temp2.dequeue(AInt)) {
		temp2.showErr();
	}
	if (!temp2.frontValue(AInt)) {
		temp2.showErr();
	}
	cout << "-------------------LQueue test1 ends-------------" << endl;

	cout << "-------------------LQueue test2 begins-------------" << endl;
	AQueue<string>* p2 = new AQueue<string>;
	cout << *p2 << endl;
	p2->enqueue("foo");
	p2->enqueue("bar");
	cout << *p2 << endl;
	AString = "";
	p2->frontValue(AString);
	cout << AString << endl;
	cout << *p2 << endl;
	cout << p2->dequeue(AString) << endl;
	cout << p2->dequeue(AString) << endl;
	cout << p2->dequeue(AString) << endl;
	cout << p2->dequeue(AString) << endl;
	p2->showErr();
	cout << p2->length() << endl;
	p2->print();
	delete p2;
	cout << "-------------------LQueue test2 ends-------------" << endl;
}