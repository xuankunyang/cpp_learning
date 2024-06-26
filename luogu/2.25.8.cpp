#include <iostream>
using namespace std;
const int N1 = 41,N2=20;
int a[N2][N1],n[N2],x1[N2],x2[N2];
bool dfs1(int x)
{
	static int t = 1;
	int* dp38 = new int[x + 1];
	for (int i = 0; i <= x; ++i)
	{
		dp38[i] = 0;
	}
	for (int i = 1; i <= n[t]; ++i)
	{
		for (int j = x; j >= a[t][i]; --j)
		{
			dp38[j] =(dp38[j] > dp38[j - a[t][i]] + a[t][i] ? dp38[j] : dp38[j - a[t][i]] + a[t][i]);
		}
	}
	if (dp38[x] == x)
	{
		delete[] dp38;
		return 1;
	}
	delete[] dp38;
	t++;
	return 0;
}

int main()
{
	ios::sync_with_stdio, cin.tie(0), cout.tie(0);
	int nn, x,t=1,sum=0;
	while (cin >> nn >> x)
	{
		n[t] = nn;
		x1[t] = x;
		for (int i = 1; i <= nn; ++i)
		{
			cin >> a[t][i];
			sum += a[t][i];
		}
		x2[t] = sum - x;
		sum = 0;
		t++;

	}
	for (int i = 1; i < t; ++i)
	{
		if (dfs1(x1[i]) || dfs1(x2[i]))cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	


	return 0;
}