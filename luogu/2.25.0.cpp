#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main()
{
	ll vv, n, c,v,e;
	ios::sync_with_stdio, cin.tie(0), cout.tie(0);
	cin >> vv >> n >> c;
	vector<ll>dp30(c + 1, 0);//�����dpʹ������˼ά ��ʾʹ��i�������ܰ��˵����ľʯ�����
	for (int i = 1; i <= n; ++i)
	{
		cin >> v >> e;
		for (int j = c; j>=e; --j)
		{
			dp30[j] = max(dp30[j], dp30[j - e]+v);
		}

	}
	for (int i = 1; i <= c; ++i)
	{
		if (dp30[i] >=vv)
		{
			cout << c - i << endl;
			return 0;
		}
	}
	cout << "Impossiple" << endl;
	return 0;
}