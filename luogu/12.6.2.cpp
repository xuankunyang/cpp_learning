#include <iostream>
using namespace std;
//�ѵ�̺������ֿ������ṹ�巽����洴������
struct po
{
	int x, y;
};
struct carpet
{
	int zxx, zxy, xl, yl;
};
bool cover(const int&,const carpet*,const po);
int main()
{
	int n;
	cin >> n;
	carpet* ca = new carpet[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> ca[i].zxx >> ca[i].zxy >> ca[i].xl >> ca[i].yl;
	}
	po p;//������жϵĵ������
	cin >> p.x >> p.y;
	int up = 0;
	for (int i = 0; i < n; ++i)
	{
		if (cover(i, ca, p))
			up = i + 1;
	}
	if (up == 0)
		cout << -1;
	else
		cout << up;

	delete[] ca;//�������û��

	return 0;
}
bool cover(const int &no,const carpet*ca,const po p)
{
	if (p.x <= ca[no].zxx+ca[no].xl&&p.x>=ca[no].zxx&&p.y>=ca[no].zxy&&p.y<=ca[no].zxy+ca[no].yl)return true;
//�жϸõ��Ƿ����ڲ�
	else return false;

}