#include<iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
	vector<int> v = { 5,1,3,9,11 };
	cout << *max_element(v.begin(), v.end()) << endl;//ע�ⷵ�ص���һ����ַ���ߵ����� ��ʼ��ĩβ ���ص��ǡ�st��ed���е��� ֵ�ĵ�ַ
	vector <int> u = { 5,1,7,3,10,18,9 };
	nth_element(u.begin(), u.begin() + 3, u.end());//��st��k��ed���Ե�k��Ԫ��Ϊ���ģ�ǰ��Ķ�����С������Ķ������󣬵�ǰ���������ڲ���û������ O(n)
	for (auto& i : u)cout << i << ' ' << endl;






	return 0;
}