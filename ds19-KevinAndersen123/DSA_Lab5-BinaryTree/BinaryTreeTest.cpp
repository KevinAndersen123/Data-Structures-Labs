#include "LinkedBinaryTree.h"
#include "BinaryTreeIterator.h"

#include <iostream>


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
	system("PAUSE");
	
}
