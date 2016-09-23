#include <iostream>
#include "AQueue.h"
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

}