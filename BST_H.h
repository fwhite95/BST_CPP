/*****   HEADER:  BST_H.h   *****/

//White, Freddie
//3/7/2017
//MS Visual C++ 2015
//Class template implementation: BST

#ifndef FWHITEBST
#define FWHITEBST


template <class T>
class BST
{
public:
	BST();

	void insert(T new_item);
	void deleteNode(T deleteMe);

	//Tree traversals
	void inOrder();
	void preOrder();
	void postOrder();

private:
	struct Node
	{
		T data;
		Node *llink = nullptr;
		Node *rlink = nullptr;
	};

	Node *m_root = nullptr;

	void helperInOrder(Node *ptr, int type);
	void deleteLeafNode(Node *leaf, Node *parent);
	void deleteListNode(Node *leaf, Node *parent);
	void deleteTreeNode(Node *tree, Node *parent);
};

template <class T>
BST<T>::BST()
{
	m_root = nullptr;
}

template <class T>
void BST<T>::insert(T new_item)
{
	//Create the new node for insert item
	Node *temp = new Node;
	temp->data = new_item;
	temp->llink = nullptr;
	temp->rlink = nullptr;

	//Insert into an empty tree
	if (m_root == nullptr)
	{
		m_root = temp;
		return;
	}

	//1. 'trailPtr' trails right behind movPtr as it moves
	//	down to find the spot for insertion
	//	REASON: movPtr will become null at some point
	//		but we need the last node it last traversed to,
	//		in order to link up the new node.
	//2. 'left' boolean variable allows us to determine
	//	if we need to link the new node to the left of right 
	//	link of an existing node.

	Node *movPtr = m_root;
	Node *trailPtr = movPtr;
	bool left = true;
	while (movPtr != nullptr)
	{
		if (movPtr->data > new_item)
		{
			trailPtr = movPtr;
			movPtr = movPtr->llink;
			left = true;
		}
		else if (movPtr->data < new_item)
		{
			trailPtr = movPtr;
			movPtr = movPtr->rlink;
			left = false;
		}
		else if (movPtr->data == new_item)
			return;
	}

	//Choose left or right link to link up
	//	the new node pointed to by 'temp'
	if (left)
		trailPtr->llink = temp;
	else
		trailPtr->rlink = temp;

	temp = nullptr;
}

template <class T>
void BST<T>::deleteNode(T deleteMe)
{
	cout << "Deleting node: " << deleteMe << endl;
	Node *index = m_root;
	Node *parent = index;
	while (index != nullptr && index->data != deleteMe) {
		parent = index;
		if (deleteMe < index->data) {
			index = index->llink;
		}
		else {
			index = index->rlink;
		}
	}

	if (index == nullptr)
		return; // Return if node doesnt exist

	if (index->llink == nullptr && index->rlink == nullptr)
		deleteLeafNode(index, parent);
	else if (index->llink == nullptr || index->rlink == nullptr)
		deleteListNode(index, parent);
	else
		deleteTreeNode(index, parent);
}

template <class T>
void BST<T>::deleteListNode(Node *leaf, Node *parent) {
	// Delete Head Node
	if (leaf->data == parent->data) {
		if (leaf->llink == nullptr) {
			parent = parent->rlink;
		}
		else {
			parent = parent->llink;
		}
		m_root = parent;

		// delete left link
	}
	else if (parent->llink != nullptr && parent->llink->data == leaf->data) {

		if (leaf->llink == nullptr) {
			parent->llink = leaf->rlink;
		}
		else if (leaf->rlink == nullptr) {
			parent->llink = leaf->llink;
		}
	}

	// delete right link
	else if (parent->rlink != nullptr && parent->rlink->data == leaf->data) {
		if (leaf->llink == nullptr) {
			parent->rlink = leaf->rlink;
		}
		else if (leaf->rlink == nullptr) {
			parent->rlink = leaf->llink;
		}
	}

	// delete the node
	delete leaf;
}

template<class T>
inline void BST<T>::deleteTreeNode(Node *tree, Node *parent)
{
	Node *nextBiggest = tree;
	while (tree->rlink != nullptr && tree->llink != nullptr)
	{
		parent = nextBiggest;
		nextBiggest = tree->llink;
		while (nextBiggest->rlink != nullptr)
		{
			parent = nextBiggest;
			nextBiggest = nextBiggest->rlink;
		}

		T temp = tree->data;
		tree->data = nextBiggest->data;
		nextBiggest->data = temp;

		if (nextBiggest->rlink == nullptr && nextBiggest->llink == nullptr)
			return deleteLeafNode(nextBiggest, parent);
		else if (nextBiggest->rlink == nullptr || nextBiggest->llink == nullptr)
			return deleteListNode(nextBiggest, parent);

	}
}

template <class T>
void BST<T>::deleteLeafNode(Node *leaf, Node *parent)
{
	if (parent->rlink != nullptr && parent->rlink->data == leaf->data) {
		parent->rlink = nullptr;
	}
	else {
		parent->llink = nullptr;
	}
	delete leaf;
}

template <class T>
void BST<T>::inOrder()
{
	helperInOrder(m_root, 2);
	cout << endl;
}


template <class T>
void BST<T>::preOrder()
{
	helperInOrder(m_root, 1);
	cout << endl;
}

template <class T>
void BST<T>::postOrder()
{
	helperInOrder(m_root, 3);
	cout << endl;
}

template <class T>
void BST<T>::helperInOrder(Node *ptr, int type)
{
	if (ptr != nullptr)
	{
		if (type == 1) cout << ptr->data << ' ';
		helperInOrder(ptr->llink, type);
		if (type == 2) cout << ptr->data << ' ';
		helperInOrder(ptr->rlink, type);
		if (type == 3) cout << ptr->data << ' ';
	}
}

#endif //FWHITEBST!
