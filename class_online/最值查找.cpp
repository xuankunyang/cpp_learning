#include<iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
	vector<int> v = { 5,1,3,9,11 };
	cout << *max_element(v.begin(), v.end()) << endl;//注意返回的是一个地址或者迭代器 起始，末尾 返回的是【st，ed）中的最 值的地址
	vector <int> u = { 5,1,7,3,10,18,9 };
	nth_element(u.begin(), u.begin() + 3, u.end());//（st，k，ed）以第k个元素为中心，前面的都比它小，后面的都比他大，但前后两部分内部并没有排序 O(n)
	for (auto& i : u)cout << i << ' ' << endl;






	return 0;
}