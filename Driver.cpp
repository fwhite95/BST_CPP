#include "BST_H.h"
#include <iostream>
using namespace std;


int main()
{
	BST<int> myTree1;
	for (int i = 0; i < 10; i++)
		myTree1.insert(i);
	cout << "TEST 1: Number Tree...\n";
	myTree1.deleteNode(0);
	myTree1.inOrder();
	myTree1.postOrder();
	myTree1.preOrder();

	myTree1.deleteNode(9);
	myTree1.inOrder();

	BST<char> myTree2;
	for (int i = 0; i < 10; i++)
		myTree2.insert(static_cast<char> ('A' + i));
	cout << "\nTEST 2: Character Tree...\n";
	myTree2.preOrder();
	myTree2.inOrder();
	myTree2.postOrder();


	cout << endl << endl;

	BST<int> myTree;
	myTree.insert(55);
	myTree.insert(20);
	myTree.insert(1);
	myTree.insert(54);
	myTree.insert(52);
	myTree.insert(50);
	myTree.insert(45);
	myTree.insert(90);
	myTree.insert(100);
	myTree.insert(60);
	myTree.insert(64);
	myTree.insert(68);
	myTree.insert(80);


	myTree.inOrder();
	myTree.deleteNode(55);
	myTree.inOrder();
	myTree.deleteNode(45);
	myTree.inOrder();
	myTree.deleteNode(20);
	myTree.inOrder();
	myTree.deleteNode(90);
	myTree.inOrder();
	myTree.deleteNode(64);
	myTree.inOrder();
	cout << endl;
	return 0;
}

