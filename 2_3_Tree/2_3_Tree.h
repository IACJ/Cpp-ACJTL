
#pragma once


#define EMPTY_KEY -1

class TT_node {   //Two-Tree-treeNode
public:
	int lVal; int lKey;
	int rVal; int rKey;
	TT_node* leftP;
	TT_node* centerP;
	TT_node* rightP;

	TT_node() {
		leftP = centerP = rightP = NULL;
		lKey = rKey = EMPTY_KEY;
	}

	TT_node(int lk, int lv, int rk= EMPTY_KEY, int rv = EMPTY_KEY,
			TT_node*lp = NULL, TT_node*cp = NULL, TT_node*rp = NULL) {

		lKey = lk, lVal = lv;
		rKey = rk, rVal = rv;
		leftP = lp;
		centerP = cp;
		rightP = rp;
	}

	bool isLeaf() {
		return leftP == NULL;
	}

};


class TT_tree {   //Two-Tree-tree
public:

	bool find_help(TT_node* subroot, const int& K, int& e) {
		if (subroot == NULL) {
			return false;
		}

		if (K == subroot->lKey) {
			e = subroot->lVal;
			return true;
		}

		if (subroot->rKey != EMPTY_KEY && K == subroot->rKey) {
			e = subroot->rVal;
			return true;
		}

		if (K < subroot->lKey) {
			return find_help(subroot->leftP, K, e);
		}


		if (subroot->rKey == EMPTY_KEY || K < subroot->rKey) {
			return find_help(subroot->centerP, K, e);
		}

		return find_help(subroot->rightP, K, e);
	}


	void insert_help(TT_node* subroot,
				const int e, int& retVal, TT_node*& retP) {

		if (subroot == NULL) {
			subroot = new TT_node(e, e);
			return ;
		}

		int my_retv;
		TT_node* my_retp = NULL;

		if (subroot->isLeaf()) {
			if (subroot->rKey == EMPTY_KEY) {  //Easy case :not full
				if (subroot->lKey < e) {
					subroot->rKey = e;
					subroot->rVal = e;
				}else {
					subroot->rKey = subroot->lKey;
					subroot->rVal = subroot->lVal;
					subroot->lKey = e;
					subroot->lVal = e;
				}
			}else {
				splitnode(subroot, e, NULL, retVal, retP);
			}
		}else if(e<subroot->lKey){
			insert_help(subroot->leftP, e, my_retv, my_retp);
		}else if (subroot->rKey == EMPTY_KEY || e<subroot->rKey){
			insert_help(subroot->centerP, e, my_retv, my_retp);
		}else {
			insert_help(subroot->rightP, e, my_retv, my_retp);
		}

		if (my_retp != NULL) {

			if (subroot->rKey != EMPTY_KEY) {			//full
				splitnode(subroot, my_retv, my_retp, retVal, retP);
			}else{ //Not full:add to this node
				if (my_retv < subroot->lKey) {
					subroot->rKey = subroot->lKey;
					subroot->rVal = subroot->lVal;
					subroot->lKey = my_retv;
					subroot->lVal = my_retv;

					subroot->rightP = subroot->centerP;
					subroot->centerP = my_retp;
				}
				else {
					subroot->rKey = my_retv;
					subroot->rVal = my_retv;
					subroot->rightP = my_retp;
				}
			}

		}
	}


	bool splitnode(TT_node* subroot, const int inval,
			TT_node*inptr, int& retval, TT_node*& retptr) {

		retptr = new TT_node();
		if (inval < subroot->lKey) { //Add at left
			retval = subroot->lKey;

			subroot->lKey = inval;
			subroot->lVal = inval;

			retptr->lKey = subroot->rKey;
			retptr->lVal = subroot->rVal;

			retptr->leftP = subroot->centerP;
			retptr->centerP = subroot->rightP;
			subroot->centerP = inptr;

		}else if (inval < subroot->rKey) { //Center
			retval = inval;

			retptr->lKey = subroot->rKey;
			retptr->lVal = subroot->lVal;

			retptr->leftP = inptr;
			retptr->centerP = subroot->rightP;
		}else{										//Add at right
			retval = subroot->rKey;
			retptr->lKey = inval;
			retptr->lKey = inval;
			retptr->leftP = subroot->rightP;
			retptr->centerP = inptr;
		}
		subroot->rKey = EMPTY_KEY;
		subroot->rightP = NULL;
	}
};

