#include <iostream>
using namespace std;

template<class elemtype>
class BSTree;

template<class elemtype>
class bstnode
{
	friend class BSTree<elemtype>;
private:
	elemtype data;
	bstnode<elemtype>* left, * right;
public:
	bstnode()
	{
		left = nullptr;
		right = nullptr;
	}
	bstnode(const elemtype& e, bstnode<elemtype>* l = nullptr, bstnode<elemtype>* r = nullptr)
	{
		data = e;
		left = l;
		right = r;
	}
};

template<class elemtype>
class BSTree
{
private:
	bstnode<elemtype>* root;
	elemtype flag;
	elemtype min;
	void insert(bstnode<elemtype>*& r)
	{
		elemtype e;
		cin >> e;
		if (e == flag)return;
		r = new bstnode<elemtype>(e);
		insert(r->left);
		insert(r->right);
	}
	elemtype leftmax(bstnode<elemtype>* r)
	{
		bstnode<elemtype>* child = r->left;
		if (!child)return -2000000;
		while (child->right)
		{
			child = child->right;
		}
		return child->data;
	}
	elemtype rightmin(bstnode<elemtype>* r)
	{
		bstnode<elemtype>* child = r->right;
		if (!child)return 2000000;
		while (child->left)
		{
			child = child->left;
		}
		return child->data;
	}
	elemtype getmin1(bstnode<elemtype>* r)
	{
		elemtype lm = (r->data) - leftmax(r), rm = rightmin(r) - (r->data);
		return lm < rm ? lm :rm;
	}
	void getmin2(bstnode<elemtype>* r)
	{
		if (!r)return;
		elemtype x = getmin1(r);
		min = x < min ? x : min;
		if (r->left)getmin2(r->left);
		if (r->right)getmin2(r->right);
	}
public:
	BSTree(elemtype f)
	{
		root = nullptr;
		flag = f;
		min = 10000;
	}
	void insert()
	{
		insert(root);
	}
	elemtype getmin()
	{
		getmin2(root);
		return min;
	}
};

int main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	BSTree<int>bst(-1);
	bst.insert();
	cout << bst.getmin() << endl;




	return 0;
}