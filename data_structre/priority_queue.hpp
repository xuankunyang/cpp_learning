#pragma once

template <class elemtype>
struct greater1
{
	bool operator()(const elemtype& a, const elemtype& b)
	{
		return a > b;
	}
};
template <class elemtype>
struct less1
{
	bool operator()(const elemtype& a, const elemtype& b)
	{
		return a < b;
	}
};


template <class elemtype,class compare=less1<elemtype>>
class priority_queue
{
private:
	elemtype* arr;
	int len;
	int maxsize;
	compare com;
	void doublespace()
	{
		elemtype* tmp = new elemtype[maxsize * 2];
		for (int i = 0; i < maxsize; ++i)
		{
			tmp[i] = arr[i];
		}
		maxsize *= 2;
		delete[]arr;
		arr = tmp;
	}
	void swap(elemtype& a, elemtype& b)
	{
		elemtype tmp = a;
		a = b;
		b = tmp;
	}
public:
	priority_queue(int inisize = 100)
	{
		maxsize = inisize;
		len = 0;
		arr = new elemtype[maxsize];
	}
	bool empty()
	{
		return len == 0;
	}
	int size()
	{
		return len;
	}
	void push(const elemtype& e)
	{
		if (len == maxsize - 1)doublespace();
		arr[++len] = e;
		int pos = len;
		while (pos >1&& com(arr[pos], arr[pos / 2]))
		{
			swap(arr[pos], arr[pos / 2]);
			pos /= 2;
		}
	}
	void pop()
	{
		swap(arr[1], arr[len]);
		len--;
		int pos = 1;
		while (pos <= len)
		{
			int child1 = pos * 2, child2 = pos * 2 + 1;
			if (child1 <= len && child2 <= len)
			{
				if (com(arr[child1], arr[child2]))
				{
					if (com(arr[child1], arr[pos]))
					{
						swap(arr[child1], arr[pos]);
						pos = child1;
					}
					else break;
				}
				else
				{
					if (com(arr[child2], arr[pos]))
					{
						swap(arr[child2], arr[pos]);
						pos = child2;
					}
					else break;
				}
			}
			else if (child1 <= len && com(arr[child1], arr[pos]))
			{
				swap(arr[child1], arr[pos]);
				pos = child1;
			}
			else break;
		}
	}
	void pop(elemtype& e)
	{
		e = arr[1];
		swap(arr[1], arr[len]);
		len--;
		int pos = 1;
		while (pos <= len)
		{
			int child1 = pos * 2, child2 = pos * 2 + 1;
			if (child1 <= len && child2 <= len)
			{
				if (com(arr[child1], arr[child2]))
				{
					if (com(arr[child1], arr[pos]))
					{
						swap(arr[child1], arr[pos]);
						pos = child1;
					}
					else break;
				}
				else
				{
					if (com(arr[child2], arr[pos]))
					{
						swap(arr[child2], arr[pos]);
						pos = child2;
					}
					else break;
				}
			}
			else if (child1 <= len && com(arr[child1], arr[pos]))
			{
				swap(arr[child1], arr[pos]);
				pos = child1;
			}
			else break;
		}
	}
	elemtype front()
	{
		return arr[1];
	}
	~priority_queue()
	{
		delete[]arr;
	}
};