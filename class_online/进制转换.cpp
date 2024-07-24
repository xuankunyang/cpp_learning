#include<iostream>
#include <vector>
using namespace std;
int main()
{
	//假设已经给了一个数组来表示一个k进制的整数要将其转换为十进制（当k大于10时已经将字母转换为对应的数字）
	int a[] = { 1,3,10,5,7 };
	int x = 0, n = 5,k = 11;
	for (int i = 0; i < n; ++i)
	{
		x = x * k + a[i];
	}
	//将十进制转换为任意进制
	int y,cnt=0,kk=2;
	cin >> y;
	vector<int>b;
	while (y)
	{
		b[++cnt] = y % kk;
		y /= kk;
	}
	reverse(b.begin()+1, b.begin() + 1 + cnt);






	return 0;
}