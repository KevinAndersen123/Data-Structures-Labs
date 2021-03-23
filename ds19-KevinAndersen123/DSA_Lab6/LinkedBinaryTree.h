#ifndef LINKEDBINARYTREE_H
#define LINKEDBINARYTREE_H
#include <stack>
#include  <algorithm>
// Forward references.
template <typename T, typename Iterator>class BinaryTree;
template <typename T>class BinaryTreeNode;
template <typename T>class Container;

template <typename T, typename Iterator>
class LinkedBinaryTree : public BinaryTree<T, Iterator> {      
public:       
    // LinkedBinaryTree specific member functions
    // Constructor          
    LinkedBinaryTree(T element);
    // Copy constructor
    LinkedBinaryTree(LinkedBinaryTree<T, Iterator> const & other) {
       copy(other);
    }
    // Destructor
    ~LinkedBinaryTree() {
       destroy();
    }
        
    // Generic container functions
    virtual int size() const;
    virtual bool isEmpty() const;          
    
    // Generic SimpleTree functions
    virtual Iterator root() const;
    virtual Iterator parent(Iterator & position) const;  
    virtual bool isInternal(Iterator & position) const;
    virtual bool isExternal(Iterator & position) const;
    virtual bool isRoot(Iterator & position) const;   
    virtual void swap(Iterator & first, Iterator & second);
    virtual void replace(Iterator & position, T element);
	virtual int depth(Iterator iter);
	virtual int depthNonRecursive(Iterator iter);
    // BinaryTree functions
    virtual Iterator & leftChild(Iterator & position) const;
    virtual Iterator & rightChild(Iterator & position) const;
	virtual Iterator treeMinimum(Iterator& n) const;
	virtual int height(Iterator n) const;

	// Functions to return tree iterators
	Iterator & begin();
	Iterator & end();

    // Binary search tree function - inserts a new key
	Iterator insertItem(T key, Iterator iter, Iterator iterParent);
	// Binary search tree function - searches for a key
	Iterator treeSearch(T key, Iterator iter);
	
   
private:
    BinaryTreeNode<T>* m_root;     // Pointer to the root node
    int m_count;                    // Number of nodes in the tree
        
    void copy(LinkedBinaryTree<T, Iterator> const & other);
    void destroy();
};

template <typename T, typename Iterator>
LinkedBinaryTree<T, Iterator>::LinkedBinaryTree(T element) : m_count(1) {
    m_root = new BinaryTreeNode<T>(element, this, 0);    
}

template <typename T, typename Iterator>
void LinkedBinaryTree<T, Iterator>::copy(LinkedBinaryTree<T, Iterator> const & other) {
    m_root = new BinaryTreeNode<T>(*(other.m_root));        
    m_count = other.m_count;
}

template <typename T, typename Iterator>
void LinkedBinaryTree<T, Iterator>::destroy() {
   delete m_root;
}


template <typename T, typename Iterator>
int LinkedBinaryTree<T, Iterator>::size() const {
    return m_count;
}

template <typename T, typename Iterator>
bool LinkedBinaryTree<T, Iterator>::isEmpty() const {
    return (m_count == 0);
}

template <typename T, typename Iterator>
void LinkedBinaryTree<T, Iterator>::swap(Iterator & first, Iterator & second) {
   T temp = (*first);
   (*first) = (*second);
   (*second) = temp;   
}

template <typename T, typename Iterator>
void LinkedBinaryTree<T, Iterator>::replace(Iterator & position, T element) {
    (*position) = element;	
}

template<typename T, typename Iterator>
inline int LinkedBinaryTree<T, Iterator>::depth(Iterator iter)
{
	if (isRoot(iter))
	{
		return 0;
	}
	else
	{
		return 1 + depth(parent(iter));
	}
}

template<typename T, typename Iterator>
inline int LinkedBinaryTree<T, Iterator>::depthNonRecursive(Iterator iter)
{
	int depth = 0;
	while(iter.up())
	{
		depth++;
	}
	return depth;

}

