#include <iostream>
#include <map>
using namespace std;
int main()
{
	//���ڴ����ֵ�� �������Ϊ����һһӳ�� ע���ڲ��洢����pair
	//insert({k,v})  ע���Ǵ�����
	//erase(key) �����õ���������
	//count(key)�ж�key�Ƿ����   ����0��1
	//���ƻ���lower_bound��upper_bound
	//multimap����� ɾ��Ԫ�ص�ʱ���multisetһ��
	map<int, string>mymap = { {1,"apple"},{2,"banana"},{3,"orange"} };
	mymap.insert(make_pair(4,"grape"));
	//�ܷ���Ĳ���ֵ�ķ�ʽ��
	cout << "value at key 2:" << mymap[2] << endl;
	//����������Ҳ��pair
	for (const auto& pair : mymap)
	{
		cout << pair.first << " " << pair.second << endl;
	}
	multimap<int, string>mmap = { {1,"apple"},{2,"banana"},{2,"orange"} };
	mmap.insert(make_pair(3, "grape"));
	//���ظ�Ԫ�� �޷�ʹ�����淽��Ĳ��ҷ���
	auto range = mmap.equal_range(2);
	for (auto it = range.first; it != range.second; ++it)//֮ǰ������ itֻ��д!= ��������ָ��
	{
		cout << it->first << " " << it->second << endl;
	}





	return 0;
}