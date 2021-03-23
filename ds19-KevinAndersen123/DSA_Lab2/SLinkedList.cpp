#include <iostream>
#include "SLinkedList.h"
#include <list>

int main() 
{
	SLinkedList<int, SListIterator<int>> list;	
	list.insertLast(20); 
	list.insertLast(10);
	list.insertLast(5);

	SListIterator<int> start = list.begin();
	start++;
	start++;
	list.insertBefore(start, 15);
	start = list.begin();
	SListIterator<int> it;
	for (it = list.begin(); it != list.end(); ++it)
	{
		std::cout << *it << std::endl;
	}
	list.reverse();
	for (it = list.begin(); it != list.end(); ++it)
	{
		std::cout << *it << std::endl;
	}
	start = list.begin();
	start++;
	start++;
	list.makeNewHead(start);
	for (it = list.begin(); it != list.end(); ++it)
	{
		std::cout << *it << std::endl;
	}
	std::list<int> spliceListQ4 = { 1,2,3,4,5 };
	list.splice(start, spliceListQ4);
	for (it = list.begin(); it != list.end(); ++it)
	{
		std::cout << *it << std::endl;
	}
	std::cout << "-------------------------------------Q5---------------------------------------------" << std::endl;
	//Question 5
	std::list<int> list1;
	std::list<int> dest;

	for (int i = 0; i < 100; i++)
	{
		list1.push_front(rand() % 10 + 1);
	}
	for (auto iterator = list1.begin(); iterator != list1.end(); ++iterator)
	{
		std::cout << *iterator << std::endl;
	}
	dest.begin();
	dest.splice(dest.begin(), list1, ++find(list1.begin(), list1.end(), 5),--find(list1.rbegin(), list1.rend(), 10).base());
	dest.reverse();

	std::cout << "-----------------------------------------------------------------------------------" << std::endl;
	for (auto iterator = dest.begin(); iterator != dest.end(); ++iterator)
	{
		std::cout << *iterator << std::endl;
	}
	
	system("PAUSE");
}
