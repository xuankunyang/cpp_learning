#include <iostream>
using namespace std;
int main()
{
	int l, n;
	cin >> l >> n;
	int* p = new int[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> p[i];
	}
	int half = (l+1) / 2;//ע������Ҫ��ż���ۣ���min��ʱ����Ҫ
	//��ʵminֻ��Ҫ���м仮������ߵ������ұߵ����ң��ֱ������ֵ�ͺ���
	int left_max = 0, right_max = l+1;
	if(l%2==1)
	{
		for (int i = 0; i < n; ++i)
		{
			if (p[i] <= half && p[i] > left_max)
				left_max = p[i];
			else if (p[i] >= half && p[i] < right_max)
				right_max = p[i];
		}
	}
	else
	{
		for (int i = 0; i < n; ++i)
		{
			if (p[i] <= half && p[i] > left_max)
				left_max = p[i];
			else if (p[i] > half && p[i] < right_max)
				right_max = p[i];
		}
	}
	int min = left_max > (l + 1 - right_max) ? left_max : l + 1 - right_max;
	cout << min << " ";
	int left = l + 1, right = 0;//������Ҫ��¼���ұߺ�����ߵ�����
	//�����������������С����ײ���⣬����Խ����������
	//��ô��max��������ߵ������ߣ����ұߵ������ߣ�������ֵ
	for (int i = 0; i < n; ++i)
	{
		if (p[i] < left)
			left = p[i];
		if (p[i] > right)
			right = p[i];
	}
	int max = l + 1 - left > right ? l + 1 - left : right;
	cout << max;
	delete[]p;//���������delete
	return 0;
}