#include <iostream>
#include<algorithm>
#include <vector>
using namespace std;
int main()
{
	//对象：数组或容器，前提：单调 默认单增
	//binary_search 返回bool 位置 low_bound upper_bound
	vector<int>numbers = { 1,3,5,7,9 };
	int target = 5;
	bool found = binary_search(numbers.begin(), numbers.end(), target);//起始 末尾 目标
	//low_bound 前提 非降序（否则 自定义）返回【st，ed）第一个    大于等于   x的元素的地址  同样的 upper_bound返回的是第一个  大于  元素的地址
	//如果不存在，返回最后一个元素的下一个位置 vector中就是end() 
	vector<int> v = { 1,5,7,3,10,18,9 };
	sort(v.begin(), v.begin());
	cout << (lower_bound(v.begin(), v.end(), 8) - v.begin()) << endl;//下标
	vector<int> u = { 1,2,3,8,8,8,9,10,15 };//low_bound ->第一个8 upper_bound-> 最后一个8的下一位  ，当然这是只有一“群”8的时候的情况

	


	








	return 0;
}
