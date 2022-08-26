#include <iostream>
#include "BST.h"

using namespace std;

BST::BST() { root = NULL; }

BST::~BST() {}

void BST::insertNode(int data){
    Node * newNode = new Node();
    newNode->data = data;
    newNode->left = newNode->right = NULL;

    insert(root, newNode);

    size++;
}

void BST::insert(Node *&root, Node *&newNode){

    if(root == NULL) root = newNode;

    
	else if (newNode->data < root->data)
    {
        insert(root->left, newNode);
    }
    else
    {
        insert(root->right, newNode);
    }
}


void BST::print() {
	Node* temp = root;
	cout << endl;
	cout << endl << "Printing data in BST..." << endl;
	DisplayInOrder(temp);
}

void BST::DisplayInOrder(Node* temp) {
	if (root == NULL) {
		cout << endl << "List is empty. Nothing to display." << endl;
		return;
	}

	if (temp->left != NULL) {
		DisplayInOrder(temp->left);
	}
	
	cout << temp->data << endl;
	
	if (temp->right != NULL) {
		DisplayInOrder(temp->right);
	}

	// cout << temp->data;
}

void BST::search(int data) {
	Node* temp = root;
	searchNode(temp, data);
}

void BST::searchNode(Node* temp, int data) {
	if (root == NULL) {
		cout << endl << "List is empty. No items to match." << endl << endl;
		return;
	}

	if (temp->left != NULL) {
		searchNode(temp->left, data);
	}

	if (temp->data == data) {
		cout << endl << "Search Operation: Node with value " << data << " found." << endl;
		return;
	}

	if (temp->right != NULL) {
		searchNode(temp->right, data);
	}
}