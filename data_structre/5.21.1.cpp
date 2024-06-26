#include <iostream>
#include <cstring>
using namespace std;

template<class elemtype>
struct greater4
{
	bool operator()(const elemtype& a, const elemtype& b)
	{
		return a > b;
	}
};
template<class elemtype, class compare = greater4<elemtype>>
void adjust(elemtype a[], int n, int i, compare cmp)
{
	int child;
	while (true)
	{
		child = 2 * i + 1;
		if (child > n - 1)return;
		if (child + 1 < n)
		{
			if (cmp(a[child + 1], a[child]) || a[child] == a[child + 1])//右孩子优先于左孩子
				child++;
		}
		if (a[i] > a[child])return;
		swap(a[i], a[child]);
		i = child;
	}
}

template <class elemtype, class compare = greater4<elemtype>>
void heapSort(elemtype a[], int n)
{
	compare cmp;
	for (int i = (n - 1) / 2; i >= 0; --i)
	{
		adjust(a, n, i, cmp);
	}//初次建堆的时间复杂度为O(nlog2(n))但是实际可达到O(n)
	for (int j = n - 1; j >= 1; --j)
	{
		swap(a[0], a[j]);
		adjust(a, j, 0, cmp);
	}//遍历调整时间复杂度为O(nlog2(n))
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	int* a = new int[n];
	bool* b = new bool[n];
	memset(b, 0, sizeof b);
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	heapSort(a, n);
	int t = 1;
	long long w = 0, z = 0;
	int lh = 0, rh = n - 1;
	bool evenflag = 0;
	while (t)
	{
		evenflag = 0;
		for (; rh >= 0; --rh)
		{
			if (b[rh])continue;
			if (a[rh] & 1)continue;
			b[rh] = 1;
			w += a[rh];
			evenflag = 1;
			break;
		}
		if (evenflag)
		{
			for (; lh < n; ++lh)
			{
				if (b[lh])continue;
				b[lh] = 1;
				z += a[lh];
				break;
			}
			t++;
		}
		else
		{
			for (; lh < n; ++lh)
			{
				if (b[lh])continue;
				b[lh] = 1;
				z += a[lh];
			}
			break;
		}
		++t;
	}

	if (z > w)cout << "Z";
	else if (z < w)cout << "W";
	else cout << "0";


	return 0;
}