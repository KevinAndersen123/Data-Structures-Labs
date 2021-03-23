#include <iostream>

#pragma once

#include "SListNode.h"

template <typename T>
class SListIterator : public std::iterator<std::forward_iterator_tag, T> 
{ 
public:
    SListIterator(SListNode<T>* t_initialNode = 0) 
	{
        m_current = t_initialNode; 
    }
        
    T & operator *() const 
	{ 
	    return (*m_current).element();  
    } 
    
	SListNode<T>* get() 
	{
		return m_current;
	}

	SListIterator<T>& operator ++(); // Prefix ++
	SListIterator<T> operator ++(int); // Postfix ++	
	bool operator ==(SListIterator<T> t_other) const; 
	bool operator !=(SListIterator<T> t_other) const; 
    T & operator [](int index) ;
	
private:
	SListNode<T>* m_current;
};

template <typename T>
SListIterator<T>& SListIterator<T> :: operator ++() 
{ 
     m_current = m_current->next().get();
     return *this;
}
	
template <typename T>
SListIterator<T> SListIterator<T> :: operator ++(int) 
{
     SListIterator<T> original(m_current);
     m_current = m_current->next().get();
     return original;      	  
}

template <typename T>
bool SListIterator<T> :: operator ==(const SListIterator<T> t_other) const 
{ 
     return m_current == t_other.m_current;  
}
	
template <typename T>
bool SListIterator<T> :: operator !=(const SListIterator<T> t_other) const 
{
     return m_current != t_other.m_current;   
}

template <typename T>
T & SListIterator<T> :: operator [](int t_index) 
{
	for (int i = 0; i < t_index; i++) 
	{
		m_current = m_current->next().get();		
	}
	return m_current->element();
}


