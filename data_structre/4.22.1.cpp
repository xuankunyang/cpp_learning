#include <iostream>
#include "priority_queue.h"
using namespace std;

int main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int a, b, c,x,y;
	long long score = 0;
	cin >> a >> b >> c;
	priority_queue<int, greater1<int>>q;
	q.push(a);
	q.push(b);
	q.push(c);
	while (q.size() > 1)
	{
		x = q.front();
		q.pop();
		y = q.front();
		q.pop();
		score += 1;
		if (x > 1)q.push(x - 1);
		if (y > 1)q.push(y - 1);
	}
	cout << score * 10 << endl;


	return 0;
}