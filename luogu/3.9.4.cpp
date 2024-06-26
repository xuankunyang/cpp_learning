#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
const int N21 = 1e6 + 5;
int ls[N21], rs[N21];
int dfs9(int x)
{
	if (x == 0)return 0;
	if (ls[x] == 0&&rs[x]==0)return 1;
	return max(dfs9(ls[x]), dfs9(rs[x])) + 1;
}



int main()
{
	ios::sync_with_stdio, cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> ls[i] >> rs[i];
	}
	cout << dfs9(1);




	return 0;
}