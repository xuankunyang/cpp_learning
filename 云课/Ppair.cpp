#include<iostream>
#include <algorithm>
#include <utility>
#include <string>
#include <vector>
using namespace std;
int main()
{
	pair<int, string> pa(3, "Mike");
	//构造函数 有两个参数 根据前面<>里的类型来
	cout << pa.first << " " << pa.second << endl;//两个成员 first second
	//pair可以嵌套
	pair<int, pair<int, string>>pp(3, make_pair(4, "what"));//注意这里要调用make函数 也就是返回一个对应类型的pair
	//pair自带的排序规则是按照first成员进行升序排序，若相同，再按照second进行降序排序 也意味着 可以直接用sort对pair数组进行排序
	vector<pair<int, int>> point;
	point.push_back(make_pair(3, 2));
	point.push_back(make_pair(1, 4));
	point.push_back(make_pair(2, 1));//push_back() 赋值
	sort(point.begin(), point.end());
	for (auto& p : point)
	{
		cout << p.first << " " << p.second << endl;
	}
	return 0;
}