#include <iostream>
using namespace std;

int count(int n, int m, int st, int fx)//fx=0 ������ fx=1������
{
	if (n == 1)return 0;//��ԭ�� �������� 
	int distance = fx ? (n - 1 - st + m - 1) : (st + m - 1);//�߹���·�� �������й�ϵ
	int newfx;
	if ((distance / (n - 1)) & 1)//������ �ı䷽��
	{
		if (fx)newfx = 0;
		else newfx = 1;//������Ż��ķ�ʽ�������
	}
	else newfx = fx;//ż���� ���ı䷽��
	int newpos = newfx ? (n - 1 - distance % (n - 1)) : distance % (n - 1);//�µ�λ��
	int newst = newfx ? newpos - 1 : newpos;
	int next = count(n - 1, m, newst, newfx);//����  ��n���� �Ƴ�n-1���� �����õ�n�Ľ��
	return (next >= newpos) ? next + 1 : next;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	cout << 1+count(n, m, 0, 0);

	return 0;
}