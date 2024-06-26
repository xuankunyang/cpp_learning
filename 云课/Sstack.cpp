#include <iostream>
#include <stack>
using namespace std;
int main()
{
	//后进先出  stack 不能遍历
	//push(x) 插入
	//pop()弹出
	//top()栈顶元素
	//tip：将一个数组元素一次放入栈，再依次取出，可实现反转
	stack<int> mystack;
	mystack.push(19);
	mystack.push(12);
	mystack.push(11);
	mystack.push(10);
	cout << "栈顶元素:" << mystack.top() << endl;
	//弹出:
	mystack.pop();
	cout << "栈顶元素变为：" << mystack.top() << endl;
	cout << "是否为空:" << mystack.empty() << endl;







	return 0;
}