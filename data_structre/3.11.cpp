#include<iostream>
using namespace std;

int main()
{
	// stack 各种操作时间复杂度都是O（1）
	// doublespace 扩大空间可能会造成O（n）的消耗
	// 均摊之后仍是O（1）
	// 
	// 双共享栈：两个数组相向放置 top分为0，1 bottom也是
	// 
	// 链式栈：空间不连续，在链式结构的基础上少了head节点
	// 
	// 栈的应用： 函数调用，括号匹配，表达式计算问题
	// 前缀，中缀，后缀 表达式 
	// 编译时，编译器首先将中缀表达式转换为后缀表达式，这又是使用stack实现的
	// 只有运算的优先级高于栈顶 才能压入 否则一直弹出直到top优先级低于后者， 注意相同也要弹出
	// 
	// stack也有reverse操作详见 https://www.cnblogs.com/swifthao/p/12776362.html
	//

	return 0;
}