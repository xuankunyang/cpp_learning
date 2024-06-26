#pragma once
#include "seqStack.h"
template <class elemtype>
struct huffmannode
{
	elemtype data;
	int weight;
	int parent;
	int left, right;
};

template <class elemtype>
int minindex(huffmannode<elemtype>bt[], int k, int m)
{
	int min=0;
	int minweight = 1e7 + 9;
	for (int i = m - 1; i > k; --i)
	{
		if (bt[i].parent == 0 && bt[i].weight < minweight)
		{
			min = i;
			minweight = bt[i].weight;
		}
	}
	return min;
}

template <class elemtype>
huffmannode<elemtype>* BestBinaryTree(elemtype a[], int w[], int n)
{
	int m = 2 * n;
	huffmannode<elemtype>* BBTree = new huffmannode<elemtype>[m];
	int min1, min2;
	int i;
	for (int j = 0;j<n; ++j)
	{
		i = m - 1 - j;
		BBTree[i].data = a[j];
		BBTree[i].weight = w[j];
		BBTree[i].parent = 0;
		BBTree[i].left = 0;
		BBTree[i].right = 0;
	}
	i = n - 1;
	while (i)
	{
		min1 = minindex(BBTree, i, m);
		BBTree[min1].parent = i;
		min2 = minindex(BBTree, i, m);
		BBTree[min2].parent = i;
		BBTree[i].parent = 0;
		BBTree[i].left = min1;
		BBTree[i].right = min2;
		BBTree[i].weight = BBTree[min1].weight + BBTree[min2].weight;
		i--;
	}
	return BBTree;
}

template <class elemtype>
char** huffmancode(huffmannode<elemtype>BBTree[], int n)
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