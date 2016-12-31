#pragma once
#include<iostream>
#include<algorithm>
#include<list>
using namespace std;



// Binary tree node class
template <typename Elem>
class BinaryNode {
public:
	Elem it;         // The node's value
	BinaryNode* lc;  // Pointer to left child
	BinaryNode* rc;  // Pointer to right child

	BinaryNode() {
		lc = rc = NULL; 
	}
	BinaryNode(Elem e, BinaryNode* l = NULL, BinaryNode* r = NULL) {
		it = e; 
		lc = l;
		rc = r;
	}
	bool isLeaf(){
		return (lc == NULL) && (rc == NULL);
	}
};
//=========================================================
template <typename Elem>
class LBinaryTree {
public:
	BinaryNode<Elem>* root;
public:
	LBinaryTree() {
		root = new BinaryNode<Elem>;
	}

	BinaryNode<Elem>* getRoot() {
		return root;
	}
	void preorder(BinaryNode<Elem>* subroot);
	void inorder(BinaryNode<Elem>* subroot);
	void postorder(BinaryNode<Elem>* subroot);
	void leveloder();

	int count(BinaryNode<Elem>* subroot);
	int height(BinaryNode<Elem>* subroot);
	void visit(BinaryNode<Elem>* subroot) {
		cout << ' ' << subroot->it;
	}
};


template <typename Elem>
void LBinaryTree<Elem>::preorder(BinaryNode<Elem>*subroot) {
	if (subroot == NULL) return;  // Empty
	visit(subroot);  // Perform some action
	preorder(subroot->lc);
	preorder(subroot->rc);
}

template <typename Elem>
void LBinaryTree<Elem>::inorder(BinaryNode<Elem>* subroot) {
	if (subroot == NULL) return;  // Empty
	inorder(subroot->lc);
	visit(subroot);  // Perform some action
	inorder(subroot->rc);
}

template <typename Elem>
void LBinaryTree<Elem>::postorder(BinaryNode<Elem>* subroot) {
	if (subroot == NULL) return;  // Empty
	postorder(subroot->lc);
	postorder(subroot->rc);
	visit(subroot);  // Perform some action
}


// Return the number of nodes in the subtree
template <typename Elem>
int LBinaryTree<Elem>::count(BinaryNode<Elem>* subroot) {
	if (subroot == NULL) {
		return 0;  //  count :0
	}
	return 1 + count(subroot->lc) + count(subroot->rc);
}

template <typename Elem>
int LBinaryTree<Elem>::height(BinaryNode<Elem>* subroot) {
	if (subroot == NULL) {
		return 0;  // height : 0
	}
	return max(1 + height(subroot->lc) ,1 + height(subroot->rc));
}

template<typename Elem>
void LBinaryTree<Elem>::leveloder(){

	list< BinaryNode<Elem>* > queue;

	if (root == NULL) {
		return;   //Empty tree;
	}

	queue.push_back(root);

	while (!queue.empty()){
		BinaryNode<Elem>* subroot = queue.front();
		queue.pop_front();

		visit(subroot);

		if (subroot->lc != NULL) {
			queue.push_back(subroot->lc);
		}
		if (subroot->rc != NULL) {
			queue.push_back(subroot->rc);
		}
	}

	cout << endl;
}


