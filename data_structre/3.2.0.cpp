#include <iostream>
using namespace std;
int main()
{
	int n;
	ios::sync_with_stdio, cin.tie(0), cout.tie(0);
	cin >> n;
	int* h = new int[n + 1];
	int* prefix = new int[n + 1];
	prefix[0] = 0;
	for (int i = 1; i <= n; ++i)
	{
		
		cin >> h[i];
		prefix[i] = prefix[i - 1] + h[i];
	}
	int max = -1e5;
	for (int i = 0; i <= n; ++i)
	{
		max = prefix[i] > max ? prefix[i] : max;
	}
	cout << max;
	delete[]h;
	delete[]prefix;

	return 0;
}