template <typename T, typename Iterator>
Iterator LinkedBinaryTree<T, Iterator>::root() const {
    return Iterator(m_root);
}

template <typename T, typename Iterator>
Iterator LinkedBinaryTree<T, Iterator>::parent(Iterator & position) const {     
	return position.node()->parent();
}

template <typename T, typename Iterator>
bool LinkedBinaryTree<T, Iterator>::isInternal(Iterator & position) const {	
	return ( position.node()->leftChild() != 0 || position.node()->rightChild() != 0);    
}

template <typename T, typename Iterator>
bool LinkedBinaryTree<T, Iterator>::isExternal(Iterator & position) const {
	return ( position.node()->leftChild() == 0 && position.node()->rightChild() == 0);    
}

template <typename T, typename Iterator>
bool LinkedBinaryTree<T, Iterator>::isRoot(Iterator & position) const {	
    return ( position == m_root );
}

template <typename T, typename Iterator>
Iterator & LinkedBinaryTree<T, Iterator>::leftChild(Iterator & position) const {    	
	Iterator & iter = position;
	if ( position.node() != 0 ) {
		iter = position.node()->leftChild();
	}
	return iter;
}

template <typename T, typename Iterator>
Iterator & LinkedBinaryTree<T, Iterator>::rightChild(Iterator & position) const {    
    Iterator & iter = position;
	if (position.node() != 0) {
		iter = position.node()->rightChild();
	}
	return iter;
}

template<typename T, typename Iterator>
inline Iterator LinkedBinaryTree<T, Iterator>::treeMinimum(Iterator& n) const
{
	Iterator minValue = n;
	while (minValue.downLeft());
	return minValue;
}

template<typename T, typename Iterator>
inline int LinkedBinaryTree<T, Iterator>::height(Iterator n) const
{
	if (isInternal(n))
	{
		int x = 0;
		int y = 0;
		if (n.node()->leftChild() != nullptr)
		{
			x = height(n.node()->leftChild());
		}
		if (n.node()->rightChild() != nullptr)
		{
			y = height(n.node()->rightChild());
		}
		
		return std::max(x, y) + 1;
	}
	return 0;
}

template <typename T, typename Iterator>
Iterator LinkedBinaryTree<T, Iterator>::treeSearch(T key, Iterator iter) {
	/*if n is an external node and key(n) <> k then
  return NULL KEY
if k == key(n) then
  return n
else if k < key(n) then
  return treeSearch(k, T.leftChild(n))
else
  { we know that k > key(n) }
  return treeSearch(k, T.rightChild(n))*/
	
	if ( iter.node() == 0 || isExternal(iter) && (*iter) != key ) {
		return Iterator(0);
	}
	if ( key == (*iter) ) {
		return iter;
	}	
	else if ( key < (*iter) ) {
		return treeSearch( key, leftChild(iter) );
	}
	else {
		return treeSearch( key, rightChild(iter) );
	}
}
template <typename T, typename Iterator>
Iterator LinkedBinaryTree<T, Iterator>::insertItem(T key, Iterator iter, 
													          Iterator iterParent) {
    BinaryTreeNode<T> * node = iter.node();
	if ( node == 0) {       
       node = new BinaryTreeNode<T>(key, this);
       node->setLeftChild(0);
       node->setRightChild(0);
       node->setParent(iterParent.node());
	   m_count++;
    }
    else if (key < node->element()) {
       Iterator tempIter = insertItem(key, node->leftChild(), iter );
       node->setLeftChild( tempIter.node() );       
    }
    else if (key > node->element()) {
	   Iterator tempIter = insertItem(key, node->rightChild(), iter );
       node->setRightChild( tempIter.node() );              
    }
    
    return Iterator(node);    
}

template <typename T, typename Iterator>
Iterator & LinkedBinaryTree<T, Iterator>::begin() {
	return Iterator(m_root);	
}

template <typename T, typename Iterator>
Iterator & LinkedBinaryTree<T, Iterator>::end() {
	return m_root->parent();	
}

#include "BinaryTree.h"
#include "BinaryTreeNode.h"

#endif
