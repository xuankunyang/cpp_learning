#include <iostream>
#include <algorithm>
#include <cctype>
#include <vector>
using namespace std;
int main()
{
	//��Сдת��
	char ch='a';
	if (islower(ch))
		cout << "Сд" << endl;
	if (isupper(ch))
		cout << "��д" << endl;
	char s = tolower(ch);//תΪСд������Сд�������в���
	char ss = toupper(ch);
	//ȫ����
	vector <int> num = { 1,3,4,2 };
	sort(num.begin(), num.end());
	//next_permutation() �������ɵ�ǰ���е���һ�����У�����  �ֵ���  ���������������������һ�����У��򽫵�ǰ���и���Ϊ��һ�����У�������true������Ѿ������һ���������и�Ϊ��һ����������false
	//ע��ǰ������
	do
	{
		for (int i : num)
			cout << i << " ";
	} while (next_permutation(num.begin(), num.end()));
	cout << endl;
	//�෴�� prev_permutation ���ɵ�����һ������ �����ֵ������� ���� Ӧ���ǽ��� 






	return 0;
}