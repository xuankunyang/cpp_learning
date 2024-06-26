#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
//https://blog.csdn.net/qq_41555192/article/details/82532458这篇里面关于输入字符串时的空格问题总结的好
int main()
{
	int n;
	cin>>n;
	char** a = new char*[n];
	for (int i = 0; i < n; ++i)
	{
		a[i] = new char[9];//个人感觉会有更优化的数组申请方式
	}
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	int size = 0;
	for (int i = 0; i < n; ++i)
	{
		size += strlen(a[i]);//计算加起来的长度
	}
	char* result = new char[size];
	for (int i = 0; i < size; i++)
	{
		result[i] = '0';
	}
	char *temp=new char[size];//用于储存待比较的数据
	for (int i = 0; i < size; ++i)
	{
		temp[i] = '\0';//相当于初始化
	}
	int* xulie = new int[n];
	for (int i = 0; i < n; ++i)
		xulie[i] = i;//刚刚这里整成i+1去了，导致后面数组越界！！
	do//好像dowhile好久没用了
	{
		for (int i = 0; i < n; ++i)
		{//拼接函数
			strcat_s(temp,strlen(temp)+strlen(a[xulie[i]])+1, a[xulie[i]]);
		}
		if (strcmp(temp, result) > 0)//字符串的“比大小”
		{
			strcpy_s(result, strlen(temp) + 1, temp);//储存当前的最大值
		}	//https://blog.csdn.net/leowinbow/article/details/82380252这一篇csdn有详细介绍
		for (int i = 0; i < size; ++i)
		{
			temp[i] = '\0';//相当于归零
		}
	} while (next_permutation(xulie, xulie + n));//这个相当于不断生成下标的全排列，也就是各个字符串不同的排列方式
	//https://blog.csdn.net/KYJL888/article/details/85069557全排列算法
	cout<<result;
	for (int i = 0; i < n; ++i)
	{
		delete[] a[i];
	}
	delete[] a;
	delete[] xulie;
	delete[] result;
	delete[] temp;
	return 0;
}