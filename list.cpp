#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/*
*	if the mem is a pointer to a object and the object is created in heap.

*	the node_st should have a destruct function to release the heap memory

*	if the type defined in class ,we can use it by added "classname::".

*	by addition , the type should have a public property.
*/

class mylist
{
public:
	typedef struct node_st
	{
		int mem;
		struct node_st *next;
	}NODE, *PNODE;

public:

	mylist(PNODE phead = NULL) :
		m_phead(phead) {}
	void add(int num);
	void del(int num);
	void free();
	void print();
	//reserse
	NODE *reverse(NODE *p);
	NODE *get() { return m_phead; }
	~mylist()
	{
		free();
	}
private:
	PNODE m_phead;

};

void mylist::print()
{
	if (!m_phead)
	{
		std::cout << "list is null" << std::endl;
		return;
	}
	for (PNODE pnode_temp = m_phead; pnode_temp; pnode_temp = pnode_temp->next)
	{
		std::cout << pnode_temp->mem << std::endl;
	}

}

void mylist::del(int num)
{
	if (!m_phead) return;

	PNODE pnode_p = m_phead;
	PNODE pnode_temp = m_phead->next;

	while (pnode_temp)
	{
		PNODE pnode_t = pnode_temp->next;
		if (pnode_temp->mem == num)
		{
			delete pnode_temp;
			pnode_temp = pnode_t;
			pnode_p->next = pnode_t;
			continue;
		}
		pnode_temp = pnode_temp->next;
		pnode_p = pnode_p->next;
	}

	if (m_phead->mem == num)
	{
		pnode_temp = m_phead->next;
		delete m_phead;
		m_phead = pnode_temp;
	}
}

void mylist::add(int num)
{
	PNODE pnode_temp = m_phead;
	PNODE pnode_p = NULL;
	for (; pnode_temp; pnode_temp = pnode_temp->next)
	{
		pnode_p = pnode_temp;
	}
	pnode_temp = new NODE;
	pnode_temp->mem = num;
	pnode_temp->next = NULL;

	if (!pnode_p)
	{
		m_phead = pnode_temp;
		return;
	}

	pnode_p->next = pnode_temp;
}

void mylist::free()
{
	PNODE pnode_d = m_phead;
	while (pnode_d)
	{
		PNODE pnode_temp = pnode_d->next;
		delete pnode_d;
		pnode_d = pnode_temp;
	}
	m_phead = NULL;
}

mylist::NODE *mylist::reverse(NODE* p)
{
	if (p == NULL || p->next == NULL)
		return p;
	NODE *newHead = reverse(p->next);
	p->next->next = p;
	p->next = NULL;
	m_phead = newHead;
	return newHead;
}

void test()
{
	int num;
	mylist list;
	srand(time(NULL));
	for (int i = 0; i < 5; i++)
	{
		num = rand() % 10;
		list.add(num);
		printf("%d ", num);
	}
	puts("\n------------------------");
	list.print();
	puts("\n------------------------reverse:");
	list.reverse(list.get());
	list.print();
	puts("please input num to delete:");
	std::cin >> num;
	list.del(num);
	puts("------------------------");
	list.print();
}

int main()
{
	test();
	system("pause");
	return 0;
}
