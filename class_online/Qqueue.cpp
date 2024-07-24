#include <iostream>
#include <queue>
#include <vector>
#include <functional>
using namespace std;
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//先进先出
	//push(x) pop() 插入 弹出
	//front() back() 返回元素
	//重要的是priority_queue   默认大的在前面(大根堆) 自动排序
	//自定义升降序
	//仿函数方法:
	struct compare
	{
		bool operator()(int a, int b)
		{
			return  a > b;//小根堆
		}
	};
	priority_queue<int, vector<int>, compare>pp;
	pp.push(1248);
	pp.push(12438);
	//另一种奇怪的方法：
	auto cmp = [](int a, int b)
		{
			return a > b;
		};
	priority_queue<int, vector<int>,decltype(cmp)>pq(cmp);

	//如果元素类型比较简单，可以直接使用greater<T>来修改比较方法（个人认为这是最高效的）
	priority_queue<int, vector<int>, greater<int>>qq;//greater<T>定义在第四个头文件中
	//deque双端队列 双进双出
	//push_back(x) push_front(x) 类似的pop也是有前后之分 

	

	





	return 0;
}