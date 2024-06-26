#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
int n26, d26;
const int N26 = 1e5 + 3;
vector<int>g26[N26];
int dis26[N26];

int bfs14()
{
	int ans = 0;
	queue<int>q;
	q.push(1);
	dis26[1] = 0;
	while (!q.empty())
	{
		auto t = q.front();
		q.pop();
		for (const auto& i : g26[t])
		{
			if (dis26[i] != -1)continue;
			dis26[i] = dis26[t] + 1;
			if (dis26[i] > d26)return ans;
			ans++;
			q.push(i);
		}
	}
	return ans;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int a, b;
	memset(dis26, -1, sizeof dis26);

	cin >> n26 >> d26;
	for (int i = 1; i < n26; ++i)
	{
		cin >> a >> b;
		g26[a].push_back(b);
		g26[b].push_back(a);
	}
	cout<<bfs14();


	return 0;
}