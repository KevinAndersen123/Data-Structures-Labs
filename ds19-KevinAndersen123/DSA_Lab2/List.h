#pragma once
#include <list>
// Forward references.
template <typename T, typename Iterator>class Sequence;

template <typename T, typename Iterator>
class List : public Sequence<T, Iterator> 
{
public:        
    virtual void insertFirst(T t_element) = 0;
    virtual void insertLast(T t_element) = 0;
    virtual void insertAfter(Iterator & t_position, T t_element) = 0;
	virtual void insertBefore(Iterator & t_position, T t_element) = 0;
    virtual Iterator remove(Iterator & t_position) = 0;    
    virtual int remove(T t_element) = 0;	
};

#include "Sequence.h"
