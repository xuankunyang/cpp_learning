#include <iostream>
using namespace std;
const int NN = 1e6 + 9;
int a[NN];
bool vis[NN];
int n;
void dfs(int dep)
{
	if (dep == n+1)
	{
		for (int i = 1; i <= n; ++i)
		{
			cout << a[i] << " ";
		}
		cout << endl;
		return;
	}
	for (int i = 1; i <= n; ++i)
	{
		//�ų����Ϸ�·��
		if (vis[i])continue;//vis[i]������¼i�Ƿ��Ѿ���ʹ�ù�
		//�޸�״̬
		vis[i]=true;
		a[dep] = i;
		//��һ��
		dfs(dep + 1);
		//�ָ��ֳ�
		vis[i] = false;
	}
}
int main()
{
	//��1~n��ȫ����
	cin >> n;
	dfs(1);




	return 0;
}