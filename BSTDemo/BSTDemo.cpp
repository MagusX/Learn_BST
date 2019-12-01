// BSTDemo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream> 
using namespace std;

struct Node {
	int key;
	Node* left;
	Node* right;
};

Node* create(int k) {
	Node* pNode = new Node;
	pNode->key = k;
	pNode->left = NULL;
	pNode->right = NULL;
	return pNode;
}

void add(Node* &pCur, int k) {
	if (pCur == NULL) pCur = create(k);
	else if (k < pCur->key) add(pCur->left, k);
	else if (k > pCur->key) add(pCur->right, k);
	else return;
}

bool find(Node* pCur, int k) {
	if (pCur == NULL) return false;
	if (k < pCur->key) find(pCur->left, k);
	else if (k > pCur->key) find(pCur->right, k);
	else return true;
}

void searchStandFor(Node* &toKill, Node* &decoy) {
	if (toKill->right) searchStandFor(toKill->right, decoy);
	else {
		decoy->key = toKill->key;
		Node* tNode = toKill;
		toKill = toKill->left;
		delete tNode;
		tNode = NULL;
	}
}
void remove(Node*& pCur, int k) {
	if (pCur == NULL) return;
	if (k < pCur->key) remove(pCur->left, k);
	else if (k > pCur->key) remove(pCur->right, k);
	else {
		Node* t = pCur;
		if (pCur->left == NULL) {
			pCur = pCur->right;
			delete t;
			t = NULL;
		} else if (pCur->right == NULL) {
			pCur = pCur->left;
			delete t;
			t = NULL;
		} else searchStandFor(t->left, pCur);
	}
}

void traverse(Node* pCur) {
	if (pCur == NULL) return;
	traverse(pCur->left);
	cout << pCur->key << ", ";
	traverse(pCur->right);
}

int height(Node* pCur) {
	if (pCur == NULL) return 0;
	int lHeight = height(pCur->left);
	int rHeight = height(pCur->right);
	if (lHeight > rHeight) return lHeight + 1;
	return rHeight + 1;
}

int main()
{
	Node* tree = NULL;
	add(tree, 9);
	add(tree, 12);
	add(tree, 3);
	add(tree, 4);
	add(tree, 6);
	add(tree, 5);
	add(tree, 8);
	add(tree, 7);
	
	cout << height(tree);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
