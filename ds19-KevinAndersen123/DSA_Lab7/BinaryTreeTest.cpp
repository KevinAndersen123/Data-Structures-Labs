#include "LinkedBinaryTree.h"
#include "BinaryTreeIterator.h"
#include <string>
#include <iostream>


template <typename T>
void binaryPreorder(BinaryTreeNode<T>* node);
template <typename T>
void binaryInorder(BinaryTreeNode<T>* node);

int main() {	

	LinkedBinaryTree<int, BinaryTreeIterator<int>> myTree(10);
	BinaryTreeIterator<int> iter = myTree.root();
	BinaryTreeIterator<int> parentOfIter = myTree.parent(iter);
	myTree.insertItem(5, iter, parentOfIter);
	myTree.insertItem(15, iter, parentOfIter);
	myTree.insertItem(25, iter, parentOfIter);
	myTree.insertItem(35, iter, parentOfIter);
    
	//Uncomment the below to test your solution to Lab Exercise 5.
	iter = myTree.root();
	
	iter.downRight();
	iter.downRight();
	iter.downRight();
	std::cout << "Depth of node using non Recursive: " << *iter << " is " << myTree.depthNonRecursive(iter) << std::endl;
	std::cout << "Depth of node using Recursive: " << *iter << " is " << myTree.depth(iter) << std::endl;
	//Reset the tree iterator to the root.
	iter = myTree.root();
	std::cout << "Tree minimum rooted at: " << *myTree.root() << " is " << *myTree.treeMinimum(iter) << std::endl;
	binaryInorder(myTree.root().node());

	LinkedBinaryTree<int, BinaryTreeIterator<int>> myTree2(38);
	BinaryTreeIterator<int> iter2 = myTree2.root();
	BinaryTreeIterator<int> parentOfIter2 = myTree2.parent(iter);
	myTree2.insertItem(20, iter2, parentOfIter2);
	myTree2.insertItem(10, iter2, parentOfIter2);
	myTree2.insertItem(23, iter2, parentOfIter2);
	myTree2.insertItem(22, iter2, parentOfIter2);
	myTree2.insertItem(27, iter2, parentOfIter2);
	myTree2.insertItem(55, iter2, parentOfIter2);
	myTree2.insertItem(51, iter2, parentOfIter2);
	myTree2.insertItem(49, iter2, parentOfIter2);
	myTree2.insertItem(52, iter2, parentOfIter2);
	myTree2.insertItem(39, iter2, parentOfIter2);
	iter2 = myTree2.root();
	std::cout << "Height of tree: " << *iter2 << " is " << myTree2.height(iter2) << std::endl;

	iter = myTree2.root();
	iter.downLeft();
	iter.downLeft();
	myTree2.deleteItem(iter);
	iter = myTree2.root();
	std::cout << iter.node()->element() << std::endl;
	system("PAUSE");

}

template<typename T>
void binaryPreorder(BinaryTreeNode<T>* node)
{
	std::cout << node->element() << std::endl;

	if (node->leftChild() != nullptr)
	{
		binaryPreorder(node->leftChild().node());
	}
	if (node->rightChild() != nullptr)
	{
		binaryPreorder(node->rightChild().node());
	}

}

template<typename T>
void binaryInorder(BinaryTreeNode<T>* node)
{
	std::stack<BinaryTreeNode<T>*> m_stack;
	while (!m_stack.empty() || node != nullptr)
	{
		while(node != nullptr)
		{
			m_stack.push(node);
			node = node->leftChild().node();
		}
		if (node == nullptr)
		{
			node = m_stack.top();
			m_stack.pop();
			std::cout << "Visiting " + std::to_string(node->element()) << std::endl;
			node = node->rightChild().node();
		}
	}
} 
