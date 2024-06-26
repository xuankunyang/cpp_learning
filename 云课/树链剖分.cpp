#include <iostream>
#include <vector>
using namespace std;

NODE nd[1000];
//这里需要重新定义一下点
struct NODE
{
	int fa;
	int in, out;
	int son;//指的是重儿子
	int top;//所属链的首节点编号
	int dep;
	int size;//子树大小
};

int lca(int x, int y)
{
	while (nd[x].top != nd[y].top)
	{
		if (nd[nd[x].top].dep < nd[nd[y].top].dep)swap(x, y);
		x = nd[nd[x].top].fa;
	}
	return nd[x].dep > nd[y].dep ? y : x;
}


int main()
{
	//主要是重链剖分
	//优先使用重儿子延续当前链，轻儿子则另开一条链
	//重儿子指某节点的所有儿子中子树最大的儿子，相等随便选一个，其他均为轻儿子
	//
	// 重链剖分分为两个dfs进行
	// 先预处理dfs1
	// 剖分dfs2：更新链首，dfs序；首先对重儿子进行dfs，以保证dfs连续；再对其他轻儿子dfs
	// 
	// 链的深度指的是首节点的深度
	// 
	//


	return 0;
}