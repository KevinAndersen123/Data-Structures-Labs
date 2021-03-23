#ifndef BINARYTREE_H
#define BINARYTREE_H

// Forward references.
template <typename T, typename Iterator> class SimpleTree;

template <typename T, typename Iterator>
class BinaryTree : public SimpleTree<T, Iterator> {
public:       
    virtual Iterator & leftChild(Iterator & position) const = 0;
    virtual Iterator & rightChild(Iterator & position) const = 0;
};

#include "SimpleTree.h"

#endif
