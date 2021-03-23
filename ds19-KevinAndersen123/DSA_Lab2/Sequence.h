#pragma once

// Forward references.
template <typename T> class Container;

template <typename T, typename InputIterator>
class Sequence : public Container<T> 
{
public:       
    virtual void swap(InputIterator & t_first, InputIterator & t_second) = 0;
	virtual void replace(InputIterator & t_position, T t_element) = 0;    
};

#include "Container.h"

