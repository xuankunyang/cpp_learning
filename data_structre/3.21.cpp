#include <iostream>
#include <queue>
#include <stack>
using namespace std;

template <class elemtype>
class BTree;

template <class elemtype>
class node
{
	friend class BTree<elemtype>;
private:elemtype data;
	   node* left, * right;
	   int leftflag, rightflag;
public:
	node()
	{
		left = nullptr, right = nullptr;
		leftflag = 0, rightflag = 0;
	}
	node(const elemtype& e,node* l = nullptr, node* r = nullptr)
	{
		data = e;
		left = l, right = r;
		leftflag = 0, rightflag = 0;
	}
};

template <class elemtype>
class BTree
{
private:
	node<elemtype>* root;
	elemtype stopflag;
	int size(node<elemtype>* t)//	求以t为根节点的子树的大小
	{
		if (!t)return 0;
		return 1 + size(t->left) + size(t->right);
	}
	int height(node<elemtype>* t)//求以t为根节点的子树的高度
	{
		if (!t)return 0;
		int a = height(t->left), b = height(t->right);
		return a > b ? (a + 1) : (b + 1);
	}
	void del(node<elemtype>* t)//删除以t为根节点的子树
	{
		if (!t)return;
		del(t->left);
		del(t->right);
		delete t;
	}
	void preorder(node <elemtype>* t)//子树前序遍历
	{
		if (!t)return;
		cout << t->data << endl;;
		preorder(t->left);
		preorder(t->right);
	}
	void inorder(node<elemtype>* t)//中序遍历
	{
		if (!t)return;
		inorder(t->left);
		cout << t->data << endl;;
		inorder(t->right);
	}
	void postorder(node<elemtype>* t)//后序遍历
	{
		if (!t)return;
		postorder(t->left);
		postorder(t->right);
		cout << t->data << endl;
	}

public:
	BTree()
	{
		root = nullptr;
	}
	void del()
	{
		del(root);
		root = nullptr;
	}
	bool empty()
	{
		return root == nullptr;
	}
	node<elemtype>* getroot()
	{
		return root;
	}
	int height()
	{
		return height(root);
	}
	int size()
	{
		return size(root);
	}
	void preorder()
	{
		preorder(root);
	}
	void preorder_stack()//可以用stack实现
	{
		if (empty())return;//可以方便的找出所有子孙
		stack<node<elemtype>*>s;
		node <elemtype>* p;
		s.push(root);
		while (!s.empty())
		{
			auto t = s.top();
			s.pop();
			cout << t->data;
			if (t->right)s.push(t->right);
			if (t->left)s.push(t->left);
		}
	}
	void inorder()
	{
		inorder(root);
	}

	void inorder_stack()
	{
		if (!root)return;
		stack<node<elemtype>*>s;
		node<elemtype>* p;
		s.push(root);
		p = root;
		while (p->left)
		{
			s.push(p->left);
			p = p->left;
		}
		while (!s.empty())
		{
			p = s.top();
			s.pop();
			cout << p->data;
			if (p->right)
			{
				p = p->right;
				s.push(p);
				while (p->left)
				{
					s.push(p->left);
					p = p->left;
				}
			}
		}
	}

	void inorder_stack_pro()//其实这个算法的底层是嵌套的循环， 2  有左儿子则一直压下去， 2  弹出的时候考虑右孩子
	{
		if (empty())return;
		stack <node<elemtype>*>s1;
		stack <int>s2;
		node<elemtype>* p;
		int flag;
		s1.push(root);
		s2.push(0);
		while (!s1.empty())
		{
			flag = s2.top();
			s2.pop();
			p = s1.top();
			if (flag)
			{
				s1.pop();
				cout << p->data;
				if (!p->right)continue;
				s1.push(p->right);
				s2.push(0);
			}
			else
			{
				s2.push(1);//标记，以便返回输出时考察是否有右孩子,
				if (p->left)//有左孩子压左孩子
				{
					s1.push(p->left);
					s2.push(0);
				}
			}
			
		}
		
	}
	void postorder()
	{
		postorder(root);
	}

	void postorder_stack()//求所有祖先，较为方便，当pop（）==a的时候，stack里面的必定是其祖先
	{
		stack<node<elemtype>*>s1;
		stack<int>s2;
		s1.push(root);
		s2.push(0);
		node<elemtype>* p;
		int flag;
		while (!s1.empty())
		{
			p = s1.top();
			flag = s2.top();
			s2.pop();
			switch (flag)
			{
			case 0:
			{
				s2.push(1);
				if (p->left)
				{
					s1.push(p->left);
					s2.push(0);
				}
				break;
			}
			case 1: 
			{
				s2.push(2);
				if (p->right)
				{
					s1.push(p->right);
					s2.push(0);
				}
				break;
			}
			case 2:
			{
				s1.pop();
				cout << p->data;
			}
			}
			
		}
	}


	void levelorder()//层序遍历
	{
		queue<node<elemtype>*>q;
		q.push(root);
		while (!q.empty())
		{
			auto t = q.front();
			q.pop();
			cout << t->data;
			if (t->left)q.push(t->left);
			if (t->right)q.push(t->right);
		}
	}
	void createBTree(const elemtype& flag)
	{
		queue<node<elemtype>*>q;
		elemtype r, ls, rs;
		node <elemtype>* p, * pl, * pr;
		stopflag = flag;
		cout << "please input the root:" << endl;
		cin >> r;
		if (r == stopflag)
		{
			root = nullptr;
			return;
		}
		root = new node<elemtype>(r);
		q.push(root);
		while (!q.empty())
		{
			p = q.front();
			q.pop();
			cout << "please input the left and right son of" << p->data << "using" << flag << "as no child";
			cin >> ls >> rs;
			if (ls != flag)
			{
				pl = new node<elemtype>(ls);
				p->left=pl;
				q.push(pl);
			}
			if (rs != flag)
			{
				pr = new node<elemtype>(rs);
				p->right = pr;
				q.push(pr);
			}
		}
		
	}
	node<elemtype>* buildBTree_by_pre_in(elemtype pre[], int pl, int pr, elemtype mid[], int ml, int mr)
	{
		node <elemtype>* p, * leftroot, * rightroot;
		int i, pos, num;
		int lpl, lpr, lml, lmr;
		int rpl, rpr, rml, rmr;
		if (pl > pr)return nullptr;
		p = new node<elemtype>(pre[pl]);
		if (!root)root = p;
		for (i= ml; i <= mr; ++i)
		{
			if (mid[i] == pre[pl])
				break;
		}
		pos = i;
		num = pos - ml;
		lpl = pl + 1;
		lpr = pl + num;
		lml = ml;
		lmr = pos - 1;
		leftroot = buildBTree_by_pre_in(pre, lpl, lpr, mid, lml, lmr);
		rpl = pl + num + 1;
		rpr = pr;
		rml = pos + 1;
		rmr = mr;
		rightroot = buildBTree_by_pre_in(pre, rpl, rpr, mid, rml, rmr);
		p->left = leftroot;
		p->right = rightroot;
	}
};

//已知一棵完全二叉树的层序遍历，能唯一确定
//已知一棵 满 二叉树前序、中序、后序遍历之一，能唯一确定这颗二叉树
//已知前序和中序，后序和中序能唯一确定 
//一直前序和后序 不一定能唯一确定
//

int main()
{
	//链式二叉树：
	// 
	// 
	//
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	BTree<char> tree;
	tree.createBTree('0');
	tree.size();
	tree.height();
	tree.postorder();
	tree.levelorder();
	


	return 0;
}