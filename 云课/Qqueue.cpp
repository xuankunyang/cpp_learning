#include <iostream>
#include <queue>
#include <vector>
#include <functional>
using namespace std;
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//�Ƚ��ȳ�
	//push(x) pop() ���� ����
	//front() back() ����Ԫ��
	//��Ҫ����priority_queue   Ĭ�ϴ����ǰ��(�����) �Զ�����
	//�Զ���������
	//�º�������:
	struct compare
	{
		bool operator()(int a, int b)
		{
			return  a > b;//С����
		}
	};
	priority_queue<int, vector<int>, compare>pp;
	pp.push(1248);
	pp.push(12438);
	//��һ����ֵķ�����
	auto cmp = [](int a, int b)
		{
			return a > b;
		};
	priority_queue<int, vector<int>,decltype(cmp)>pq(cmp);

	//���Ԫ�����ͱȽϼ򵥣�����ֱ��ʹ��greater<T>���޸ıȽϷ�����������Ϊ�������Ч�ģ�
	priority_queue<int, vector<int>, greater<int>>qq;//greater<T>�����ڵ��ĸ�ͷ�ļ���
	//deque˫�˶��� ˫��˫��
	//push_back(x) push_front(x) ���Ƶ�popҲ����ǰ��֮�� 

	

	





	return 0;
}