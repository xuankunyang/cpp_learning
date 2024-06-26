#include <iostream>
using namespace std;
int main()
{
	int n,m;
	cin >> n;
	long long* a = new long long[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	cin >> m;
	int lh, rh;
	for (int i = 0; i < n / 2; ++i)
	{
		lh = i, rh = n - 1 - i;
		if (a[lh] + a[rh] == m)
		{
			cout << "Yes";
			return 0;
		}
		else if (a[lh] + a[rh] > m)
		{
			for (int t = rh - 1; t > lh; --t)
			{
				if (a[lh] + a[t] == m)
				{
					cout << "Yes";
					return 0;
				}
				if (a[lh] + a[t] < m)break;
			}
		}
		else
		{
			for (int t = lh + 1; t < rh; ++t)
			{
				if (a[t] + a[rh] == m)
				{
					cout << "Yes";
					return 0;
				}
				if (a[t] + a[rh] > m)break;
			}
		}

	}
	delete[] a;
	cout << "No";


	return 0;
}