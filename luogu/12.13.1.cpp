#include<iostream>
using namespace std;
bool search(int*,int ,int );
int main()
{
	int n, k;
	cin >> n >> k;
	int* p = new int[k - 1];
	for (int i = 0; i < k - 1 - 1; ++i)
	{
		p[i] = 1;
	}
	int t = 0;
	for (int i = 1; i <= n; ++i)
	{
		if (search(p, n, k))++t;
	}
	cout << t;

	return 0;
}
bool search(int*p,int n,int k)
{
	static int point = 0;
	static int sum = 0;
	for (; point <= k - 1 - 2; ++point)
	{
		sum += p[point];
	}
	sum += p[point + 1];
	if (n - sum>=p[point+1])
	{
		p[point + 2] = n - sum;
		sum -= p[point + 1];
		p[point + 1]++;
		return true;
	}
	else
	{
		sum -= p[point + 1];
		sum -= p[point];
		p[point]++;
		p[point + 1] = p[point];
		return false;
	}
	



}