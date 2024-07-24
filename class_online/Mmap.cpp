#include <iostream>
#include <map>
using namespace std;
int main()
{
	//用于储存键值对 可以理解为函数一一映射 注意内部存储的是pair
	//insert({k,v})  注意是大括号
	//erase(key) 或者拿迭代器区间
	//count(key)判断key是否存在   返回0或1
	//类似还有lower_bound和upper_bound
	//multimap多个键 删除元素的时候和multiset一样
	map<int, string>mymap = { {1,"apple"},{2,"banana"},{3,"orange"} };
	mymap.insert(make_pair(4,"grape"));
	//很方便的查找值的方式：
	cout << "value at key 2:" << mymap[2] << endl;
	//遍历的内容也是pair
	for (const auto& pair : mymap)
	{
		cout << pair.first << " " << pair.second << endl;
	}
	multimap<int, string>mmap = { {1,"apple"},{2,"banana"},{2,"orange"} };
	mmap.insert(make_pair(3, "grape"));
	//含重复元素 无法使用上面方便的查找方法
	auto range = mmap.equal_range(2);
	for (auto it = range.first; it != range.second; ++it)//之前讲过了 it只能写!= 且类似于指针
	{
		cout << it->first << " " << it->second << endl;
	}





	return 0;
}