#include <iostream>
using namespace std;
//把地毯和坐标分开创建结构体方便后面创建数组
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
	po p;//输入待判断的点的坐标
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

	delete[] ca;//这回终于没忘

	return 0;
}
bool cover(const int &no,const carpet*ca,const po p)
{
	if (p.x <= ca[no].zxx+ca[no].xl&&p.x>=ca[no].zxx&&p.y>=ca[no].zxy&&p.y<=ca[no].zxy+ca[no].yl)return true;
//判断该店是否在内部
	else return false;

}