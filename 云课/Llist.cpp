#include <iostream>
#include <list>
using namespace std;
int main()
{
	list<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_front(0);//放在开头
	//同时 还有pop_back（）和pop_front（）
	//list 是双向的 因此插入和删除的时间复杂度都是O（1） 而查找的时间复杂度是O(n)，频繁使用查找和随机访问，更适合使用vector或deque
	//size()返回链表元素个数 empty（）检查是否为空 clear（）清空
	//front()返回链表第一个元素的引用 back（）同理
	//begin（）指向第一个元素的迭代器 end()指向最后一个元素的下一个位置的迭代器
	//insert()在指定位置插入一个若干个元素
	//同样的 也存在erase()
	//++begin() begin（）不会自增 只是拷贝得到一个数
	list<int> ll;
	for (int i = 0; i < 5; ++i)
	{
		ll.push_back(i);
	}
	reverse(ll.begin(), ll.end());
	ll.insert(++ll.begin(), 99);//注意这里的begin（）并没有自增 也就是实现了在第一个元素后面的位置加进去了99这个元素
	ll.erase(++++ll.begin(), --ll.end());//这里实现了删去第3到倒数第二个元素 注意是【 ，）
	cout << (int)ll.size() << endl;//同之前讲的一样 size（）返回的是一个unsigned int 所以常常需要将其强制类型转换为int








	return 0;
}