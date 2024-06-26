#include <iostream>
#include <cstring>
#include "priority_queue.h"
using namespace std;

int a4[105];

struct elem
{
	long long data, base;
	int primeindex;
	elem(){}
	elem(long long a, long long b, int c)
	{
		data = a;
		base = b;
		primeindex = c;
	}
	friend bool operator<(const elem& a, const elem& b)
	{
		return a.data < b.data || (a.data ==b.data&&a.base*a4[a.primeindex+1]<b.base*a4[b.primeindex+1]);
	}
};

int main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	memset(a4, 10000009, sizeof a4);
	int k, n;
	long long x;
	cin >> k >> n;
	for (int i = 0; i < k; ++i)
	{
		cin >> a4[i];
	}
	bool flag = 1;
	for (int j = k - 1; j > 0; --j)
	{
		flag = 0;
		for (int i = 0; i < j; ++i)
		{
			if (a4[i] > a4[i + 1])
			{
				int tmp = a4[i];
				a4[i] = a4[i + 1];
				a4[i + 1] = tmp;
				flag = 1;
			}
		}
		if (!flag)break;
	}
	if (n == 1)
	{
		cout << a4[0] << endl;
		return 0;
	}
	priority_queue<elem>q;
	elem tmp(a4[0],1,0);
	q.push(tmp);
	long long ans=1;
	while (n)//类似bfs 不过是具有优先性的bfs
	{
		elem top = q.front();
		q.pop();
		if (top.primeindex < k - 1)
		{
			q.push(elem(top.base * a4[top.primeindex + 1], top.base, top.primeindex + 1));
		}
		if (ans != top.data)
		{
			ans = top.data;
			q.push(elem(top.data * a4[0], top.data,0));
			n--;
		}
	}
	cout << ans;

	


	return 0;
}