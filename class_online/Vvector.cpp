#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
	vector<vector<int>> p = { {1,2,3,4},{3,4,5,6} };
	//������С ����ʵ�൱�ڶ�̬���� �Զ������ڴ�ռ�
	//Ԫ�ط��ʣ� ͨ���������� ��0 ��ʼ���һ����size����-1 ����ע�⣡����size�������ص���һ��unsigned int �����0 �ټ�һ��ܴ� �����жϵ�ʱ��Ҫ��< size
	//��ʹ�� []�� at���������� at()�ɷ�ֹԽ��
	//push_back������vectorĩβ���Ԫ�� ʹ��pop_back����ɾ��ĩβ��Ԫ�� ʹ��insert����������ָ��λ�ò���Ԫ�� ʹ��erase����ɾ��ָ��λ�õ�Ԫ��
	//������С���� ����ʹ��size����������ȡvector��Ԫ�ص�������ʹ��empty�������vector�Ƿ�Ϊ�� ʹ��resize��������vector�Ĵ�С ע�� ������С�� push_back���������ĺ���� ǰ��������֪
	//�������� end����ָ�����һ��Ԫ�صĺ�һ��λ��
	// ��ʽ��void push_back(const T& value);
	//pop_back()һ��Ҫ��֤vector�ǿ�
	vector<int >v= {10, 20, 30};
	for (auto it = v.begin(); it != v.end(); ++it)//�����Ϊָ�� ��ע�����ﲻ��д< ��Ϊ������֮��ֻ��=�ͣ�=�Ĺ�ϵ +=Ҳ����д ++ǰ��׺������
	{
		cout << *it << " ";
	}
	cout << endl;
	//����ȥ�� �������� ֱ����sort
	//ȥ�ؿ�ʹ��unique����  ע�⣡�� unique���ص��ǵ�һ���ظ�Ԫ�صĵ�����
	vector<int> vv = { 1,2,3,2,2,4,4,5,4,6 };
	sort(vv.begin(), vv.end());
	auto first = unique(vv.begin(),vv.end());//auto ��ĺܺ���
	vv.erase(first, vv.end());
	vv.insert(vv.begin() + 2, 9);//���±�Ϊ2��λ�ò���һ��9
	vv.erase(vv.begin() + 2);//ɾȥ�±�Ϊ2��Ԫ��
	//����Ƿ�Ϊ�տ���ʹ��empty���� 
	vv.clear();//���������Ԫ��
	p.clear();




	return 0;
}