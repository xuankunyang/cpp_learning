#pragma once
class outofbound{};

template <class elemtype>
class linkList;

template <class elemtype>
class node
{
	friend class linkList<elemtype>;
private:
	elemtype data;
	node* next;
public:
	node() :next(nullptr) {};
	node(const elemtype& e, node<elemtype>* n = nullptr)
	{
		data = e;
		next = n;
	}
};

template <class elemtype>
class linkList
{
private:
	node<elemtype>* head;
public:
	linkList()
	{
		head = new node<elemtype>();
	}
	bool empty()const 
	{
		if (head->next == nullptr)return 1;
		return 0;
	}
	size_t length()
	{
		size_t len = 0;
		node<elemtype>* p = head->next;
		while (p)
		{
			len++;
			p = p->next;
		}
		return len;
	}
	elemtype get(int i) const;
	{
		if (i < 1)throw outofbound{};
		node<elemtype>* p = head->next;
		while (p && (--i))
		{
			p = p->next;
		}
		if (p)return p->data;
		throw outofbound{};
	}
	int find(const elemtype& e)const 
	{
		int i = 1;
		node<elemtype>* p = head->next;
		while (p)
		{
			if (p->data == e)return i;
			p = p->next;
			i++;
		}
		return 0;
	}
	void insert(int i, const elemtype& e)//在第i个元素之前插
	{
		if (i < 1)throw outofbound{};
		node<elemtype>* p = head, * tmp;
		while (p && (--i))
		{
			p = p->next;
		}
		if (!p)return;
		tmp = new node<elemtype>(e, p->next);
		p->next = tmp;
	}
	remove(int i,elemtype& e)
	{
		if (i < 1)throw outofbound{};
		node <elemtype>* p = head, *tmp;
		while (p && (--i))
		{
			p = p->next;
		}
		if (!p)return;
		if (!p->next)return;
		tmp = p->next;
		e = tmp->data;
		p->next = tmp->next;
		delete tmp;
	}
	void clear()
	{
		node <elemtype>* p, * q;
		p = head->next;
		head->next = nullptr;
		while (p)
		{
			q = p->next;
			delete p;
			p = q;
		}
	}
	~linkList()
	{
		clear();
		delete head;
	}
	void reverse()
	{
		node<elemtype>* p, * q;
		p = head->next;
		head->next = nullptr;
		while (p)
		{
			q = p->next;
			p->next=head->next;
			head->next = p;//首席插入
			p = q;
		}
		
	}


};