#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <bitset>
using namespace std;
int main()
{
	//memset()������������ ptr��ָ��Ҫ���õ��ڴ���ָ�� value��Ҫ���õ�ֵ��ͨ����һ������ num��Ҫ���õ��ֽ���
	//��ptrָ����ڴ���ǰnum���ֽ�����Ϊvalueֵ������һ��ָ��ptr��ָ�룡����ͨ�����ڳ�ʼ��
	int a[10];
	memset(a, 0, sizeof a);//ע������byteΪ��λ 0 ��-1����ȷ��
	for (int i = 0; i < 10; ++i)
		cout << a[i]<<" ";
	cout << endl;
	memset(a, 1, sizeof a);
	for (int i = 0; i < 10; ++i)
	{
		cout << a[i]<<" ";//��Ϊ����byteΪ��λ,���Կ��ܳ��ִ�����
		cout << bitset<32>(a[i]) << " ";//�鿴������λ ������csdn
	}
	cout << endl;
	// swap(T&a,T&b)�������������ͣ������Լ���������ͽṹ��
	//reverse() ������������ ������ַ ����st��ed���ڵ�Ԫ��˳����з�ת  �����ڸ����͵����� ���� ���� �����  ֻ֧��˫�������
	vector<int> v= {1, 2, 3, 4, 5};
	reverse(v.begin(), v.end());
	for (int i : v)
		cout << i << " ";
	cout << endl;
	//unique() �������������� ������ַ���ߵ�����  ����ȥ�������ظ�Ԫ�� �����ڣ���st��ed������һ��ָ��ȥ�غ�Χ��β������� 
	//���޷���֤���ڣ��Ǿ�����!! ʱ�临�Ӷ�Ϊ O��n��
	vector<int> vv = { 1,1,1,2,2,3,3,3,4,5,5 };
	auto p = unique(vv.begin(), vv.end());//�൱�ں����ظ��ĵ�һ��Ԫ�ص�λ��1
	for (int i : vv)
		cout << i << " ";
	cout << endl;//���ʱ��Ӧ����1��2��3��4��5��1��1��2��3��3��5
	vv.erase(p, vv.end());//����Ҫ���eraseʹ�ðѺ����ظ��Ĳ���ɾȥ
	for (int i : vv)
		cout << i << " ";
	cout << endl;








	return 0;
}