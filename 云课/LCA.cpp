#include <iostream>


using namespace std;

int main()
{
	//要求lca需要先求出每个点的深度，用dfs解决
	//求完深度后，朴素的lca(x,y)的方法是 不妨设x为更深的节点，让x不断往上爬，直到dep[x]==dep[y]
	//如果x=y就直接返回，否则x，y一起往上走 直到相等
	//倍增求lca
	//定义fa[i][j]表示i节点往上走2^j到达的节点
	//fa[x][i]=fa[fa[x][i-1]][i-1]
	//用dfs求出fa数组
	//void dfs(int x,int p)
	// {
	// dep[x]=dep[p]+1;
	// fa[x][0]=p;//初始化
	// for(int i=1;i<=20;++i)
	//    fa[x][i]=fa[fa[x][i-1]][i-1];//递推 //这里其实需要判断 dep[x]-2^i>=1因为这样才有效
	// for(const auto &y:g[x])
	// {
	// if(y==p)continue;
	// dfs(y,x);
	// }
	// }
	// 具体在查询的时候 假设x深度更深 那么从大到小枚举i ->0 最后x会跳到和y一样深
	// 接着两个一起往上跳， 也是从小到大 ，通过二进制的性质，当两个fa不相等的时侯跳，不断逼近lca，最终会跳到 lca的儿子
	// 
	// 
	//


	return 0;
}