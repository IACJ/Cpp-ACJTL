#include <iostream>
#include <string>
#include "HashDict.h"
using namespace std;


int main() {
	cout << "hashing test begins--------------" << endl;
	HashDict<int,string> a(10,-1);

	a.insert(100,"hahah");

	cout << a.find(20) << endl;
	cout << a.find(50) << endl;
	cout << a.find(100) << endl;
	cout << a.find(200) << endl;
}