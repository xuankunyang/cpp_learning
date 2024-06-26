#pragma once
class outofbound{};

template <class elemtype>
class linkStack;

template <class elemtype>
class node
{
private:
	elemtype data;
	node<elemtype>* next;
public:
	node() :(next = nullptr) {};
	node(const elemtype& e, node<elemtype>* n = nullptr)
	{
		data = e;
		next = n;
	}
};

template <class elemtype>
class linkStack
{
private:
	node <elemtype>* Top;
public:
	linkList()
	{
		Top = nullptr;
	}
	bool empty()
	{
		return Top == nullptr;
	}
	elemtype top()
	{
		if (!Top)throw outofbound{};
		return Top->data;
	}
	void push(const elemtype& e)
	{
		Top = new elemtype(e, Top);
	}
	void pop()
	{
		if (!Top)throw outofbound{};
		node <elemtype>* tmp = Top;
		Top = tmp->next;
		delete tmp;
	}
	~linkStack()
	{
		node <elemtype>* p=Top, * q;
		while (p)
		{
			q = p->next;
			delete p;
			p = q;
		}
	}
	elemtype GetAndRemoveLastElem()
	{
		elemtype t = top();
		pop();
		if (empty())
			return t;
		elemtype res = GetAndRemoveLastElem();
		push(t);
		return res;
	}
	void reverse()
	{
		if (empty())return;
		elemtype a = GetAndRemoveLastElem();
		reverse();
		push(a);
	}

};