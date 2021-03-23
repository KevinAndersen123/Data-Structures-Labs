#pragma once

#include <memory>	// for std::unique_ptr
#include <stack>
#include "List.h"
#include "SListNode.h"
#include "SListIterator.h"

// First the class interface
template <typename T, typename InputIterator>
class SLinkedList : public List<T,InputIterator> 
{
public:        
               
    SLinkedList();           

    int size() const override;
    bool isEmpty() const override;
	void swap(InputIterator & t_first, InputIterator & t_second) override;
    void replace(InputIterator & t_position, T t_element) override;        
    void insertFirst(T t_element) override;
    void insertLast(T t_element) override;
    void insertAfter(InputIterator & t_position, T t_element) override;  	
	void insertBefore(InputIterator & t_position, T t_element) override;
	void reverse();
	void makeNewHead(InputIterator t_position);
	void splice(InputIterator t_position, std::list<T>& t_source);

	InputIterator remove(InputIterator & t_position) override;
    int remove(T t_element) override;
	
    // Member functions specific to SLinkedList
    SListNode<T>* head() const;
    SListNode<T>* tail() const;
    
    SListIterator<T> begin() const;        
    SListIterator<T> end() const;        
	SListIterator<T> last() const;
    
private:
    std::unique_ptr<SListNode<T>> m_head;
	SListNode<T>* m_tail;
    int m_count;
};

// Now the class implementation.

template <typename T, typename InputIterator>
SLinkedList<T, InputIterator>::SLinkedList() :
    m_head(nullptr),
    m_tail(nullptr),
    m_count(0)
    {}


template <typename T, typename InputIterator>
int SLinkedList<T, InputIterator>::size() const 
{
    return m_count;
}

template <typename T, typename InputIterator>
bool SLinkedList<T, InputIterator>::isEmpty() const 
{
    return m_count == 0;
}

template <typename T, typename InputIterator>
void SLinkedList<T, InputIterator>::swap(InputIterator & t_first, InputIterator & t_second) 
{    
    T temp = *t_first;
	*t_first = *t_second;        
    *t_second = temp;		
}

template <typename T, typename InputIterator>
void SLinkedList<T, InputIterator>::replace(InputIterator & t_position, T t_element) 
{    
    *t_position = t_element; 
}

template <typename T, typename InputIterator>
void SLinkedList<T, InputIterator>::insertFirst(T t_element) 
{
        // create the new node.		
		std::unique_ptr<SListNode<T>> newNode = std::make_unique<SListNode<T>>(t_element, this);       
        newNode->setNext(m_head);
        // set the head node, and the tail node if needed.
		std::swap(m_head, newNode);
        
        if( m_tail == nullptr ) 
		{			
			m_tail = m_head.get();
        }    
        
        m_count++;  
}

template <typename T, typename InputIterator>
void SLinkedList<T, InputIterator>::insertLast(T t_element) 
{
	std::unique_ptr<SListNode<T>> newNode = std::make_unique<SListNode<T>>(t_element);
	//check if list empty
	if (m_head == nullptr)
	{
		//linnk head ptr to the first element
		std::swap(m_head, newNode);
		m_tail = m_head.get();// read the head ptr as a raw ptr
	}
	//otherwise, list is not empty
	else	
	{
		m_tail->setNext(newNode); //link last node to the new node
		//update the tail ptr
		m_tail = m_tail->next().get();

	}
}

template <typename T, typename InputIterator>
void SLinkedList<T, InputIterator>::insertAfter(InputIterator & t_position, T t_element) 
{
        
		SListNode<T>* temp = t_position.get();       
		
		if (temp != nullptr) 
		{
			std::unique_ptr<SListNode<T>> newNode = std::make_unique<SListNode<T>>(t_element, this);

			newNode->setNext(temp->next());
			// if the new node is the new end of list node
			if (newNode->next() == nullptr) 
			{
				m_tail = newNode.get();
			}
			temp->setNext(newNode);	// newNode is now nullptr
			
			m_count++;
		}
}

template <typename T, typename InputIterator>
void SLinkedList<T, InputIterator>::insertBefore(InputIterator & t_position, T t_element) 
{
	SListNode<T>* temp = t_position.get();

	if (temp != nullptr)
	{
		std::unique_ptr<SListNode<T>> newNode = std::make_unique<SListNode<T>>(t_element, this);

		if (temp == m_head.get())
		{
			std::swap(m_head, newNode->next());
			//head ptr to first element
			std::swap(m_head, newNode);
		}
		else{
			SListNode<T>* previous = m_head.get();

			//loops through list until you get to the position of the next in the position, sets previous to point to the node one before the node you want to insert
			for (; previous->next().get() != temp; previous = previous->next().get());

			std::swap(previous->next(), newNode->next());
			std::swap(previous->next(), newNode);
		}
	}

}

