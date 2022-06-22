#pragma once
#include<iostream>
using namespace std;
template<class ItemType>
class List
{
protected:
	struct node
	{
		ItemType info;
		struct node* next;
	};
	typedef struct node* NODEPTR;
	NODEPTR listptr;
public:
	List();
	~List();
	ItemType emptyList();
	void insertAfter(ItemType, ItemType);
	void deleteItem(ItemType);
	void push(ItemType);
	ItemType pop();
};
