#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
int n31, q31;
const int N31 = 1e5 + 5;
struct node
{
	ll data;
	ll ww;
	int fa;
	int son;
	int top;
	int in, out;
	int size;
	int dep;
}nd31[N31];
struct edge
{
	vector<ll>w;
	vector<int>e;
}edge31[N31];
int inpoint31[N31];

void dfs32(int x, int fa)
{
	nd31[x].dep = nd31[fa].dep + 1;
	nd31[x].fa = fa;
	nd31[x].size = 1;
	for (int i=0;i<edge31[x].e.size();++i)
	{
		if (edge31[x].e[i] == fa)continue;
		nd31[edge31[x].e[i]].ww = edge31[x].w[i];
		dfs32(edge31[x].e[i], x);
		nd31[x].size += nd31[edge31[x].e[i]].size;
	}
}

void dfs33(int x, int top)
{
	static int cnt = 0;
	nd31[x].top = top;
	nd31[x].in = ++cnt;
	inpoint31[cnt] = x;
	int s = 0;
	for (const int& i : edge31[x].e)
	{
		if (i == nd31[x].fa)continue;
		if (nd31[i].size > s)
		{
			nd31[x].son = i;
			s = nd31[i].size;
		}
	}
	if(nd31[x].son)
		dfs33(nd31[x].son, top);
	for (const int& i : edge31[x].e)
	{
		if (i == nd31[x].fa)continue;
		if (i == nd31[x].son)continue;
		dfs33(i, i);
	}
	nd31[x].out = cnt;
}

void mod1()
{
	int a, b;
	ll x;
	cin >> a >> b >> x;
	while (nd31[a].top != nd31[b].top)
	{
		if (nd31[nd31[a].top].dep < nd31[nd31[b].top].dep)swap(a, b);
		for (int i = nd31[nd31[a].top].in+1; i <= nd31[a].in; ++i)
		{
			nd31[inpoint31[i]].ww ^= x;
		}
		a = nd31[nd31[a].top].fa;
	}
	if (nd31[a].dep < nd31[b].dep)swap(a, b);
	for (int i = nd31[b].in+1; i <= nd31[a].in; ++i)
	{
		nd31[inpoint31[i]].ww ^= x;
	}
}

void sum1()
{
	int a, b;
	ll ans=0;
	cin >> a >> b ;
	while (nd31[a].top != nd31[b].top)
	{
		if (nd31[nd31[a].top].dep < nd31[nd31[b].top].dep)swap(a, b);
		for (int i = nd31[nd31[a].top].in; i <= nd31[a].in; ++i)
		{
			ans^=nd31[inpoint31[i]].data;
		}
		a = nd31[nd31[a].top].fa;
	}
	if (nd31[a].dep < nd31[b].dep)swap(a, b);
	for (int i = nd31[b].in; i <= nd31[a].in; ++i)
	{
		ans^= nd31[inpoint31[i]].data;
	}
	cout << ans << endl;
}

void mod2()
{
	int a, b;
	ll x;
	cin >> a >> b >> x;
	while (nd31[a].top != nd31[b].top)
	{
		if (nd31[nd31[a].top].dep < nd31[nd31[b].top].dep)swap(a, b);
		for (int i = nd31[nd31[a].top].in; i <= nd31[a].in; ++i)
		{
			nd31[inpoint31[i]].data ^= x;
		}
		a = nd31[nd31[a].top].fa;
	}
	if (nd31[a].dep < nd31[b].dep)swap(a, b);
	for (int i = nd31[b].in; i <= nd31[a].in; ++i)
	{
		nd31[inpoint31[i]].data ^= x;
	}
}

void sum2()
{
	int a;
	cin >> a;
	ll ans=nd31[a].data^nd31[a].ww;
	for (int i = 0; i < edge31[a].e.size(); ++i)
	{
		if (edge31[a].e[i] == nd31[a].fa)continue;
		ans ^= nd31[edge31[a].e[i]].ww;
	}
	cout << ans << endl;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n31 >> q31;
	for (int i = 1; i <= n31; ++i)
	{
		cin >> nd31[i].data;
	}
	int x, y;
	ll z;
	for (int i = 1; i < n31; ++i)
	{
		cin >> x >> y >> z;
		edge31[x].e.push_back(y);
		edge31[y].e.push_back(x);
		edge31[x].w.push_back(z);
		edge31[y].w.push_back(z);
	}
	nd31[0].dep = 0;
	dfs32(1, 0);
	dfs33(1, 1);
	for (int i = 1; i <= q31; ++i)
	{
		cin >> x;
		switch (x)
		{
		case 1: mod1(); break;
		case 2: mod2(); break;
		case 3: sum1(); break;
		case 4: sum2();
		}
	}

	return 0;
}