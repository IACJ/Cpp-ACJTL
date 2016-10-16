#include<iostream>
using namespace std;
#include "binary_tree.h"

int main() {
	cout << "--------------------------binary test begins--------------------------" << endl;
	LBinaryTree<int>* aTree = new LBinaryTree<int>;
	aTree->root->it = 8;
	aTree->root->lc= new BinaryNode<int>(4);
	aTree->root->rc= new BinaryNode<int>(6);
	aTree->root->rc->rc = new BinaryNode<int>(2);
	aTree->root->rc->lc = new BinaryNode<int>(1);
	aTree->root->rc->lc->rc = new BinaryNode<int>(9);
	/* the tree is:
												8
											  /    \
											4      6
											 	  /  \ 
												1     2
												 \
												   9
	*/
	cout << "preorder :";
	aTree->preorder(aTree->root);
	cout << endl;
	cout << "inorder :";
	aTree->inorder(aTree->root);
	cout << endl;
	cout << "postorder :";
	aTree->postorder(aTree->root);
	cout << endl<<endl;
	
	cout << "Ï°Ìâ5.7-levelorder :";
	aTree->leveloder();
	cout << endl;

	cout << "Ï°Ìâ5.8-height : " << aTree->height(aTree->root) << endl;
	cout << "Ï°Ìâ5.9-count : " << aTree->count(aTree->root) << endl;
}