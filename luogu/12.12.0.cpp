#include<iostream>
using namespace std;
struct linknode
{
	unsigned int val;
	linknode* next;
};
linknode* head=new linknode;
void insert();
void search();
void del();
int main()
{
	head->val = 1;
	head->next = nullptr;
	int q;
	cin >> q;
	for (int i = 0; i < q; ++i)
	{
		int op;
		cin >> op;
		switch (op)
		{
		case 1:insert(); break;//靠，，，没有break，楞了半天
		case 2:search(); break;
		case 3:del(); break;
		}
	}
	

	return 0;
}
void insert()
{
	unsigned int x, y;
	cin >> x >> y;
	if (x == 1)
	{
		linknode* temp = new linknode;
		temp->val = y;
		temp->next = nullptr;
		head->next = temp;
		return;
	}
	linknode* p=head;
	while (p)
	{
		if (p->val == x)break;
		p = p->next;
	}
	linknode* temp = p->next;
    p->next=new linknode;
	p = p->next;
	p->val = y;
	p->next = temp;
	p= head;
}
void search()
{
	unsigned int x;
	cin >> x;
	linknode* p = head;
	while (p)
	{
		if (p->val == x)break;
		p = p->next;
	}
	if (p->next == nullptr)cout << 0 << endl;
	else cout << p->next->val << endl;
}
void del()
{
	unsigned x;
	cin >> x;
	linknode* p = head;
	while (p)
	{
		if (p->val == x)break;
		p = p->next;
	}
	linknode* temp = p->next;
	if (temp == nullptr) p = nullptr;
	else p->next = temp->next;
	
}