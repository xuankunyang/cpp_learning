#include<iostream>
#include <algorithm>
#include <utility>
#include <string>
#include <vector>
using namespace std;
int main()
{
	pair<int, string> pa(3, "Mike");
	//���캯�� ���������� ����ǰ��<>���������
	cout << pa.first << " " << pa.second << endl;//������Ա first second
	//pair����Ƕ��
	pair<int, pair<int, string>>pp(3, make_pair(4, "what"));//ע������Ҫ����make���� Ҳ���Ƿ���һ����Ӧ���͵�pair
	//pair�Դ�����������ǰ���first��Ա����������������ͬ���ٰ���second���н������� Ҳ��ζ�� ����ֱ����sort��pair�����������
	vector<pair<int, int>> point;
	point.push_back(make_pair(3, 2));
	point.push_back(make_pair(1, 4));
	point.push_back(make_pair(2, 1));//push_back() ��ֵ
	sort(point.begin(), point.end());
	for (auto& p : point)
	{
		cout << p.first << " " << p.second << endl;
	}
	return 0;
}