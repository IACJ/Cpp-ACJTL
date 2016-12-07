#pragma once
#include <list>
using namespace std;
#define EMPTY_KEY -1

class KV_pair {
private:
	int key;
	int val;

public:
	KV_pair(int key = EMPTY_KEY, int val = 0) {
		this->key = key;
		this->val = val;
	}

	KV_pair(const KV_pair& a) {
		this->key = a.key;
		this->val = a.val;
	}

	int getKey() const{
		return key;
	}

	int getVal() const{
		return val;
	}
};

// class Elem needs a Deeply-Copy-Function
template<typename Elem>
class TT_node {   //Two-Tree-treeNode
public:
	Elem* leftE;
	Elem* rightE;

	TT_node* leftP;
	TT_node* centerP;
	TT_node* rightP;

	TT_node() {
		leftP = centerP = rightP = NULL;
		leftE = rightE = NULL;
	}

	TT_node(Elem& left, Elem& right,
		TT_node*lp = NULL, TT_node*cp = NULL, TT_node*rp = NULL) {

		leftE = new Elem(left);
		rightE = new Elem(right);

		leftP = lp;
		centerP = cp;
		rightP = rp;
	}

	TT_node(Elem& left) {

		leftE = new Elem(left);
		rightE = NULL;
		leftP = centerP = rightP = NULL;

	}

	bool isLeaf() {
		return leftP == NULL;
	}

};


// class Elem needs a Deeply-Copy-Construct-Function
template<typename Elem>
class TT_tree {   //Two-Tree-tree
private:
	TT_node<Elem>* root;

public:
	TT_tree() {
		root = NULL;
	}

	void insert(const Elem& e) {

		Elem* my_e = new Elem(e);


		Elem* my_retv;
		TT_node<Elem>* my_retp = NULL;

		insert_help(root, my_e, my_retv, my_retp);

		if (my_retp == NULL) {
			return;
		}
		// my_retp !=NULL
		TT_node<Elem>*  new_root = new TT_node<Elem>();
		new_root->leftE = my_retv;
		new_root->leftP = root;
		new_root->centerP = my_retp;
		root = new_root;
	}

	bool find(const int& K, Elem*& e) {
		return find_help(root, K, e);
	}

	void print() {
		if (root == NULL) {
			cout << "{NULL}" << endl;
			return;
		}

		list<TT_node<Elem>*> q;
		q.push_front(root);
		TT_node<Elem>* p = NULL;
		while (!q.empty()){
			p = q.front();
			q.pop_front();
			cout << "--------------------------------" << endl;
			if (p->rightE != NULL) {
				cout << "[ " << p->leftE->getKey() << ":" << p->leftE->getVal() << " , "
					<< p->rightE->getKey() << ":" << p->rightE->getVal() << " ]" << endl;
			}else {
				cout << "[ " << p->leftE->getKey() << ":" << p->leftE->getVal() << " , "
					<< " NULL "<< " ]" << endl;
			}

			if (p->leftP != NULL) {
				q.push_back(p->leftP);
				cout << "enqueue : Son1--"<<p->leftP->leftE->getKey();
			}
			if (p->centerP != NULL) {
				q.push_back(p->centerP);
				cout << ", Son2--" << p->centerP->leftE->getKey();
			}
			if (p->rightP != NULL) {
				q.push_back(p->rightP);
				cout << ", Son3--" << p->rightP->leftE->getKey();;
			}
			cout << endl;
		}
		cout << "================================" << endl;
	}

	void preOrder() {
		preOrder_help(root);
	}

private:
	bool find_help(const TT_node<Elem>* subroot, const int& K, Elem*& e) {
		if (subroot == NULL) {
			return false;
		}

		if (K == subroot->leftE->getKey()) {
			e = subroot->leftE;
			return true;
		}

		if (subroot->rightE != NULL && K == subroot->rightE->getKey()) {
			e = subroot->rightE;
			return true;
		}

		if (K < subroot->leftE->getKey()) {
			return find_help(subroot->leftP, K, e);
		}


		if (subroot->rightE == NULL || K < subroot->rightE->getKey()) {
			return find_help(subroot->centerP, K, e);
		}

		return find_help(subroot->rightP, K, e);
	}

