#include<iostream>
#include <queue>
using namespace std;

const int N1 = 100;
int ls[N1], rs[N1];//针对二叉树


//先序遍历， 根-左儿子-右儿子
void dfs1(int x)
{
	cout << x << " ";
	if (ls[x])dfs1(ls[x]);
	if (rs[x])dfs1(rs[x]);
}
//中序遍历
void dfs2(int x)
{
	if (ls[x])dfs1(ls[x]);
	cout << x << " ";
	if (rs[x])dfs1(rs[x]);
}

//后序遍历
void dfs3(int x)
{
	if (ls[x])dfs1(ls[x]);
	if (rs[x])dfs1(rs[x]);
	cout << x << " ";
}

//层序遍历
void bfs()
{
	queue<int>q;
	q.push(1);
	while (!q.empty())
	{
		int t = q.front();
		q.pop();
		cout << t<<" ";
		if (ls[t])q.push(ls[t]);
		if (rs[t])q.push(rs[t]);
	}


}

//树的直径指的是树上最长的一条链，可能不唯一
// 端点u，v唯一确定了一个直径
// u，v中必然存在一个点作为最深的叶子节点
// 求直径 跑两遍dfs
// 
// 树的重心 指的是将其删除后可以使剩余联通子块最大值最小的点
// 用mss[x]表示x点所有子树的最大值
// 性质1：重心的若干棵子树大小一定<= n/2
// 除了重心以外的所有点都必然存在一棵子树节点数>n/2
// 性质2：一棵树至多有两个重心，如果存在两个重心，则必然相邻
// 若删除连接重心的边，一定会划分为两棵大小相同的树
// 性质3：树中所有点到某个点的距离和中，到重心的距离和是最小的
// 若有两个重心，距离和一样
// 反过来，距离和最小的点一定是重心  可以优化很多问题
// 性质4：把两棵树通过一条边相连得到一棵新的树，新的重心在较大的树一侧的连接点与原来重心之间的简单路径上
// 若两棵树一样大，重心就是两个连接点
// 求重心：跑一遍dfs
// 如果mss<=n/2那就是重心
// 
// void dfs(int x,int fa)
// {
// sz[x]=1,mss[x]=0;//以x为根的子树的size，初始化mss
// for(const auto& y: g[x])
// {
// if(y==fa)continue;
// dfs(y,x);
// sz[x]+=sz[y];
// mss[x]=max(mss[x],sz[y]);
// }
// mss[x]=max(mss[x],n-sz[x]);//除了以x为根的这个子树之外的子树
// if(mss[x]<=n/2)ans.push_back(x);
// }
// 
// 
//



int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> ls[i] >> rs[i];
	}
	dfs1(1);
	cout << endl;
	dfs2(1);
	cout << endl;
	dfs3(1);
	cout << endl;
	bfs();



	return 0;
}