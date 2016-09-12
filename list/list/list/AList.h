#pragma once
#include"list_ADT.h"
#include <string>
#include <iostream>
#define  DefualtListSize  1024
using namespace std;
/**************************************************************
|			*Created-time: 2016-9-9                                            
|			*Created-by: ACJ                                                        
|			*escription: Array-based list                                       
 *************************************************************/
template <typename Elem> //Array-based list
class AList : public List<Elem> {
private:
	int maxSize;           //Maximum Size of list
	int listSize;             //Actual elem count
	int fence;	              //Position of fence
	Elem* listArray;     //Array hoding list
	string errInfo;       //error information
public:
	AList(int size= DefualtListSize);
	AList(AList<Elem>&);
	~AList();
	void clear();
	bool setPos(int pos);
	bool insert(const Elem&);
	bool append(const Elem&);
	bool remove(Elem&);
	bool getValue(Elem&);

	void setStart();
	void setEnd();
	bool prev();
	bool next();
	int leftLength() const;
	int length() const;
	void print() const;
	void showErr() const;
	
	AList<Elem>& operator =(const AList<Elem>&);
	Elem& operator [](int k);
	template <typename Elem>
	friend ostream & operator <<(ostream &output, const AList<Elem>&);
};

template<typename Elem>
inline AList<Elem>::AList(int size = DefualtListSize){
	maxSize = size;
	listSize = fence = 0;
	listArray = new Elem[maxSize];
}

template<typename Elem>
inline AList<Elem>::AList(AList<Elem> &AList2){
	maxSize = AList2.maxSize;
	listSize = AList2.listSize;
	fence = AList2.fence;
	listArray = new Elem[maxSize];
	for (int i = 0; i < listSize; i++) {
		listArray[i] = AList2.listArray[i];
	}
}

template<typename Elem>
inline AList<Elem>::~AList(){
	delete[] listArray;
	listArray = NULL;
}

template<typename Elem>
inline void AList<Elem>::clear(){
	listSize = fence = 0;
}

template<typename Elem>
bool AList<Elem>::setPos(int pos){
	if (pos<0 || pos >listSize) {
		errInfo = "cann't setPos to a wrong position!";
		return false;
	}
	fence = pos;
	return true;
}

template<typename Elem>
bool AList<Elem>::insert(const Elem & item){
	if (listSize == maxSize){
		errInfo = " cann't insert: list is full!";
		return false;
	}
	for (int i = listSize; i > fence; i--) {
		listArray[i] = listArray[i - 1];
	}
	listArray[fence] = item;
	listSize++;
	return true;
}

template<typename Elem>
bool AList<Elem>::append(const Elem & item){
	if (listSize == maxSize) {
		 errInfo = "cann't append: list is full!";
		 return false;
	 }
	 listArray[listSize] = item;
	 listSize++;
	 return true;
}

template<typename Elem>
bool AList<Elem>::remove(Elem & item ){
	if (fence == listSize) {
		errInfo = "cann't remove: fence is at the end of the list!";
		return false;
	}
	item = listArray[fence];
	for (int i = fence; i < listSize-1 ; i++){
		listArray[i] = listArray[i + 1];
	}
	listSize--;
	return true;
 }

template<typename Elem>
bool AList<Elem>::getValue(Elem &item) {
	if (fence == listSize) {
		errInfo = "cann't getValue: fence is at the end of the list!";
		return false;
	}
	item = listArray[fence];
	return true;
}

template<typename Elem>
inline void AList<Elem>::setStart(){
	fence = 0;
}

template<typename Elem>
inline void AList<Elem>::setEnd(){
	fence = listSize;
}

template<typename Elem>
bool AList<Elem>::prev(){
	if (fence == 0) {
		errInfo = "cann't prev(): fence is at the first of the list!";
		return false;
	}
	fence--;
	return true;
}

template<typename Elem>
bool AList<Elem>::next(){
	if (fence == listSize) {
		errInfo = "cann't next(): fence is at the end of the list!";
		return false;
	}
	fence++;
	return true;
}

template<typename Elem>
inline int AList<Elem>::leftLength() const{
	return fence;
}

template<typename Elem>
inline int AList<Elem>::length() const{
	return listSize;
}

template<typename Elem>
void AList<Elem>::print() const{
	cout << *this<< endl;
}

template<typename Elem>
inline void AList<Elem>::showErr() const{
	cout << errInfo << endl;
}

template<typename Elem>
AList<Elem>& AList<Elem>::operator=(const AList<Elem>& AList2){
	delete[] listArray;
	maxSize = AList2.maxSize;
	listSize = AList2.listSize;
	fence = AList2.fence;
	listArray = new Elem[maxSize];
	for (int i = 0; i < listSize; i++) {
		listArray[i] = AList2.listArray[i];
	}
	return *this;
}

template<typename Elem>
Elem & AList<Elem>::operator[](int k){
	if (k < 0 || k >= listSize) {
		errInfo = "Excepetion: operator[] with a wrong position!";
		throw errInfo;
	}
	return listArray[k];
}

template<typename Elem>
ostream & operator<<(ostream & output, const AList<Elem>& AList1)
{
	cout << '[';
	int i = 0;
	if (AList1.fence == i) {
		cout << '@';
	}
	if (AList1.listSize == 0) {
		cout << ']';
		return output;
	}
	cout << AList1.listArray[i];
	for (i = 1; i < AList1.listSize; i++) {
		cout << ',';
		if (AList1.fence == i) {
			cout << '@';
		}
		cout << "  " << AList1.listArray[i];
	}
	if (AList1.fence == i) {
		cout << '@';
	}
	cout << ']';
	return output;
}