#include <iostream>
using namespace std;
//���ж���
//��ʵ������ҹ��ɵ���Ϸ��б�ſ��������к�ż���У����ӷ�ĸ�����������һ��
int main5()
{
	long long n,m=0,i=1,t=1;
	cin >> n;
	//˵ʵ�����о�����������while��ÿ�һЩ
	for (;; ++i)
	{
		while (t <= i)
		{
			m++;
			if (m == n)
				goto FLAG;
			t++;
		}
		t = 1;
	}
FLAG://����������ʦ˵������goto������������ͺܺ���   :-)
	//������ż���ֿ����۾ͺ���
	if (i % 2 == 0)
		cout << t << '/' << i - t + 1;
	else
		cout << i - t + 1 << '/' << t;
	return 0;
}