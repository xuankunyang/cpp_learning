#include <iostream>
#include<algorithm>
#include <vector>
using namespace std;
int main()
{
	//���������������ǰ�᣺���� Ĭ�ϵ���
	//binary_search ����bool λ�� low_bound upper_bound
	vector<int>numbers = { 1,3,5,7,9 };
	int target = 5;
	bool found = binary_search(numbers.begin(), numbers.end(), target);//��ʼ ĩβ Ŀ��
	//low_bound ǰ�� �ǽ��򣨷��� �Զ��壩���ء�st��ed����һ��    ���ڵ���   x��Ԫ�صĵ�ַ  ͬ���� upper_bound���ص��ǵ�һ��  ����  Ԫ�صĵ�ַ
	//��������ڣ��������һ��Ԫ�ص���һ��λ�� vector�о���end() 
	vector<int> v = { 1,5,7,3,10,18,9 };
	sort(v.begin(), v.begin());
	cout << (lower_bound(v.begin(), v.end(), 8) - v.begin()) << endl;//�±�
	vector<int> u = { 1,2,3,8,8,8,9,10,15 };//low_bound ->��һ��8 upper_bound-> ���һ��8����һλ  ����Ȼ����ֻ��һ��Ⱥ��8��ʱ������

	


	








	return 0;
}
