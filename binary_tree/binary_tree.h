#pragma once
#include<iostream>
#include<algorithm>
using namespace std;

//data structure    value-height
template <typename Elem>
class Value_Level {
public:
	Elem value;
	int level;
	static int i;
	static Value_Level<Elem>* list;
public:
	static int compare(Value_Level<Elem> e1, Value_Level<Elem> e2) {
		return e1.level < e2.level;
	}
};
int Value_Level<int>::i = 0;
Value_Level<int>* Value_Level<int>::list;

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
	void leveloder_help(BinaryNode<Elem>* subroot,int level);
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
	int n = count(root);
	Value_Level<Elem>::list = new Value_Level<Elem>[n];
	Value_Level<Elem>::i = 0;
	leveloder_help(root,0);
	stable_sort(Value_Level<Elem>::list, Value_Level<Elem>::list +n,Value_Level<Elem>::compare);
	for (int i = 0; i < n; i++){
		cout << Value_Level<Elem>::list[i].value;
		cout << "  ";
	}
	cout << endl;
}

template<typename Elem>
void LBinaryTree<Elem>::leveloder_help(BinaryNode<Elem>* subroot,int level){
	if (subroot == NULL) return;
	Value_Level<Elem>::list[Value_Level<Elem>::i].level = level;
	Value_Level<Elem>::list[Value_Level<Elem>::i].value = subroot->it;
	Value_Level<Elem>::i++;
	leveloder_help(subroot->lc, level + 1);
	leveloder_help(subroot->rc, level + 1);
	return ;
}
