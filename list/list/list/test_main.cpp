#include<iostream>
#include <string>
#include"AList.h"
using namespace std;

int main() {
	cout << "---------AList Test1 begins--------" << endl;
	// test the copy-construct, a list of list, append, remove 
	AList<int>* p1 = new AList<int>;
	p1->append(2);
	p1->append(0);
	p1->append(4);
	p1->append(8);
	AList<int>* p2 = new AList<int>(*p1);
	cout << "p1 is ";    p1->print();
	cout << "p2 is " << *p2 << endl;
	AList<int>* p3 = new AList<int>;
	cout << "p3 is " << *p3 << endl;
	*p3 = *p2;
	p3->insert(100);
	cout << "p2 is " << *p2 << endl;
	cout << "p3 is " << *p3 << endl;
	AList<AList<int>>* p4 = new AList<AList<int>>;
	cout << "p4 is " << *p4 << endl;
	p4->append(*p1);
	cout << "p4 is " << *p4 << endl;
	p4->append(*p2);
	cout << "p4 is " << *p4 << endl;
	p4->append(*p3);
	cout << "p4 is " << *p4 << endl;
	p4->setPos(1);
	cout << "p4 is " << *p4 << endl;
	AList<int>* p5 = new AList<int>;
	p4->remove(*p5);
	cout << "p4 is " << *p4 << endl;
	cout << "the removed item is " << *p5 << endl;
	cout << "--------AList Test1 ends---------" << endl << endl << endl;

	cout << "---------AList Test2 begins--------" << endl;
	//test error-information when moving the fence to a wrong position
	AList<char>*q = new AList<char>;
	q->print();
	char Achar;
	if (!q->getValue(Achar)) {
		q->showErr();
	}
	q->append('A');
	q->append('B');
	q->append('C');
	q->setEnd();
	q->print();
	if (!q->next()) {
		q->showErr();
	}
	if (!q->remove(Achar)) {
		q->showErr();
	}
	if (!q->getValue(Achar)) {
		q->showErr();
	}
	q->insert('N');
	q->print();
	q->next();
	q->print();
	q->setStart();
	q->print();
	if (!q->prev()) {
		q->showErr();
	}
	delete q;
	q = NULL;
	cout << "--------AList Test2 ends---------" << endl << endl << endl;

	cout << "---------AList Test3 begins--------" << endl;
	//test operator function <<  []  = ,when there is a list of a list
	// operator []  will throw a Exception when receiving a wrong argument
	AList<int> foo;
	foo.append(1997);
	foo.append(4);
	foo.append(22);
	cout << foo << endl;
	foo[1] = 3;
	cout << foo << endl;
	foo[2] = 16;
	cout << foo << endl;
	try {
		foo[3] = 100;
	}catch(string Exception){
		cout << Exception << endl;
	}
	AList<int> bar;
	cout << "bar is "<< bar << endl;
	AList<AList<int>> foobar;
	cout << "foobar is " << foobar << endl;
	foobar.append(bar);
	cout << "foobar is " << foobar << endl;
	foobar.append(bar);
	cout << "foobar is " << foobar << endl;
	foobar[0] = foo;
	cout << "foobar is " << foobar << endl;
	cout << "--------AList Test3 ends---------" << endl << endl << endl;
	
	cout << "---------AList Test4 begins--------" << endl;
	//normal test
	AList<int> temp(4);
	temp.append(1);
	temp.print();
	temp.append(2);
	temp.print();
	temp.append(3);
	temp.print();
	temp.append(4);
	temp.print();
	if (!temp.append(5)) {
		temp.showErr();
	}
	temp.print();
	if (!temp.insert(6)) {
		temp.showErr();
	}
	temp.print();
	int aInt;
	temp.remove(aInt);
	cout << aInt << " was removed." << endl;
	temp.print();
	if (!temp.insert(7)) {
		temp.showErr();
	}
	temp.print();
	cout << "--------AList Test4 ends---------" << endl << endl << endl;

	cout << "---------AList Test5 begins--------" << endl;
	//normal test
	AList<string>*p = new AList<string>;
	p->append("dog");
	p->append("cat");
	p->append("pig");
	p->print();
	p->setPos(2);
	p->insert("bird");
	p->print();
	p->insert("fly");
	p->print();
	string aString;
	p->remove(aString);
	cout << aString << " was removed." << endl;
	p->print();
	cout << "leftLength is " << p->leftLength() << endl;
	cout << "Length is " << p->length() << endl;
	p->getValue(aString);
	cout << "the value of fence is " << aString << endl;
	p->clear();
	p->print();
	if (!p->setPos(20)) {
		p->showErr();
	}
	delete p;
	p = NULL;
	cout << "--------AList Test5 ends---------" << endl << endl << endl;


	system("pause");
	return 0;
}