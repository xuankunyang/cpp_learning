#include <iostream>
using namespace std;
//康托尔表
//其实这就是找规律的游戏，斜着看，奇数列和偶数列，分子分母升序降序情况不一样
int main5()
{
	long long n,m=0,i=1,t=1;
	cin >> n;
	//说实话，感觉这里用两个while会好看一些
	for (;; ++i)
	{
		while (t <= i)
		{
			m++;
			if (m == n)
				goto FLAG;
			t++;
		}
		t = 1;
	}
FLAG://哈哈哈，老师说不能用goto，但这题里面就很好用   :-)
	//后面奇偶数分开讨论就好了
	if (i % 2 == 0)
		cout << t << '/' << i - t + 1;
	else
		cout << i - t + 1 << '/' << t;
	return 0;
}