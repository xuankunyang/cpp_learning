#include <iostream>
#include <set>
using namespace std;
int main()
{
	//set
	//Ĭ����������
	//�������ظ���Ԫ�ش��� �����ظ�Ԫ�� �Զ�����
	// insert(x)  erase(x) find(x)
	//���Ƶ���lower_bound �� upper_bound
	//�޸�set�ȽϷ������ֶ�
	set<int, greater<int>>ss;
	ss.insert(1);
	ss.insert(432);
	ss.insert(1249781);
	ss.insert(1278);
	//�º�������
	struct mycmp
	{
		bool operator()(const int& a, const int& b)const
		{
			return a > b;
		}
	};
	set<int, mycmp>sss;

	//multiset �������ظ�Ԫ��
	//ʹ��erase��x����ʱ����ȫ����xɾ��
	//����ֻɾ��һ��x ��ôʹ��erase��find�����ص��ǵ�������
	












	return 0;
}