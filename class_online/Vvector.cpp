#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
	vector<vector<int>> p = { {1,2,3,4},{3,4,5,6} };
	//容器大小 ：其实相当于动态数组 自动分配内存空间
	//元素访问： 通过索引访问 从0 开始最后一个是size（）-1 但是注意！！！size（）返回的是一个unsigned int 如果是0 再减一会很大 所以判断的时候要用< size
	//可使用 []和 at（）来访问 at()可防止越界
	//push_back（）在vector末尾添加元素 使用pop_back（）删除末尾的元素 使用insert（）函数在指定位置插入元素 使用erase（）删除指定位置的元素
	//容器大小管理： 可以使用size（）函数获取vector中元素的数量，使用empty（）检查vector是否为空 使用resize（）调整vector的大小 注意 调整大小后 push_back（）从最后的后面加 前面的情况不知
	//迭代器： end（）指向最后一个元素的后一个位置
	// 格式：void push_back(const T& value);
	//pop_back()一定要保证vector非空
	vector<int >v= {10, 20, 30};
	for (auto it = v.begin(); it != v.end(); ++it)//可理解为指针 但注意这里不能写< 因为迭代器之间只有=和！=的关系 +=也不可写 ++前后缀都可以
	{
		cout << *it << " ";
	}
	cout << endl;
	//排序去重 需先排序 直接用sort
	//去重可使用unique（）  注意！！ unique返回的是第一个重复元素的迭代器
	vector<int> vv = { 1,2,3,2,2,4,4,5,4,6 };
	sort(vv.begin(), vv.end());
	auto first = unique(vv.begin(),vv.end());//auto 真的很好用
	vv.erase(first, vv.end());
	vv.insert(vv.begin() + 2, 9);//在下标为2的位置插入一个9
	vv.erase(vv.begin() + 2);//删去下标为2的元素
	//检查是否为空可以使用empty（） 
	vv.clear();//清空向量的元素
	p.clear();




	return 0;
}