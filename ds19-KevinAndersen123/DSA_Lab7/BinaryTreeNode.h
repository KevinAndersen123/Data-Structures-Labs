#ifndef BINARYTREENODE_H
#define BINARYTREENODE_H


// Forward references.
template <typename T>class Container;
template <typename T>class BinaryTreeIterator;

template <typename T>
class BinaryTreeNode {

public:    
    // Constructor
    BinaryTreeNode(T element, Container<T>* container=0, 
             BinaryTreeNode<T>* parent=0); 
         
    // Generic Position functions
    virtual T element () const;
    virtual Container<T>* container() const;    
    virtual void setElement(T element);
    
    // TreeNode specific functions
    // Manipulators
    void setParent(BinaryTreeNode<T>* parent); 
    void setLeftChild(BinaryTreeNode<T>* left); 
    void setRightChild(BinaryTreeNode<T>* right); 
    
    // Accessors    
    BinaryTreeIterator<T> parent() const;
    BinaryTreeIterator<T> leftChild() const;
    BinaryTreeIterator<T> rightChild() const;        
    
private:    
    
    T m_element;    
    BinaryTreeNode<T>* m_parent;
    BinaryTreeNode<T>* m_leftChild;
    BinaryTreeNode<T>* m_rightChild;
    Container<T>* m_container;           
};

template <typename T>
BinaryTreeNode<T>::BinaryTreeNode(T element, Container<T>* pContainer, 
       BinaryTreeNode<T>* pParent) :
       m_element(element), 
       m_container(pContainer), 
       m_parent(pParent),
       m_leftChild(0),
       m_rightChild(0)
       {} 

template <typename T>
T BinaryTreeNode<T>::element() const {
    return m_element;    
}

template <typename T>
Container<T>* BinaryTreeNode<T>::container() const {
    return m_container;   
}

template <typename T>
void BinaryTreeNode<T>::setElement(T element) {
   m_element = element;
}

template <typename T>
void BinaryTreeNode<T>::setParent(BinaryTreeNode<T>* parent) {
   m_parent = parent;
}

template <typename T>
void BinaryTreeNode<T>::setLeftChild(BinaryTreeNode<T>* leftChild) {
   m_leftChild = leftChild;
}

template <typename T>
void BinaryTreeNode<T>::setRightChild(BinaryTreeNode<T>* rightChild) {
   m_rightChild = rightChild;
}

template <typename T>
BinaryTreeIterator<T> BinaryTreeNode<T>::parent() const {
   return BinaryTreeIterator<T>(m_parent);
}

template <typename T>
BinaryTreeIterator<T> BinaryTreeNode<T>::leftChild() const {
   return BinaryTreeIterator<T>(m_leftChild);
}

template <typename T>
BinaryTreeIterator<T> BinaryTreeNode<T>::rightChild() const {
   return BinaryTreeIterator<T>(m_rightChild);   
}

#include "BinaryTreeIterator.h"
#endif

