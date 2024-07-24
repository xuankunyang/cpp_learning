#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <bitset>
using namespace std;
int main()
{
	//memset()接受三个参数 ptr：指向要设置的内存块的指针 value：要设置的值，通常是一个整数 num：要设置的字节数
	//将ptr指向的内存块的前num个字节设置为value值，返回一个指向ptr的指针！！！通常用于初始化
	int a[10];
	memset(a, 0, sizeof a);//注意是以byte为单位 0 和-1是正确的
	for (int i = 0; i < 10; ++i)
		cout << a[i]<<" ";
	cout << endl;
	memset(a, 1, sizeof a);
	for (int i = 0; i < 10; ++i)
	{
		cout << a[i]<<" ";//因为是以byte为单位,所以可能出现错误定义
		cout << bitset<32>(a[i]) << " ";//查看二进制位 具体上csdn
	}
	cout << endl;
	// swap(T&a,T&b)可以是任意类型，包括自己创建的类和结构体
	//reverse() 接受两个参数 两个地址 将【st，ed）内的元素顺序进行反转  可用于各类型的容器 数组 向量 链表等  只支持双向迭代器
	vector<int> v= {1, 2, 3, 4, 5};
	reverse(v.begin(), v.end());
	for (int i : v)
		cout << i << " ";
	cout << endl;
	//unique() 接受两个参数， 两个地址或者迭代器  用于去除相邻重复元素 ！相邻！【st，ed）返回一个指向去重后范围的尾后迭代器 
	//若无法保证相邻，那就排序!! 时间复杂度为 O（n）
	vector<int> vv = { 1,1,1,2,2,3,3,3,4,5,5 };
	auto p = unique(vv.begin(), vv.end());//相当于后面重复的第一个元素的位置1
	for (int i : vv)
		cout << i << " ";
	cout << endl;//这个时候应该是1，2，3，4，5，1，1，2，3，3，5
	vv.erase(p, vv.end());//所以要配合erase使用把后面重复的部分删去
	for (int i : vv)
		cout << i << " ";
	cout << endl;








	return 0;
}