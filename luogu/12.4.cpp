#include <iostream>
using namespace std;
int main()
{
	int l, n;
	cin >> l >> n;
	int* p = new int[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> p[i];
	}
	int half = (l+1) / 2;//注意这里要奇偶讨论，算min的时候需要
	//其实min只需要从中间划开，左边的向左，右边的向右，分别求最大值就好了
	int left_max = 0, right_max = l+1;
	if(l%2==1)
	{
		for (int i = 0; i < n; ++i)
		{
			if (p[i] <= half && p[i] > left_max)
				left_max = p[i];
			else if (p[i] >= half && p[i] < right_max)
				right_max = p[i];
		}
	}
	else
	{
		for (int i = 0; i < n; ++i)
		{
			if (p[i] <= half && p[i] > left_max)
				left_max = p[i];
			else if (p[i] > half && p[i] < right_max)
				right_max = p[i];
		}
	}
	int min = left_max > (l + 1 - right_max) ? left_max : l + 1 - right_max;
	cout << min << " ";
	int left = l + 1, right = 0;//这里是要记录最右边和最左边的坐标
	//精髓在这里！！！类似小球碰撞问题，“穿越法”！！！
	//那么，max就是最左边的往右走，最右边的往左走，求个最大值
	for (int i = 0; i < n; ++i)
	{
		if (p[i] < left)
			left = p[i];
		if (p[i] > right)
			right = p[i];
	}
	int max = l + 1 - left > right ? l + 1 - left : right;
	cout << max;
	delete[]p;//差点又忘了delete
	return 0;
}