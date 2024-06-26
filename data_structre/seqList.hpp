#pragma once
#include <iostream>
#define initsize 100
using namespace std;
class illegalsize{};
class outofbound{};

template <class elemtype>
class seqList
{
private:
	elemtype* data;
	int len;
	int maxsize;
	void doublespace()
	{
		elemtype* tmp = new elemtype[2 * maxsize];
		if (!tmp)throw illegalsize();
		for (int i = 1; i <= len; ++i)
		{
			tmp[i] = data[i];
		}
		delete[]data;
		data = tmp;
		maxsize = maxsize * 2 - 1;
	}
public:
	seqList(int size = initsize)
	{
		data = new elemtype[size];
		if (!data)throw illegalsize();
		maxsize = size - 1;//0�±�λ�ò���Ԫ�أ����ڲ���ʱ��Ϊ�ڱ�λ
		len = 0;
	}
	bool empty()const
	{
		return len == 0;
	}
	int size()const
	{
		return len;
	}
	elemtype get(int x)const
	{
		if (x<1 || x>len)throw outofbound();
		return data[x];
	}
	int find(const elemtype& e)const//�����ڸ�Ԫ�أ����ظ�Ԫ�ص�λ�ã�û���򷵻�0
	{
		int i;
		data[0] = e;
		for (i = len; i >= 0; --i)
		{
			if (data[i] == e)break;
		}
		return i;
	}
	void insert(int i, const elemtype& e)
	{
		if (i<1 || i>len + 1)return;
		if (len == maxsize)doublespace();
		for (int j = len + 1; j > i; --i)
		{
			data[j] = data[j - 1];
		}
		data[i] = e;
		len++;
	}
	void push_back(const elemtype& e)
	{
		if (len == maxsize)doublespace();
		data[++len] = e;
		data;
	}
	void remove(int i, elemtype& e)//ɾ��������e��
	{
		if (i<1 || i>len)return;
		e = data[i];
		for (int j = i; j < len; ++j)
		{
			data[j] = data[j + 1];
		}
		len--;
		return;
	}
	void clear()
	{
		len = 0;
	}
	~seqList()
	{
		delete[] data;
	}
	elemtype operator[](int i)const
	{
		return data[i];
	}
	
};



