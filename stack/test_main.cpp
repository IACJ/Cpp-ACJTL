#include<iostream>
#include<string>
#include "AStack.h"
using namespace std;
int main() {
	cout << "----------------------AStack test1 begins------------------" << endl;
	AStack<int> temp;
	temp.print();
	temp.push(1);
	temp.push(2);
	temp.push(3);
	temp.push(4);
	cout << temp << endl;
	int AInt = 0;
	temp.pop(AInt);
	cout << AInt << endl;
	cout << temp << endl;
	cout << temp.length() << endl;
	cout << temp.topValue(AInt) << endl;
	cout << AInt << endl;
	cout << "----------------------AStack test1 ends------------------" << endl;

	cout << "----------------------AStack test2 begins------------------" << endl;
	AStack<string> * p1 = new AStack<string>(5);
	cout << *p1 << endl;
	p1->push("aa");
	p1->push("bb");
	p1->push("cc");
	p1->push("dd");
	p1->push("ee");
	cout << *p1 << endl;
	if (!p1->push("ff")) {
		p1->showErr();
	}
	cout << *p1 << endl;
	cout << p1->length() << endl;
	p1->clear();
	cout << *p1 << endl;
	cout << p1->length() << endl;
	string AString;
	if (!p1->topValue(AString)) {
		p1->showErr();
	}
	if (!p1->pop(AString)) {
		p1->showErr();
	}
	cout << "----------------------AStack test2 ends------------------" << endl;
		
};
