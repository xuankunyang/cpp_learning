#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
//https://blog.csdn.net/qq_41555192/article/details/82532458��ƪ������������ַ���ʱ�Ŀո������ܽ�ĺ�
int main()
{
	int n;
	cin>>n;
	char** a = new char*[n];
	for (int i = 0; i < n; ++i)
	{
		a[i] = new char[9];//���˸о����и��Ż����������뷽ʽ
	}
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	int size = 0;
	for (int i = 0; i < n; ++i)
	{
		size += strlen(a[i]);//����������ĳ���
	}
	char* result = new char[size];
	for (int i = 0; i < size; i++)
	{
		result[i] = '0';
	}
	char *temp=new char[size];//���ڴ�����Ƚϵ�����
	for (int i = 0; i < size; ++i)
	{
		temp[i] = '\0';//�൱�ڳ�ʼ��
	}
	int* xulie = new int[n];
	for (int i = 0; i < n; ++i)
		xulie[i] = i;//�ո���������i+1ȥ�ˣ����º�������Խ�磡��
	do//����dowhile�þ�û����
	{
		for (int i = 0; i < n; ++i)
		{//ƴ�Ӻ���
			strcat_s(temp,strlen(temp)+strlen(a[xulie[i]])+1, a[xulie[i]]);
		}
		if (strcmp(temp, result) > 0)//�ַ����ġ��ȴ�С��
		{
			strcpy_s(result, strlen(temp) + 1, temp);//���浱ǰ�����ֵ
		}	//https://blog.csdn.net/leowinbow/article/details/82380252��һƪcsdn����ϸ����
		for (int i = 0; i < size; ++i)
		{
			temp[i] = '\0';//�൱�ڹ���
		}
	} while (next_permutation(xulie, xulie + n));//����൱�ڲ��������±��ȫ���У�Ҳ���Ǹ����ַ�����ͬ�����з�ʽ
	//https://blog.csdn.net/KYJL888/article/details/85069557ȫ�����㷨
	cout<<result;
	for (int i = 0; i < n; ++i)
	{
		delete[] a[i];
	}
	delete[] a;
	delete[] xulie;
	delete[] result;
	delete[] temp;
	return 0;
}