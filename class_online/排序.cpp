#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool cmp(const int& u, const int& v)
{
	return u > v;
}
int main()
{
	//sortʱ�临�Ӷ�O (nlogn)
	int a[100];
	int n;
	cin >> n;
	for (int i = 0; i < 100; ++i)
	{
		cin >> a[i];
	}
	sort(a, a + n+1);//��ʼ��ַ��������ַ����һλ  *�ȽϺ��� �ɲ�д Ĭ��������     ��1��n+1��
	vector<int>v = { 5,1,3,9,11 };
	sort(v.begin(), v.end());
	sort(v.begin(), v.end(),cmp);//���������������ʵ�ֽ������� ��Ϊ���� ����ֵӦΪbool
	sort(v.begin(), v.end(), [](const int& u, const int& v)//��������
		{
			return u > v;
		});//ע�� ���ŵ��÷�









	return 0;
}