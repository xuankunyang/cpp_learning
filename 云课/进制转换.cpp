#include<iostream>
#include <vector>
using namespace std;
int main()
{
	//�����Ѿ�����һ����������ʾһ��k���Ƶ�����Ҫ����ת��Ϊʮ���ƣ���k����10ʱ�Ѿ�����ĸת��Ϊ��Ӧ�����֣�
	int a[] = { 1,3,10,5,7 };
	int x = 0, n = 5,k = 11;
	for (int i = 0; i < n; ++i)
	{
		x = x * k + a[i];
	}
	//��ʮ����ת��Ϊ�������
	int y,cnt=0,kk=2;
	cin >> y;
	vector<int>b;
	while (y)
	{
		b[++cnt] = y % kk;
		y /= kk;
	}
	reverse(b.begin()+1, b.begin() + 1 + cnt);






	return 0;
}