#include <iostream>
using namespace std;
unsigned long long p[1001] = { 0 };//��Ŀ����n<=1000���������¼ÿһ��n�Ķ�Ӧ�Ĵ�
//�͵ݹ��˼��һ����������
void  cal(int);
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cal(i);//��С�����㣬���Ǿ��裬��Ϊ�������õ�С���Ľ��
	}
	cout << p[n];
	return 0;
}
void cal(int n)
{
	unsigned long long sum = 0;
	for (int i =1 ; i<=n/2; ++i)
	{
		sum += p[i];//��ʵ���ǰ�ǰ��ķ�����ȫ�������ڼ������Լ�
	}
	p[n]=sum + 1;//+���Լ�
}