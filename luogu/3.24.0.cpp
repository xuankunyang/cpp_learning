#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
using ll = long long;

const int N30 = 1e5 + 5;
int n30, m30;
vector<int>edge30[N30];
int cnt30 = 0;
int inpoint30[N30];

struct node
{
	int data;
	int fa;
	int son;
	int top;
	int in, out;
	int size;
	int dep;
}nd30[N30];

void dfs30(int x, int fa)
{
	nd30[x].dep = nd30[fa].dep + 1;
	nd30[x].size = 1;
	nd30[x].fa = fa;
	for (const auto& i : edge30[x])
	{
		if (i == fa)continue;
		dfs30(i, x);
		nd30[x].size += nd30[i].size;
	}
}
void dfs31(int x, int top)
{
	nd30[x].in = ++cnt30;
	inpoint30[cnt30] = x;
	nd30[x].top = top;
	int s = 0;
	for (const int& i : edge30[x])
	{
		if (i == nd30[x].fa)continue;
		if (nd30[i].size > s)
		{
			nd30[x].son = i;
			s = nd30[i].size;
		}
	}
	if(nd30[x].son)
		dfs31(nd30[x].son, top);
	for (const int& i : edge30[x])
	{
		if (i == nd30[x].fa)continue;
		if (i == nd30[x].son)continue;
		dfs31(i, i);
	}
	nd30[x].out = cnt30;
}
void changeroot(int x)
{
	dfs30(x, 0);
	dfs31(x, x);
	cnt30 = 0;
}

void modpath()
{
	int x, y;
	int add;
	cin >> x >> y >> add;
	while (nd30[x].top != nd30[y].top)
	{
		if (nd30[nd30[x].top].dep < nd30[nd30[y].top].dep)
			swap(x, y);
		for (int i = nd30[nd30[x].top].in; i <= nd30[x].in; ++i)
		{
			nd30[inpoint30[i]].data += add;
		}
		x = nd30[nd30[x].top].fa;
	}
	if (nd30[x].dep < nd30[y].dep)swap(x, y);
	for (int i = nd30[y].in; i <= nd30[x].in; ++i)
	{
		nd30[inpoint30[i]].data += add;
	}
}
void sumpath()
{
	int x, y;
	ll ans = 0;
	cin >> x >> y;
	while (nd30[x].top != nd30[y].top)
	{
		if (nd30[nd30[x].top].dep < nd30[nd30[y].top].dep)
			swap(x, y);
		for (int i = nd30[nd30[x].top].in; i <= nd30[x].in; ++i)
		{
			ans+=nd30[inpoint30[i]].data;
		}
		x = nd30[nd30[x].top].fa;
	}
	if (nd30[x].dep < nd30[y].dep)swap(x, y);
	for (int i = nd30[y].in; i <= nd30[x].in; ++i)
	{
		ans+=nd30[inpoint30[i]].data;
	}
	cout << ans << endl;
}

void modson()
{
	int x;
	int add;
	cin >> x >> add;
	for (int i = nd30[x].in; i <= nd30[x].out; ++i)
	{
		nd30[inpoint30[i]].data += add;
	}
}

void sumson()
{
	int x;
	ll ans=0;
	cin >> x;
	for (int i = nd30[x].in; i <= nd30[x].out; ++i)
	{
		ans+= nd30[inpoint30[i]].data;
	}
	cout << ans << endl;
}

int main()
{
	ios::sync_with_stdio, cin.tie(0), cout.tie(0);
	cin >> n30;
	for (int i = 1; i <= n30; ++i)
	{
		cin >> nd30[i].data;
	}
	int x;
	for (int i = 2; i <= n30; ++i)
	{
		cin >> x;
		nd30[i].fa = x;
		edge30[x].push_back(i);
		edge30[i].push_back(x);
	}
	nd30[0].dep = 0;
	changeroot(1);
	cin >> m30;
	int a;
	for (int i = 1; i <= m30; ++i)
	{
		cin >> x;
		switch (x)
		{
		case 1:
			cin >> a;
			changeroot(a);
			break;
		case 2: modpath(); break;
		case 3: modson(); break;
		case 4: sumpath(); break;
		case 5: sumson();
		}
	}
	return 0;
}

