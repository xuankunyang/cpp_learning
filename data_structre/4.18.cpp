﻿#include<iostream>
using namespace std;

int main()
{
	//
	// 并查集
	// 存储：顺序存储，树形存储
	// 顺序存储： flag=0为一个等价类
	// flag=1为一个等价类
	// flag=2为一个等价类......
	// 合并：改动flag
	// 并，查均为On
	// 树形存储：
	// 存储parent和data
	// 根节点就是等价类的标签
	// 根节点的parent标记为负的节点数
	// 既表明他为根节点，又能找出节点数量
	// 合并：改变根节点的parent
	// 尽量让个数少的等价类并到个数多的等价类中或者让树矮的往高的并
	// 😔
	// 尽量让树高控制在2，便于查找
	// 
	// 
	// 表达式树
	// 后序遍历得到后缀式
	// 类似利用stack来辅助表达式树的建立
	// 
	// 
	// 查找
	// 
	// 插值查找：
	// 对于均匀的数据，线性查找
	// 分块查找：
	// 数据体量很大，分批载入数组中
	// 
	//



	return 0;
}