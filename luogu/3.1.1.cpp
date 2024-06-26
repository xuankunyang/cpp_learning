#include<iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
int n6, A6, B6;
const int N6 = 205;
int k6[N6];
queue<int>q6;
int dist6[N6];

int bfs1()
{
	memset(dist6, -1, sizeof dist6);
	dist6[A6] = 0;
	q6.push(A6);
	while (!q6.empty())
	{
		auto t = q6.front();
		q6.pop();
		if (t == B6)return dist6[t];
		if (t + k6[t] <= n6 && (dist6[t+k6[t]]==-1))
		{
			q6.push(t + k6[t]);
			dist6[t + k6[t]] = dist6[t] + 1;
		}
		if(t-k6[t>0]&& (dist6[t - k6[t]] == -1))
		{
			q6.push(t - k6[t]);
			dist6[t - k6[t]] = dist6[t] + 1;
		}
	}
	return -1;
}


int main()
{
	ios::sync_with_stdio, cin.tie(0), cout.tie(0);
	cin >> n6 >> A6 >> B6;
	for (int i = 1; i <= n6; ++i)
	{
		cin >> k6[i];
	}
	cout<<bfs1();

	return 0;
}