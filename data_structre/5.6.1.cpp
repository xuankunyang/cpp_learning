#include <iostream>
using namespace std;

int binary_search(int target, int* a, int size)
{
	int lh = 0, rh = size;
	int mid;
	while (lh + 1 != rh)
	{
		mid = (lh + rh) / 2;
		if (target < a[mid])rh = mid;
		else if (target > a[mid])lh = mid;
		else return mid;
	}
	if (target == a[lh])return lh;
	else if (target == a[rh])return rh;
	return -1;
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n,k;
	cin >> n;
	int* a = new int[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	cin >> k;
	int* b = new int[k];
	for (int i = 0; i < k; ++i)
	{
		cin >> b[i];
	}
	
	for (int i = 0; i < k; ++i)
	{
		cout << binary_search(b[i], a, n) << endl;
	}


	return 0;
}