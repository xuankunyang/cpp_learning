#include <iostream>
#include <list>
using namespace std;
int main()
{
	list<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_front(0);//���ڿ�ͷ
	//ͬʱ ����pop_back������pop_front����
	//list ��˫��� ��˲����ɾ����ʱ�临�Ӷȶ���O��1�� �����ҵ�ʱ�临�Ӷ���O(n)��Ƶ��ʹ�ò��Һ�������ʣ����ʺ�ʹ��vector��deque
	//size()��������Ԫ�ظ��� empty��������Ƿ�Ϊ�� clear�������
	//front()���������һ��Ԫ�ص����� back����ͬ��
	//begin����ָ���һ��Ԫ�صĵ����� end()ָ�����һ��Ԫ�ص���һ��λ�õĵ�����
	//insert()��ָ��λ�ò���һ�����ɸ�Ԫ��
	//ͬ���� Ҳ����erase()
	//++begin() begin������������ ֻ�ǿ����õ�һ����
	list<int> ll;
	for (int i = 0; i < 5; ++i)
	{
		ll.push_back(i);
	}
	reverse(ll.begin(), ll.end());
	ll.insert(++ll.begin(), 99);//ע�������begin������û������ Ҳ����ʵ�����ڵ�һ��Ԫ�غ����λ�üӽ�ȥ��99���Ԫ��
	ll.erase(++++ll.begin(), --ll.end());//����ʵ����ɾȥ��3�������ڶ���Ԫ�� ע���ǡ� ����
	cout << (int)ll.size() << endl;//֮ͬǰ����һ�� size�������ص���һ��unsigned int ���Գ�����Ҫ����ǿ������ת��Ϊint








	return 0;
}