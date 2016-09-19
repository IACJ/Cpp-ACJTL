#include "big_int.h"

int max(int x, int y) {
	return x > y ? x : y;
}


BigInt::BigInt(const string astring){
	if (!init(astring)) {
		throw (string)"Err: cann't string_to_BigInt!";
	}
}

BigInt::BigInt(const BigInt & BigInt2){
	init(BigInt2);
}

BigInt::BigInt(const int *arr2, int length){
	m_length =length;
	arr = new int[m_length * 99];
	for (int i = 0; i < m_length; i++) {
		arr[i] =arr2[i];
	}
}

BigInt::~BigInt(){
	delete arr;
	arr = NULL;
}

BigInt & BigInt::operator=(const BigInt &BigInt2){
	delete arr;
	init(BigInt2);
	return *this;
}

const int & BigInt::operator[](int k) {
	return arr[k];
}

const int BigInt::length() const
{
	return m_length;
}

bool BigInt::init(string astring){
	if (astring.size() == 0) {
		return false;
	}
	arr = new int[astring.size() * 99];
	m_length = astring.size();

	for ( int i = astring.size() - 1; i >=0 ; i--) {
		if (astring[i] <= '9' && astring[i] >= '0') {
			arr[m_length - 1 - i] = astring[i] - '0';
		}else{
			return false;
		}
	}
	return true;
}

void BigInt::init(const BigInt& BigInt2){
	m_length = BigInt2.m_length;
	arr = new int[m_length * 99];
	for (int i = 0; i < m_length; i++) {
		arr[i] = BigInt2.arr[i];
	}
}

ostream & operator<<(ostream & output, const BigInt & BigInt1) {
	for (int i = BigInt1.m_length - 1; i >= 0; i--) {
		output << BigInt1.arr[i];
	}
	return output;
}

BigInt operator+(const BigInt & BigInt1, const BigInt &BigInt2){

	int bigger = max(BigInt1.m_length, BigInt2.m_length);
	int * arr2 = new int[bigger * 99 + 1];

	for (int i = 0; i <= bigger; i++) {
		arr2[i] = 0;
	}
	//cout << "init" << bigger << ',' << arr2[bigger] << endl;
	for (int i = 0; i < bigger; i++) {
		if (i < BigInt1.length()) {
			arr2[i] += BigInt1.arr[i];
		}
		if (i < BigInt2.length()) {
			arr2[i] += BigInt2.arr[i];
		}	
		arr2[i + 1] += arr2[i] / 10;
		arr2[i] %= 10;
	}
	//cout <<"before "<< bigger << ','<<arr2[bigger]<< endl;
	if (arr2[bigger] != 0) {
		bigger++;
	}
	//cout <<"after " << bigger << endl << endl;
	return BigInt(arr2, bigger);
}

BigInt operator*(const BigInt &BigInt1, const BigInt &BigInt2){
	int bigger = BigInt1.m_length + BigInt2.m_length -1;
	int * arr2 = new int[bigger +100];

	for (int i = 0; i <= bigger; i++) {
		arr2[i] = 0;
	}


	for (int i = 0; i < BigInt1.m_length; i++){
		for (int j = 0; j < BigInt2.m_length; j++){
			arr2[i + j] += BigInt1.arr[i] * BigInt2.arr[j];
		}
	}
	for (int i = 0; i < bigger; i++) {
		arr2[i + 1] += arr2[i] / 10;
		arr2[i] %= 10;
	}

	if (arr2[bigger] != 0) {
		bigger++;
	}
	return BigInt(arr2, bigger);
}
