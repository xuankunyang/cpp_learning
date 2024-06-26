#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
using ll = long long;
int n28, q28;
const int N28 = 1e5 + 5;
vector<int>edge28[N28];
int a28[N28],in28[N28],out28[N28],inpoint28[N28];
bool vis28[N28];

void dfs17(int x)
{
	static int cnt = 0;
	in28[x] = ++cnt;
	inpoint28[cnt] = x;
	for (const int& i : edge28[x])
	{
		dfs17(i);
	}
	out28[x] = cnt;
}

void solve28(int x)
{
	ll ans = 0;
	for (int i = in28[x] ; i <= out28[x]; ++i)
	{
		ans += a28[inpoint28[i]];
	}
	cout << ans << endl;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	memset(vis28, false, sizeof vis28);
	cin >> n28;
	for (int i = 1; i <= n28; ++i)
	{
		cin >> a28[i];
	}
	int x, y;
	for (int i = 1; i < n28; ++i)
	{
		cin >> x >> y;
		edge28[x].push_back(y);
		vis28[y] = 1;
	}
	int root;
	for (int i = 1; i <= n28; ++i)
	{
		if (!vis28[i])
		{
			root = i;
			break;
		}
	}
	dfs17(root);
	cin >> q28;
	for (int i = 1; i <= q28; ++i)
	{
		cin >> x;
		solve28(x);
	}
	


	return 0;
}