	void insert_help(TT_node<Elem>*& subroot,
		Elem* e, Elem*& retVal, TT_node<Elem>*& retP) {

		if (subroot == NULL) {
			subroot = new TT_node<Elem>( *(new Elem(*e)) );     //why did i write it like this...
			return;
		}

		Elem* my_retv = NULL;
		TT_node<Elem>* my_retp = NULL;

		if (subroot->isLeaf()) {
			if (subroot->rightE == NULL) {  //Easy case :not full
				if (subroot->leftE->getKey() < e->getKey()) {
					subroot->rightE = e;
				}
				else {
					subroot->rightE = subroot->leftE;
					subroot->leftE = e;
				}
			}
			else {
				splitnode(subroot, e, NULL, retVal, retP);
			}
		}
		else if (e->getKey() < subroot->leftE->getKey()) {  //insert_help ::left subtree
			insert_help(subroot->leftP, e, my_retv, my_retp);
		}
		else if (subroot->rightE == NULL || e->getKey() < subroot->rightE->getKey()) { //insert_help ::center subtree
			insert_help(subroot->centerP, e, my_retv, my_retp);
		}
		else {  //insert_help ::right subtree
			insert_help(subroot->rightP, e, my_retv, my_retp);
		}

		if (my_retp == NULL) {
			return;
		}

		// my_retp !=NULL
		if (subroot->rightE != NULL) {			//full
			splitnode(subroot, my_retv, my_retp, retVal, retP);
		}
		else {  //Not full:add to this node
			if (my_retv->getKey() < subroot->leftE->getKey()) {  // add to the left
				subroot->rightE = subroot->leftE;
				subroot->leftE = my_retv;

				subroot->rightP = subroot->centerP;
				subroot->centerP = my_retp;
			}
			else {   // add to the right
				subroot->rightE = my_retv;

				subroot->rightP = my_retp;
			}
		}

	}

	// As it's name
	void splitnode(TT_node<Elem>* subroot,  Elem* inVal,TT_node<Elem>*inPtr,
		Elem*& retVal, TT_node<Elem>*& retPtr) {

		retPtr = new TT_node<Elem>();
		if (inVal->getKey() < subroot->leftE->getKey()) { //Add at left

			retVal = subroot->leftE;

			subroot->leftE = inVal;
			retPtr->leftE = subroot->rightE;

			retPtr->leftP = subroot->centerP;
			retPtr->centerP = subroot->rightP;

			subroot->centerP = inPtr;

		}
		else if (inVal->getKey() < subroot->rightE->getKey()) { //Center

			retVal = inVal;

			retPtr->leftE = subroot->rightE;

			retPtr->leftP = inPtr;
			retPtr->centerP = subroot->rightP;
		}
		else {										//Add at right

			retVal = subroot->rightE;

			retPtr->leftE = inVal;

			retPtr->leftP = subroot->rightP;
			retPtr->centerP = inPtr;
		}
		subroot->rightE = NULL;
		subroot->rightP = NULL;
	}

	void preOrder_help(TT_node<Elem>* subroot) {
		if (subroot == NULL) {
			return;
		}

		if (subroot->rightE != NULL) {
			cout << "[ " << subroot->leftE->getKey() << ":" << subroot->leftE->getVal() << " , "
				<< subroot->rightE->getKey() << ":" << subroot->rightE->getVal() << " ]" << endl;
		}
		else {
			cout << "[ " << subroot->leftE->getKey() << ":" << subroot->leftE->getVal() << " , "
				<< " NULL " << " ]" << endl;
		}

		preOrder_help(subroot->leftP);
		preOrder_help(subroot->centerP);
		preOrder_help(subroot->rightP);
	}



};

