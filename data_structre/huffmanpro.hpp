#pragma once
#include "seqStack.h"
#include "priority_queue.h"
template <class elemtype>
struct node
{
	elemtype data;
	int weight;
	int parent;
	int left, right;
	int index;
};

template<class elemtype>
struct less3
{
	bool operator()(const node<elemtype>& a, const node<elemtype>& b)
	{
		return a.weight < b.weight;
	}
};


template <class elemtype>
node<elemtype>* BestBinaryTree(elemtype a[], int w[], int n)
{
	int m = 2 * n;
	node<elemtype>* BBTree = new node<elemtype>[m];
	priority_queue<node<elemtype>,less3<elemtype>>q;
	int i;
	for (int j = 0; j < n; ++j)
	{
		i = m - 1 - j;
		BBTree[i].data = a[j];
		BBTree[i].weight = w[j];
		BBTree[i].parent = 0;
		BBTree[i].left = 0;
		BBTree[i].right = 0;
		BBTree[i].index = i;
		q.push(BBTree[i]);
	}
	i = n - 1;
	while (q.size()>1)
	{
		node<elemtype> min1, min2;
		q.pop(min1);
		min1.parent = i;
		q.pop(min2);
		min2.parent = i;
		BBTree[i].parent = 0;
		BBTree[i].left = min1.index;
		BBTree[i].right = min2.index;
		BBTree[i].weight = min1.weight + min2.weight;
		q.push(BBTree[i]);
		i--;
	}
	q.pop(BBTree[i]);
	return BBTree;
}

template <class elemtype>
char** code(node<elemtype> *BBTree, int n)
{
	seqStack <char>s;
	char** hfcode;
	hfcode = new char* [n];
	for (int i = 0; i < n; ++i)
	{
		hfcode[i] = new char[n + 1];
	}
	int m = 2 * n;
	if (n == 0)return hfcode;
	if (n == 1)
	{
		hfcode[0][0] = '0';
		hfcode[0][1] = '\0';
		return hfcode;
	}
	int parent, child;
	for (int i = m - 1; i >= n; --i)
	{
		child = i;
		parent = BBTree[child].parent;
		while (parent)
		{
			if (BBTree[parent].left == child)
				s.push('0');
			else s.push('1');
			child = parent;
			parent = BBTree[parent].parent;
		}
		int j = 0;
		while (!s.empty())
		{
			hfcode[m - 1 - i][j] = s.top();
			s.pop();
			j++;
		}
		hfcode[m - 1 - i][j] = '\0';
	}
	return hfcode;
}