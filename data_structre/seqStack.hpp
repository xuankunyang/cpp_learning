#pragma once
class illegalsize1{};
class outofbound1{};

template <class elemtype>
class seqStack
{
private:
	elemtype* arr;
	int Top;
	int maxsize;
	void doublespace()
	{
		elemtype* tmp = new elemtype[maxsize * 2];
		if (!tmp)throw illegalsize1{};
		for (int i = 0; i <= Top; ++i)
		{
			tmp[i] = arr[i];
		}
		delete[]arr;
		arr = tmp;
		maxsize *= 2;
	}
public:
	seqStack(int initsize=100)
	{
		maxsize = initsize;
		arr = new elemtype[maxsize];
		if (!arr)throw illegalsize1{};
		Top = -1;
	}
	elemtype top()
	{
		if (empty())throw outofbound1{};
		return arr[Top];
	}
	bool empty()
	{
		return Top == -1;
	}
	bool full()
	{
		return Top == maxsize - 1;
	}
	void push(const elemtype& e)
	{
		if (full())doublespace();
		arr[++Top] = e;
	}
	void pop()
	{
		if (empty())throw outofbound1{};
		Top--;
	}
	~seqStack()
	{
		delete[]arr;
	}
};