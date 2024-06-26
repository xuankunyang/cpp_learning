#include<iostream>
#include <iomanip>
#include "priority_queue.h"
using namespace std;

int main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n,m,gender,t,numa=0,numb=0;
	priority_queue<int>a, b;
	cin >> n;
	int* len = new int[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> len[i];
	}
	cin >> m;
	for (int i = 0; i < m; ++i)
	{
		cin >> gender>>t;
		if (gender == 1)
		{
			a.push(t);
			numa++;
		}
		else 
		{
			b.push(t);
			numb++;
		}
	}
	int  now =0;
	long long wait1 = 0, wait2 = 0;
	int i = 0;
	while (i<n-1)
	{
		if (a.empty() || b.empty())break;
		while (a.size()&&b.size()&&a.front() <=now&& b.front() <= now)
		{
			int x, y;
			a.pop(x);
			b.pop(y);
			wait1 += (now-x);
			wait2 += (now-y);
		}
		now += len[i++];
	}
	while (a.size())
	{
		int x;
		a.pop(x);
		wait1 += (now - x);
	}
	while (b.size())
	{
		int x;
		b.pop(x);
		wait2 += (now - x);
	}
	double x = (double)wait1 / (double)numa, y = (double)wait2 / (double)numb;
	cout<<fixed << setprecision(2) << x << " " << y << endl;
	
	


	return 0;
}