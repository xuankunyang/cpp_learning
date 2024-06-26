#include <iostream>
#include "priority_queue.h"
using namespace std;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n,x,y;
	long long ans = 0;
	cin >> n;
	priority_queue<int>q;
	for (int i = 1; i <= n; ++i)
	{
		cin >> x;
		q.push(x);
	}
	if (n == 0)
	{
		cout << 0;
		return 0;
	}
	else if (n == 1)
	{
		cout << x;
		return 0;
	}
	while (q.size() > 1)
	{
		x = q.front();
		q.pop();
		y = q.front();
		q.pop();
		q.push(x + y);
		ans += (x + y);
	}
	cout << ans;

	return 0;
}