//#include <iostream>
//#include <cstring>
//
//using namespace std;
//
//typedef long long LL;
//
//const int N = 1e5 + 10, M = N << 1;
//
//int n, m;
//int h[N], w[N], e[M], ne[M], idx; //建树
//int id[N], nw[N], cnt; //id:节点的dfn序编号，nw[id[i]]是i的权值w（w -> nw的映射）
//int dep[N], sz[N], top[N], fa[N], son[N];
////sz:子树节点个数，top:重链的顶点，son:重儿子，fa:父节点
//struct SegmentTree
//{
//	int l, r;
//	LL sum, flag;
//}tr[N << 2];
//
//void add(int a, int b)
//{
//	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
//}
////dfs1预处理
//void dfs1(int u, int father, int depth)
//{
//	dep[u] = depth, fa[u] = father, sz[u] = 1;
//	for (int i = h[u]; ~i; i = ne[i])
//	{
//		int j = e[i];
//		if (j == father) continue;
//		dfs1(j, u, depth + 1);
//		sz[u] += sz[j];
//		if (sz[son[u]] < sz[j]) son[u] = j; //重儿子是子树节点最多的儿子
//	}
//}
////dfs2做剖分（t是重链的顶点）
//void dfs2(int u, int t)
//{
//	id[u] = ++cnt, nw[cnt] = w[u], top[u] = t;
//	if (!son[u]) return; //叶节点结束
//	dfs2(son[u], t); //重儿子重链剖分
//	//处理轻儿子
//	for (int i = h[u]; ~i; i = ne[i])
//	{
//		int j = e[i];
//		if (j == fa[u] || j == son[u]) continue;
//		dfs2(j, j); //轻儿子的重链顶点就是他自己
//	}
//}
//
////------------------------线段树的部分------------------------\\
//
//void pushup(int u)
//{
//	tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
//}
//
//void pushdown(int u)
//{
//	auto& root = tr[u], & left = tr[u << 1], & right = tr[u << 1 | 1];
//	if (root.flag)
//	{
//		left.sum += root.flag * (left.r - left.l + 1);
//		left.flag += root.flag;
//		right.sum += root.flag * (right.r - right.l + 1);
//		right.flag += root.flag;
//		root.flag = 0;
//	}
//}
//
//void build(int u, int l, int r)
//{
//	tr[u] = { l, r, nw[r], 0 };
//	if (l == r) return;
//	int mid = l + r >> 1;
//	build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
//	pushup(u);
//}
//
//void update(int u, int l, int r, int k)
//{
//	if (l <= tr[u].l && r >= tr[u].r)
//	{
//		tr[u].flag += k;
//		tr[u].sum += k * (tr[u].r - tr[u].l + 1);
//		return;
//	}
//	pushdown(u);
//	int mid = tr[u].l + tr[u].r >> 1;
//	if (l <= mid) update(u << 1, l, r, k);
//	if (r > mid) update(u << 1 | 1, l, r, k);
//	pushup(u);
//}
//
//LL query(int u, int l, int r)
//{
//	if (l <= tr[u].l && r >= tr[u].r) return tr[u].sum;
//	pushdown(u);
//	int mid = tr[u].l + tr[u].r >> 1;
//	LL res = 0;
//	if (l <= mid) res += query(u << 1, l, r);
//	if (r > mid) res += query(u << 1 | 1, l, r);
//	return res;
//}
//
////------------------------线段树的部分------------------------\\
//
//void update_path(int u, int v, int k)
//{
//	while (top[u] != top[v])    //向上爬找到相同重链
//	{
//		if (dep[top[u]] < dep[top[v]]) swap(u, v);
//		update(1, id[top[u]], id[u], k);    //dfs序原因，上面节点的id必然小于下面节点的id
//		u = fa[top[u]];
//	}
//	if (dep[u] < dep[v]) swap(u, v);
//	update(1, id[v], id[u], k); //在同一重链中，处理剩余区间
//}
//LL query_path(int u, int v)
//{
//	LL res = 0;
//	while (top[u] != top[v])    //向上爬找到相同重链
//	{
//		if (dep[top[u]] < dep[top[v]]) swap(u, v);
//		res += query(1, id[top[u]], id[u]);
//		u = fa[top[u]];
//	}
//	if (dep[u] < dep[v]) swap(u, v);
//	res += query(1, id[v], id[u]);  //在同一重链中，处理剩余区间
//	return res;
//}
//void update_tree(int u, int k) //子树全部加上k
//{
//	update(1, id[u], id[u] + sz[u] - 1, k); //由于dfs序的原因，可以利用子树节点个数直接找到区间
//}
//LL query_tree(int u)
//{
//	return query(1, id[u], id[u] + sz[u] - 1); //原因同上
//}
//
//int main()
//{
//	scanf("%d", &n);
//	memset(h, -1, sizeof h);
//	for (int i = 1; i <= n; i++) scanf("%d", &w[i]);
//	for (int i = 1; i < n; i++)
//	{
//		int a, b;
//		scanf("%d%d", &a, &b);
//		add(a, b), add(b, a);
//	}
//	dfs1(1, -1, 1);
//	dfs2(1, 1);
//	build(1, 1, n);
//	scanf("%d", &m);
//	while (m--)
//	{
//		int t, u, v, k;
//		scanf("%d%d", &t, &u);
//		if (t == 1)
//		{
//			scanf("%d%d", &v, &k);
//			update_path(u, v, k);
//		}
//		else if (t == 2)
//		{
//			scanf("%d", &k);
//			update_tree(u, k);
//		}
//		else if (t == 3)
//		{
//			scanf("%d", &v);
//			printf("%lld\n", query_path(u, v));
//		}
//		else printf("%lld\n", query_tree(u));
//	}
//	return 0;
//}
//
//作者：一只野生彩色铅笔
//链接：https ://www.acwing.com/solution/content/62664/
//来源：AcWing
//著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。