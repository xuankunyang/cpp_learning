#include <iostream>
#include <set>
using namespace std;
int main()
{
	//set
	//默认升序排序
	//不允许重复的元素存在 插入重复元素 自动忽略
	// insert(x)  erase(x) find(x)
	//类似的有lower_bound 和 upper_bound
	//修改set比较方法的手段
	set<int, greater<int>>ss;
	ss.insert(1);
	ss.insert(432);
	ss.insert(1249781);
	ss.insert(1278);
	//仿函数方法
	struct mycmp
	{
		bool operator()(const int& a, const int& b)const
		{
			return a > b;
		}
	};
	set<int, mycmp>sss;

	//multiset 允许储存重复元素
	//使用erase（x）的时候会把全部的x删掉
	//若想只删除一个x 那么使用erase和find（返回的是迭代器）
	












	return 0;
}