template<typename T, typename InputIterator>
inline void SLinkedList<T, InputIterator>::reverse()
{
	//create a stack
	std::stack<T> stackNodes;
	//push the node elements onto the stack
	for (SListNode<T>* node = m_head.get(); node->next().get() != nullptr; node = node->next().get())
	{
		stackNodes.push(node->element());
	}

	stackNodes.push(m_tail->element());
	//swap the last element and the last element and pop 
	for (SListNode<T>* node = m_head.get(); stackNodes.size() != 0; node = node->next().get())
	{
		std::swap(node->element(), stackNodes.top());
		stackNodes.pop();
	}

	//push address of each node onto stack 
	//pop top pointer in the stack 
	//swap element of last node to the first element 
	//pop next pointer on stack. swap element of this node with the second node in the list,repeat until stack is empty
}

template <typename T, typename InputIterator>
InputIterator SLinkedList<T, InputIterator>::remove(InputIterator & t_position) 
{
      SListNode<T>* node = t_position.get();	     
      
	  // Advance the iterator position to the next node
	  ++t_position;

      // If the node to be removed is at the head of the list
      if (m_head.get() == node) 
	  {
		  m_head = std::move(m_head->next());		  
      }
      else 
	  { // Node to be deleted has a predecessor.
		   SListNode<T>* previous = m_head.get();

           // Set up 'previous' to point to the node one before the node we wish to delete.
	       for ( ; previous->next().get() != node; previous = previous->next().get() );

		   // If the node to be deleted is the tail.
           if (node == m_tail) 
		   {
              m_tail = previous;
           }
		   // Get a (unique_ptr) reference to the node to be deleted. 
		   std::unique_ptr<SListNode<T>> & deleteMe = previous->next();
           // Link to the node after the one to be deleted.
		   deleteMe = std::move(deleteMe->next());          
       }
                      
       m_count--;

	   // Return the new iterator position
	   return t_position;       
}

template <typename T, typename InputIterator>
void SLinkedList<T, InputIterator>::makeNewHead(InputIterator t_position)
{
	SListIterator<T> headPositionIt = this->begin();
	swap(headPositionIt, t_position);
}
//Transfers all elements from list t_source into *this. The list container t_source becomes
//empty after the operation.
template<typename T, typename InputIterator>
inline void SLinkedList<T, InputIterator>::splice(InputIterator t_position, std::list<T>& t_source)
{
	for (auto node = t_source.begin(); node != t_source.end(); node++)
	{
		this->insertBefore(t_position, *node);	
	}
	t_source.clear();
}

template <typename T, typename InputIterator>
int SLinkedList<T, InputIterator>::remove(T t_element) 
{
    // Remove all occurrences of element
	SListNode<T> *current = m_head.get();
	SListNode<T> *temp;

	int matches = 0;
	while (current != 0) 
	{
		// if we have found a match
		if (current->element() == t_element) 
		{
			std::cout << "Found a match" << std::endl;
			// Remove the match we have found
			temp = current;
			current = current->next().get();
			SListIterator<T> iterToRemove(temp);
			remove( iterToRemove );
			matches++;
		}
		else 
		{
			current = current->next().get();
		}
	}
	m_count--;
	return matches;
}


template <typename T, typename InputIterator>
SListIterator<T> SLinkedList<T, InputIterator>::last() const 
{
    if (m_tail != nullptr) 
	{
		return SListIterator<T>(m_tail);
	}
	return this->end();	
}


template <typename T, typename InputIterator>
SListNode<T>* SLinkedList<T, InputIterator>::head() const 
{
	return m_head.get();
}

template <typename T, typename InputIterator>
SListNode<T>* SLinkedList<T, InputIterator>::tail() const 
{
	return m_tail;
}

template <typename T, typename InputIterator>
SListIterator<T> SLinkedList<T, InputIterator>::begin() const 
{
    SListIterator<T> startIterator(m_head.get());
    return startIterator;    
}

template <typename T, typename InputIterator>
SListIterator<T> SLinkedList<T, InputIterator>::end() const 
{
	// Return a "one past the end" iterator  
	SListNode<T> *temp = nullptr;

	SListIterator<T> endIterator(temp);
	return endIterator;
}


