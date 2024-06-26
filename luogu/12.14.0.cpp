#include <iostream>
using namespace std;
unsigned long long p[1001] = { 0 };//题目给了n<=1000，开数组记录每一个n的对应的答案
//和递归的思想一样，但更快
void  cal(int);
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cal(i);//从小到大算，这是精髓，因为大数会用到小数的结果
	}
	cout << p[n];
	return 0;
}
void cal(int n)
{
	unsigned long long sum = 0;
	for (int i =1 ; i<=n/2; ++i)
	{
		sum += p[i];//其实就是把前面的方案数全加起来在加上他自己
	}
	p[n]=sum + 1;//+他自己
}