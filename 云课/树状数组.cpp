#include <iostream>
using namespace std;

int lowbit(int x)
{
	return x & -x;
}

int main()
{
	//һ���޸�һ�߲�ѯ ��̬�������
	//ʵ�ֶ�����ĵ����޸ĺ������ѯ
	//t[i]�洢��iΪ��β���������СΪlowbit(i)�������
	//�ҵ����޸ĵ����� ��3+lowbit(3)=4 4+lowbit(4)=8......
	//��ѯ[1-k]����ͣ�7-lowbit(7)=6,6-lowbit(6)=4 4-lowbit(4)=0 �����=t[7]+t[6]+t[4]
	// update(int k ,int x)
	// {
	// for(int i=k;i<=n;i+=lowbit(i))
	// t[i]+=x;
	// }
	// getprefix(int k)
	// {
	// int res=0;
	// for(int i=k;i>0;i-=lowbit(i)) //ע������i��������� ��Ȼ��һֱ�ظ�
	// res+=t[i];
	// return res;
	// }
	//
	//



	return 0;
}