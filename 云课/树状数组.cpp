#include <iostream>
using namespace std;

int lowbit(int x)
{
	return x & -x;
}

int main()
{
	//一边修改一边查询 动态求区间和
	//实现对区间的单点修改和区间查询
	//t[i]存储以i为结尾，且区间大小为lowbit(i)的区间和
	//找到需修改的区间 ：3+lowbit(3)=4 4+lowbit(4)=8......
	//查询[1-k]区间和：7-lowbit(7)=6,6-lowbit(6)=4 4-lowbit(4)=0 区间和=t[7]+t[6]+t[4]
	// update(int k ,int x)
	// {
	// for(int i=k;i<=n;i+=lowbit(i))
	// t[i]+=x;
	// }
	// getprefix(int k)
	// {
	// int res=0;
	// for(int i=k;i>0;i-=lowbit(i)) //注意这里i必须大于零 不然会一直重复
	// res+=t[i];
	// return res;
	// }
	//
	//



	return 0;
}