#include <iostream>
#include <string>
#include "2_3_Tree.h"
using namespace std;

int main() {


	cout << "test begins---------------------" << endl;
	
	TT_tree<KV_pair>* temp = new TT_tree<KV_pair>();

	temp->print();
	cout << endl;


	temp->insert(KV_pair(12, 12));
	temp->print();
	cout << endl;

	temp->insert(KV_pair(18, 18));
	temp->print();
	cout << endl;

	temp->insert(KV_pair(23, 23));
	temp->print();
	cout << endl;

	temp->insert( KV_pair(33, 33) );
	temp->print();
	cout << endl;

	temp->insert( KV_pair(48, 48));
	temp->print();
	cout << endl;

	temp->insert(KV_pair(56, 56));
	temp->print();
	cout << endl;

	temp->insert(KV_pair(49, 49));
	temp->print();
	cout << endl;

	temp->insert(KV_pair(1,1));
	temp->print();
	cout << endl;

	temp->insert(KV_pair(5, 5));
	temp->print();
	cout << endl;

	temp->insert(KV_pair(2, 2));
	temp->print();
	cout << endl;

	temp->insert(KV_pair(4, 4));
	temp->print();
	cout << endl;

	temp->preOrder();

	KV_pair* p =NULL;

	cout << temp->find(3,p) << endl;
	if (p != NULL) {
		cout << p->getKey() << ' '<< p->getVal() << endl;
	}
	else {
		cout << "NULL" << endl;
	}

	cout << temp->find(2, p) << endl;
	if (p != NULL) {
		cout << p->getKey() << ' ' << p->getVal() << endl;
	}
	else {
		cout << "NULL" << endl;
	}

	cout << temp->find(1, p) << endl;
	if (p != NULL) {
		cout << p->getKey() << ' ' << p->getVal() << endl;
	}
	else {
		cout << "NULL" << endl;
	}

	cout << temp->find(99, p) << endl;
	if (p != NULL) {
		cout << p->getKey() << ' ' << p->getVal() << endl;
	}
	else {
		cout << "NULL" << endl;
	}

	return 0;
}