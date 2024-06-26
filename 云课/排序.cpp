#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool cmp(const int& u, const int& v)
{
	return u > v;
}
int main()
{
	//sort时间复杂度O (nlogn)
	int a[100];
	int n;
	cin >> n;
	for (int i = 0; i < 100; ++i)
	{
		cin >> a[i];
	}
	sort(a, a + n+1);//起始地址，结束地址的下一位  *比较函数 可不写 默认用升序     【1，n+1）
	vector<int>v = { 5,1,3,9,11 };
	sort(v.begin(), v.end());
	sort(v.begin(), v.end(),cmp);//传入第三个参数，实现降序排列 若为函数 返回值应为bool
	sort(v.begin(), v.end(), [](const int& u, const int& v)//匿名函数
		{
			return u > v;
		});//注意 括号的用法









	return 0;
}