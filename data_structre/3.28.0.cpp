#include <iostream>
#include<cstring>
using namespace std;

template <class elemtype>
class mytree;

template<class elemtype>
class node 
{
	friend class mytree<elemtype>;
private:
	elemtype data;
	node <elemtype>*left, *right;
public:
	node()
	{
		left = nullptr;
		right = nullptr;
	}
	node(const elemtype& e, node <elemtype>* l = nullptr, node<elemtype>* r = nullptr)
	{
		data = e;
		left = l;
		right = r;
	}
};

template <class elemtype>
class mytree
{
private:
	elemtype stopflag1,stopflag2;
	node<elemtype>* root;
public:
	mytree(elemtype flag1,elemtype flag2)
	{
		root = nullptr;
		stopflag1 = flag1;
		stopflag2 = flag2;
	}
	void build(node<elemtype>*& r, elemtype* arr)
	{
		static int index = 0;
		if (arr[index]==stopflag2)return;
		if (arr[index] == stopflag1)
		{
			r = nullptr;
			index++;
			return;
		}
		r = new node<elemtype>(arr[index]);
		index++;
		build(r->left, arr);
		build(r->right, arr);
	}
	void build(elemtype* arr)
	{
		build(root, arr);
	}
	int dfs(node<elemtype>* r)
	{
		int s = 1,ls=0,rs=0;
		if (r->left)ls=dfs(r->left);
		if (r->right) rs = dfs(r->right);
		return ls > rs ? s + ls : s + rs;
	}
	int dfs()
	{
		return dfs(root);
	}
	void clear(node<elemtype>* r)
	{
		if (r->left)clear(r->left);
		if (r->right)clear(r->right);
		delete r;
	}
	~mytree()
	{
		clear(root);
	}
};

const int N3 = 1e5 + 5;
int a3[N3];

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	memset(a3,-2 , sizeof a3);
	int x,i=0;
	while (cin >> x)
	{
		a3[i] = x;
		i++;
	}
	mytree<int>t(-1,-2);
	t.build(a3);
	cout << t.dfs();

	return 0;
}