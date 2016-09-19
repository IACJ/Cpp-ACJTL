#pragma once
#include <string>
#include <iostream>
using namespace std;
/**************************************************************
|			*Created-time: 2016-9-18
|			*Created-by: ACJ
|			*Description: BigInt
**************************************************************/

class BigInt  {
private:  
	int * arr;
	int m_length;
public:
	BigInt(const string = "0");
	BigInt(const BigInt&);
	BigInt(const int* ,int length);
	~BigInt();
	BigInt& operator =(const BigInt&);
	const int& operator [](int k);
	friend ostream & operator <<(ostream &output, const BigInt&);
	const int length() const;

	friend BigInt operator +(const BigInt&, const BigInt&);
	friend BigInt operator *(const BigInt&, const BigInt&);
private:
	bool init(string);
	void init(const BigInt&);
};