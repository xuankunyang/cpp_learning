#include <iostream>
#include <cstring>
using namespace std;

template<class elemtype>
struct greater3
{
	bool operator()(const elemtype& a, const elemtype& b)
	{
		return a > b;
	}
};
template<class elemtype, class compare = greater3<elemtype>>
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

template <class elemtype, class compare = greater3<elemtype>>
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
	int n, limit;
	cin >> n >> limit;
	int* a = new int[n];
	bool* b = new bool[n];
	memset(b, 0, sizeof b);
	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	heapSort<int>(a, n);
	for (int i = 0; i < n; ++i)
	{
		if (b[i])continue;
		for (int j = n - 1; j > i; --j)
		{
			if (b[j])continue;
			if (a[i] + a[j] <= limit)
			{
				ans++;
				b[i] = 1;
				b[j] = 1;
				break;
			}
		}
		if (b[i])continue;
		ans++;
	}
	cout << ans << endl;
	



	return 0;
}