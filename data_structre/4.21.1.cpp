#include <iostream>
#include <cstring>
#include "huffmanpro.h"
using namespace std;

int main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	int* f = new int[n];
	int* a = new int[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> f[i];
		a[i] = i + 1;
	}
	node<int>* bbt = BestBinaryTree<int>(a, f, n);
	char** ch = code<int>(bbt, n);
	long long ans = 0;
	for (int i = 0; i < n; ++i)
	{
		if (ch[i] != nullptr)
		{
			ans += f[i] * strlen(ch[i]);
		}
	}
	cout << ans;

	delete[]f;
	delete[]a;
	delete[]ch;





	return 0;
}