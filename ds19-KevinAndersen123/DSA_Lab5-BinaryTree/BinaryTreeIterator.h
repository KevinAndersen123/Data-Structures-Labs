#ifndef BINARYTREEITERATOR_H
#define BINARYTREEITERATOR_H


template <typename T>class BinaryTreeNode;  // Forward reference.

template <typename T>
class BinaryTreeIterator { 
public:
    BinaryTreeIterator(BinaryTreeNode<T>* initialNode) : 
       m_current(initialNode)
       {}

    T & operator *() { 
		T element = (*m_current).element();
		return element;	    
    } 
    
	BinaryTreeNode<T> * node() {
		return m_current;
	}

    
	bool operator ==(BinaryTreeIterator<T> other) const; 
	bool operator !=(BinaryTreeIterator<T> other) const; 
	
	// Iterator movement.
    bool forth();	
	bool downLeft();
    bool downRight();
    bool up();
    
     
private:   	
	BinaryTreeNode<T>* m_current;         // Pointer to the current node
};

template <typename T>
bool BinaryTreeIterator<T> :: forth() { 	
	bool moved = false;
	BinaryTreeIterator<T> parent = m_current->parent();
     
     if (parent.node() != 0) {	    
		BinaryTreeIterator<T> rightChild = parent.node()->rightChild();        
        if (rightChild.node() != 0) {
			moved = true;
            m_current = rightChild.node();
        }
     }   
	 return moved;
}
	
template <typename T>
bool BinaryTreeIterator<T> :: operator ==(const BinaryTreeIterator<T> other) const { 
     return m_current == other.m_current;  
}

template <typename T>
bool BinaryTreeIterator<T> :: operator !=(const BinaryTreeIterator<T> other) const {
     return m_current != other.m_current;   
}

template <typename T>
bool BinaryTreeIterator<T> :: downLeft() {    
	
	if (m_current != 0 && m_current->leftChild() != 0) {
		BinaryTreeIterator<T> iter = m_current->leftChild();		
		m_current = iter.node();
		return true;
	}	
	return false;
}

template <typename T>
bool BinaryTreeIterator<T> :: downRight() {     	
	if (m_current != 0 && m_current->rightChild() != 0) {
		BinaryTreeIterator<T> iter = m_current->rightChild();		
		m_current = iter.node();
		return true;
	}	
	return false;
}

template <typename T>
bool BinaryTreeIterator<T> :: up() {	 
	if (m_current != 0 && m_current->parent() != 0) {
		BinaryTreeIterator<T> iter = m_current->parent();	
		m_current = iter.node();	
		return true;
	}	
	return false;
}


#include "BinaryTreeNode.h"

#endif 
