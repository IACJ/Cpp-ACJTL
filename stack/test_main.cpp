#include<iostream>
#include<string>
#include "AStack.h"
#include "LStack.h"
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
	delete p1;
	p1 = NULL;
	cout << "----------------------AStack test2 ends------------------" << endl;


	cout << "----------------------LStack test1 begins------------------" << endl;
	LStack<int> temp2;
	temp2.print();
	temp2.push(1);
	temp2.push(2);
	temp2.push(3);
	temp2.push(4);
	cout << temp2 << endl;
	AInt = 0;
	temp2.pop(AInt);
	cout << AInt << endl;
	cout << temp2 << endl;
	cout << temp2.length() << endl;
	cout << temp2.topValue(AInt) << endl;
	cout << AInt << endl;
	cout << "----------------------LStack test1 ends------------------" << endl;

	cout << "----------------------LStack test2 begins------------------" << endl;
	LStack<string> * p2 = new LStack<string>;
	cout << *p2 << endl;
	p2->push("aa");
	p2->push("bb");
	p2->push("cc");
	p2->push("dd");
	p2->push("ee");
	cout << *p2 << endl;
	if (!p2->push("ff")) {
		p2->showErr();
	}
	cout << *p2 << endl;
	cout << p2->length() << endl;
	p2->clear();
	cout << *p2 << endl;
	cout << p2->length() << endl;
	AString = "";
	if (!p2->topValue(AString)) {
		p2->showErr();
	}
	if (!p2->pop(AString)) {
		p2->showErr();
	}
	delete p2;
	p2 = NULL;
	cout << "----------------------LStack test2 ends------------------" << endl;
		
};
