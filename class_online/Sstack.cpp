#include <iostream>
#include <stack>
using namespace std;
int main()
{
	//����ȳ�  stack ���ܱ���
	//push(x) ����
	//pop()����
	//top()ջ��Ԫ��
	//tip����һ������Ԫ��һ�η���ջ��������ȡ������ʵ�ַ�ת
	stack<int> mystack;
	mystack.push(19);
	mystack.push(12);
	mystack.push(11);
	mystack.push(10);
	cout << "ջ��Ԫ��:" << mystack.top() << endl;
	//����:
	mystack.pop();
	cout << "ջ��Ԫ�ر�Ϊ��" << mystack.top() << endl;
	cout << "�Ƿ�Ϊ��:" << mystack.empty() << endl;







	return 0;
}