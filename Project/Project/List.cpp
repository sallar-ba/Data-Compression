#include "List.h"
template<class ItemType>
List<ItemType>::List()
{
	listptr = 0;
}
template<class ItemType>
List<ItemType>::~List()
{
	NODEPTR p, q;
	if (emptyList()) { exit(0); }
	for (p = listptr, q = p->next; p != 0; p = q, q = p->next) { delete p; }
}
template<class ItemType>
void List<ItemType>::insertAfter(ItemType oldValue, ItemType newValue)
{
	NODEPTR p, q;
	for (p = listptr; p != 0 && p->info != oldValue; p = p->next)
		;
	if (p == 0)
	{
		cout << "ERROR: value sought is not in the list.";
		exit(1);
	}
	q = new node;
	q->info = newValue;
	q->next = p->next;
	p->next = q;
}
template<class ItemType>
ItemType List<ItemType>::emptyList()
{
	return(listptr == 0);
}
template<class ItemType>
void List<ItemType>::push(ItemType newValue)
{
	NODEPTR p;
	p = new node;
	p->info = newValue;
	p->next = listptr;
	listptr = p;
}
template<class ItemType>
void List<ItemType>::deleteItem(ItemType oldValue)
{
	NODEPTR p, q;
	for (q = 0, p = listptr; p != 0 && p->info != oldValue; q = p, p = p->next)
		;
	if (p == 0)
	{
		cout << "ERROR: value sought is not in the list";
		exit(1);
	}
	if (q == 0)
	{
		listptr = p->next;
	}
	else
	{
		q->next = p->next;
	}
	delete p;
}
template<class ItemType>
ItemType List<ItemType>::pop()
{
	NODEPTR p;
	ItemType x;
	if (emptyList())
	{
		cout << "ERROR: the list is empty";
		exit(1);
	}
	p = listptr;
	listptr = p->next;
	x = p->info;
	delete p;
	return x;
}
