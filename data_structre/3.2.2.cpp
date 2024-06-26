#include <iostream>
using  namespace std;
int main()
{
	int n,ans=0;
	ios::sync_with_stdio, cin.tie(0), cout.tie(0);
	cin >> n;
	int* t = new int[n + 1];
	int* pre = new int[n + 1];
	for (int i = 0; i <= n; ++i)
	{
		pre[i] = 0;
	}

	for (int i = 1; i <= n; ++i)
	{
		cin >> t[i];
		if (t[i] > 13)
		{
			cout << "you died";
			return 0;
		}
		if (pre[i - 1] + t[i] > 13)
		{
			ans += 20;
			pre[i] = t[i];
		}

		else pre[i] = pre[i - 1] + t[i];
	}
	
	
	if (pre[n])ans += pre[n];
		cout << ans;
	


	delete[]t;
	delete[]pre;
	return 0;
}