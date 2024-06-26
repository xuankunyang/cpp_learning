#include <iostream>
#include "priority_queue.h"
using namespace std;

int main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n,x,y;
	cin >> n;
	priority_queue<int, greater1<int>>q;
	for (int i = 1; i <= n; ++i)
	{
		cin >> x;
		q.push(x);
	}
	while (q.size() > 1)
	{
		x = q.front();
		q.pop();
		y = q.front();
		q.pop();
		if (x != y)
		{
			int t = x - y;
			q.push(t);
		}
	}
	if (q.empty())cout << 0 << endl;
	else cout << q.front();

	return 0;
}