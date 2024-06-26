#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

struct node
{
	int parent;
	int left, right;
	int weight;
}a41[105];
int n41;
long long ans41 = 1e9 + 7;
int level41[105];

void bfs19(const int& x)
{
	memset(level41, 0, sizeof level41);
	long long tmp = 0;
	queue<int>q;
	q.push(x);
	while (q.size())
	{
		auto t = q.front();
		q.pop();
		tmp += (a41[t].weight * level41[t]);
		if (a41[t].left && !level41[a41[t].left]&&a41[t].left!=x)
		{
			level41[a41[t].left] = level41[t] + 1;
			q.push(a41[t].left);
		}
		if (a41[t].right &&!level41[a41[t].right]&&a41[t].right!=x)
		{
			level41[a41[t].right] = level41[t] + 1;
			q.push(a41[t].right);
		}
		if (a41[t].parent&&!level41[a41[t].parent]&& a41[t].parent!=x)
		{
			level41[a41[t].parent] = level41[t] + 1;
			q.push(a41[t].parent);
		}
	}
	ans41 = min(ans41, tmp);
}


int main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n41;
	for (int i = 1; i <= n41; ++i)
	{
		cin >> a41[i].weight >> a41[i].left >> a41[i].right;
		a41[a41[i].left].parent = i;
		a41[a41[i].right].parent = i;
	}
	for (int i = 1; i <= n41; ++i)
	{
		bfs19(i);
	}
	cout << ans41;



	return 0;
}
