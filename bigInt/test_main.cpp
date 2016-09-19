#include<iostream>
#include<string>
#include"big_int.h"

using namespace std;

int main() {
	BigInt temp("123456789");
	cout << temp << endl;
	cout << temp[0] << endl;

	BigInt temp2 = temp;
	cout << temp2 << endl;

	BigInt temp3 = ("324124214214");
	cout << temp3 << endl;
	
	temp2 = temp3;
	cout << temp2 << endl;
	cout << "---------------------------------------------------" << endl;

	BigInt* p1 = new BigInt("99");
	BigInt* p2 = new BigInt("88");
	cout << p1->length() << "  " << *p1 << endl;
	cout << p2->length() << "  " << *p2 << endl;

	cout << (*p1 + *p2).length() << "  " << *p1 + *p2 << endl;
	cout << (*p1 *  *p2).length() << "  " << *p1 * *p2 << endl;
	delete p1;
	delete p2;

	return 0;
}
