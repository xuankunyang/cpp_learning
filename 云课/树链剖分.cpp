#include <iostream>
#include <vector>
using namespace std;

NODE nd[1000];
//������Ҫ���¶���һ�µ�
struct NODE
{
	int fa;
	int in, out;
	int son;//ָ�����ض���
	int top;//���������׽ڵ���
	int dep;
	int size;//������С
};

int lca(int x, int y)
{
	while (nd[x].top != nd[y].top)
	{
		if (nd[nd[x].top].dep < nd[nd[y].top].dep)swap(x, y);
		x = nd[nd[x].top].fa;
	}
	return nd[x].dep > nd[y].dep ? y : x;
}


int main()
{
	//��Ҫ�������ʷ�
	//����ʹ���ض���������ǰ�������������һ����
	//�ض���ָĳ�ڵ�����ж������������Ķ��ӣ�������ѡһ����������Ϊ�����
	//
	// �����ʷַ�Ϊ����dfs����
	// ��Ԥ����dfs1
	// �ʷ�dfs2���������ף�dfs�����ȶ��ض��ӽ���dfs���Ա�֤dfs�������ٶ����������dfs
	// 
	// �������ָ�����׽ڵ�����
	// 
	//


	return 0;
}