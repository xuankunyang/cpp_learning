#include<iostream>
#include <cstring>

using namespace std;

char ch8[10005][1510];
bool hx8[10005];

int main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	memset(hx8, 0, sizeof hx8);
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> ch8[i];
	}
	for (int i = 1; i <= n; ++i)
	{
		if (hx8[i])continue;
		for (int j = i + 1; j <= n; ++j)
		{
			if (hx8[j])continue;
			else if (strcmp(ch8[i], ch8[j])==0)hx8[j] = 1;
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i)
	{
		if (!hx8[i])ans++;
	}
	cout << ans << endl;


	return 0;
}