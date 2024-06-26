#include <iostream>
using namespace std;
struct position
{
	int x, y;
};
int forward(int**,const int ,position&);
int main()
{//��û�н�����������
	int n;
	cin >> n;
	int** p = new int* [n];
	for (int i = 0; i < n; ++i)
	{
		p[i] = new int[n];//���������Ķ�̬��ά�������룬��ȴ����Ԥϰ
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
		cin >> y >> x >> val;//��break��־�����룬�������ǱȽϺ����
	}
	position po;
	po.x = 1;
	po.y = 1;
	int sum = 0,f=forward(p,n,po);
	while ( f!= -1)//ע�����ﲻҪ�Ѻ���ֱ��д���жϵĵط������û����ֵ�ı��ˣ�����
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