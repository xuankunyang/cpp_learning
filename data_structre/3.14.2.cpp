#include <iostream>
using namespace std;

int count(int n, int m, int st, int fx)//fx=0 向右走 fx=1向左走
{
	if (n == 1)return 0;//到原点 不用走了 
	int distance = fx ? (n - 1 - st + m - 1) : (st + m - 1);//走过的路程 跟方向有关系
	int newfx;
	if ((distance / (n - 1)) & 1)//奇数趟 改变方向
	{
		if (fx)newfx = 0;
		else newfx = 1;//这里更优化的方式是用异或
	}
	else newfx = fx;//偶数趟 不改变方向
	int newpos = newfx ? (n - 1 - distance % (n - 1)) : distance % (n - 1);//新的位置
	int newst = newfx ? newpos - 1 : newpos;
	int next = count(n - 1, m, newst, newfx);//递推  由n个人 推出n-1个人 最后反向得到n的结果
	return (next >= newpos) ? next + 1 : next;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	cout << 1+count(n, m, 0, 0);

	return 0;
}