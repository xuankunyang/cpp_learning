#include<iostream>
#include <queue>
using namespace std;

const int N1 = 100;
int ls[N1], rs[N1];//��Զ�����


//��������� ��-�����-�Ҷ���
void dfs1(int x)
{
	cout << x << " ";
	if (ls[x])dfs1(ls[x]);
	if (rs[x])dfs1(rs[x]);
}
//�������
void dfs2(int x)
{
	if (ls[x])dfs1(ls[x]);
	cout << x << " ";
	if (rs[x])dfs1(rs[x]);
}

//�������
void dfs3(int x)
{
	if (ls[x])dfs1(ls[x]);
	if (rs[x])dfs1(rs[x]);
	cout << x << " ";
}

//�������
void bfs()
{
	queue<int>q;
	q.push(1);
	while (!q.empty())
	{
		int t = q.front();
		q.pop();
		cout << t<<" ";
		if (ls[t])q.push(ls[t]);
		if (rs[t])q.push(rs[t]);
	}


}

//����ֱ��ָ�����������һ���������ܲ�Ψһ
// �˵�u��vΨһȷ����һ��ֱ��
// u��v�б�Ȼ����һ������Ϊ�����Ҷ�ӽڵ�
// ��ֱ�� ������dfs
// 
// �������� ָ���ǽ���ɾ�������ʹʣ����ͨ�ӿ����ֵ��С�ĵ�
// ��mss[x]��ʾx���������������ֵ
// ����1�����ĵ����ɿ�������Сһ��<= n/2
// ����������������е㶼��Ȼ����һ�������ڵ���>n/2
// ����2��һ�����������������ģ���������������ģ����Ȼ����
// ��ɾ���������ĵıߣ�һ���Ữ��Ϊ���ô�С��ͬ����
// ����3���������е㵽ĳ����ľ�����У������ĵľ��������С��
// �����������ģ������һ��
// ���������������С�ĵ�һ��������  �����Ż��ܶ�����
// ����4����������ͨ��һ���������õ�һ���µ������µ������ڽϴ����һ������ӵ���ԭ������֮��ļ�·����
// ��������һ�������ľ����������ӵ�
// �����ģ���һ��dfs
// ���mss<=n/2�Ǿ�������
// 
// void dfs(int x,int fa)
// {
// sz[x]=1,mss[x]=0;//��xΪ����������size����ʼ��mss
// for(const auto& y: g[x])
// {
// if(y==fa)continue;
// dfs(y,x);
// sz[x]+=sz[y];
// mss[x]=max(mss[x],sz[y]);
// }
// mss[x]=max(mss[x],n-sz[x]);//������xΪ�����������֮�������
// if(mss[x]<=n/2)ans.push_back(x);
// }
// 
// 
//



int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> ls[i] >> rs[i];
	}
	dfs1(1);
	cout << endl;
	dfs2(1);
	cout << endl;
	dfs3(1);
	cout << endl;
	bfs();



	return 0;
}