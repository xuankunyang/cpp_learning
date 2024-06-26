#include <iostream>
#include <queue>
#include <cmath>
#include <utility>

using namespace std;

int main()
{
	int n,x,y;
	ios::sync_with_stdio, cin.tie(0), cout.tie(0);
	cin >> n;
	int m = pow(2, n);
	queue<pair<int, int>>q;
	for (int i = 1; i <= m; ++i)
	{
		cin >> x;
		q.push({ x,i });
	}
	while (q.size() != 2)
	{
		auto a = q.front();
		q.pop();
		auto b = q.front();
		q.pop();
		if (a.first > b.first)
			q.push(a);
		else q.push(b);
	}
	auto a = q.front();
	q.pop();
	auto b = q.front();
	q.pop();
	if (a.first > b.first)
		cout << b.second;
	else cout << a.second;

	return 0;
}