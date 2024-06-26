#include <iostream>
using namespace std;
const int NN = 1e6 + 9;
int a[NN];
bool vis[NN];
int n;
void dfs(int dep)
{
	if (dep == n+1)
	{
		for (int i = 1; i <= n; ++i)
		{
			cout << a[i] << " ";
		}
		cout << endl;
		return;
	}
	for (int i = 1; i <= n; ++i)
	{
		//排除不合法路径
		if (vis[i])continue;//vis[i]用来记录i是否已经被使用过
		//修改状态
		vis[i]=true;
		a[dep] = i;
		//下一层
		dfs(dep + 1);
		//恢复现场
		vis[i] = false;
	}
}
int main()
{
	//求1~n的全排列
	cin >> n;
	dfs(1);




	return 0;
}