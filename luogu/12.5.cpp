#include <iostream>
using namespace std;
struct position
{
	int x, y;
};
int forward(int**,const int ,position&);
int main()
{//还没有结束。。。。
	int n;
	cin >> n;
	int** p = new int* [n];
	for (int i = 0; i < n; ++i)
	{
		p[i] = new int[n];//明明讲过的动态二维数组申请，我却像在预习
	}
	for (int i = 0; i < n; ++i)
	{
		for (int t = 0; t < n; ++t)
			p[i][t] = 0;
	}
	int x, y, val;
	cin >> y >> x >> val;
	while (x || y ||val)
	{
		p[x][y] = val;
		cin >> y >> x >> val;//带break标志的输入，这样做是比较合理的
	}
	position po;
	po.x = 1;
	po.y = 1;
	int sum = 0,f=forward(p,n,po);
	while ( f!= -1)//注意这里不要把函数直接写在判断的地方，引用会把主值改变了！！！
	{
		sum += f;
		f=forward(p, n, po);
	}
	po.x = 1;
	po.y = 1;
	while (forward(p, n, po) != -1)
	{
		sum += forward(p, n, po);
	}
	cout << sum;

	for (int i = 0; i < n; ++i)
	{
		delete[] p[i];
	}
	delete p;

	return 0;
}
int forward(int** p,const int n,position&po)
{
	if (po.x >= n && po.y >= n)return -1;
	int get = 0;
	if (po.x == n)
	{
		get = p[po.x - 1][po.y];
		po.y = po.y + 1;
		p[po.x - 1][po.y] = 0;
	}
	else if (po.y == n)
	{
		get = p[po.x ][po.y-1];
		po.x = po.x + 1;
		p[po.x][po.y-1] = 0;
	}
	else
	{
		get = p[po.x - 1][po.y] > p[po.x][po.y - 1] ? p[po.x - 1][po.y] : p[po.x][po.y - 1];
		po.x = p[po.x - 1][po.y] > p[po.x][po.y - 1] ? po.x : po.x + 1;
		po.y = p[po.x - 1][po.y] > p[po.x][po.y - 1] ? po.y + 1 : po.y;
		p[po.x - 1][po.y] = p[po.x - 1][po.y] > p[po.x][po.y - 1] ? 0 : p[po.x - 1][po.y];
		p[po.x][po.y - 1] = p[po.x - 1][po.y] > p[po.x][po.y - 1] ? p[po.x][po.y - 1] : 0;
	}
	return get;
}