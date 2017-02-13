#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef struct tag_node
{
	int mem;
	struct tag_node *next;
}NODE, *PNODE;

class linkedlist
{
public:

	linkedlist(PNODE phead = NULL) :
		m_phead(phead) {}
	void insert(int num);
	//del需要拆分
	void del(int num);
	void free();
	void print();
	NODE *search(int key);
	void delnode(NODE* p);
	//reserse
	NODE *reverse(NODE *p);
	//其它方法逆序
	NODE *reverse_(NODE *p);
	//暂时使用选择排序
	NODE *sort();
	NODE *get() { return m_phead; }
	~linkedlist()
	{
		free();
	}
private:
	PNODE m_phead;

};

NODE *linkedlist::search(int key)
{
	for (NODE *p = m_phead; p; p = p->next)
		if (p->mem == key)
			return p;
	return NULL;
}

void linkedlist::delnode(NODE* p)
{
	NODE ** pnext;
	for (pnext = &m_phead; *pnext; pnext = &(*pnext)->next)
	{
		if (*pnext == p)
		{
			*pnext = p->next;
			delete p;
			break;
		}
	}
}

void linkedlist::print()
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

void linkedlist::del(int num)
{
	NODE* p = NULL;
	while (p = search(num))
	{
		delnode(p);
	}
}

void linkedlist::insert(int num)
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

void linkedlist::free()
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

NODE *linkedlist::reverse(NODE* p)
{
	if (p == NULL || p->next == NULL)
		return p;
	NODE *newHead = reverse(p->next);
	p->next->next = p;
	p->next = NULL;
	m_phead = newHead;
	return newHead;
}

NODE *linkedlist::reverse_(NODE* p)
{
	//需要判断一下是否为空指针
	if (p == NULL)
		return m_phead;
	//三个节点指针 p1 p2 p3(放在while中)，p1 p2 依次前两个节点
	NODE *p1 = p;
	NODE *p2 = p1->next;
	//第1个节点的next提前赋值
	p1->next = NULL;
	//只需要判断p2来决定是否完成
	while (p2)
	{
		//保存一下p2->next为后面p2的赋值做准备
		NODE *p3 = p2->next;
		//关键代码，将节点的指向逆向
		p2->next = p1;
		//在下一次循环之前要将p1,p2后移一个节点
		p1 = p2;
		p2 = p3;
	}
	//循环结束后p1的指向就是链表头
	m_phead = p1;
	return m_phead;
}

NODE *linkedlist::sort()
{
	NODE *p = m_phead;
	if (p == NULL)
		return m_phead;

	while (p)
	{
		NODE *pMix = p;
		NODE *p1 = pMix->next;
		while (p1)
		{
			if (pMix->mem > p1->mem)
			{
				pMix = p1;
			}
			p1 = p1->next;
		}
		if (pMix != p)
		{
			int mem = p->mem;
			p->mem = pMix->mem;
			pMix->mem = mem;
		}		
		p = p->next;
	}
	return m_phead;
}

void test()
{
	int num;
	linkedlist list;
	srand(time(NULL));
	for (int i = 0; i < 5; i++)
	{
		num = rand() % 10;
		list.insert(num);
		printf("%d ", num);
	}
	puts("\n------------------------");
	list.print();
	puts("\n------------------------reverse:");
	list.reverse(list.get());
	list.reverse_(list.get());
	list.sort();
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
