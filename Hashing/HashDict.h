#pragma once
#include <string>
#include <iostream>
#include <assert.h>
using namespace std;


template<typename Key, typename E>
class KVpair {
public:
	Key first;
	E second;

	KVpair() {}

	KVpair(const Key& key, const E& e){
		this->first = key;
		this->second = e;
	}

	Key& key() {
		return this->first;
	}

	E& value() {
		return this->second;
	}

	void setKey(const Key& key) {
		this->first = key;
	}
};


template<typename Key, typename E>
class HashDict {
private:
	KVpair<Key, E>* HT;  //The hash table
	int M;		//Size of HT
	int currCnt;		//The current number of elements in HT
	Key EMPTYKEY;	//User-supplied key value for an empty slot

	int p(Key K, int i) const {
		return i;
	}

	int h(int x) const {
		return x % M;
	}

	int h(char* x) const {
		int i, sum;
		for (sum = 0, i = 0; x[i] != '/0'; i++) {
			sum = (sum + (int)x[i]) % M;
		}
		return sum;
	}

	void hashInsert(const Key&, const E&);
	E hashSearch(const Key&) const;

public:
	HashDict(int sz, Key k) {
		this->M = sz;
		this->EMPTYKEY = k;
		this->HT = new KVpair<Key, E>[sz];
		for (int i = 0; i < M; i++) {
			HT[i].setKey(EMPTYKEY);
		}
	}

	~HashDict() {
		delete[] HT;  //¿´Êé
	}

	//Find some record with key value "K"
	E find(const Key& k) const {
		return hashSearch(k);
	}
	int size() {
		return currCnt;		//number stored in table
	}

	//Insert element "it" with Key "K" into the dictionary.
	void insert(const Key& k, const E& it) {
		assert(currCnt < M, "Hash table is full");
		hashInsert(k, it);
		currCnt++;
	}
};

template<typename Key, typename E>
 void HashDict<Key, E>::hashInsert(const Key & k, const E & e){
	 int home;
	 h(k);
	 int pos = home = 0;
	 for (int i = 1; EMPTYKEY != (HT[pos]).key(); i++) {
		 pos = (home + p(k, i)) % M;
		 assert(k != HT[pos].key(), "Duplicates not allowed");
	 }
	 KVpair<Key, E> temp(k, e);
	 HT[pos] = temp;
}

 template<typename Key, typename E>
E HashDict<Key, E>::hashSearch(const Key & k) const{
	int home;
	int pos = home = h(k);
	for (int i = 1; k != HT[pos].key() && EMPTYKEY != HT[pos].key(); i++) {
		pos = (home + p(k, i)) % M;
	}
	if (k == HT[pos].key()) {
		return HT[pos].value();
	}
	else {
		return E();
	}
 }
