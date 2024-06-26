#pragma once

template <class elemtype>
class binarySearchTree;

template <class elemtype>
class node
{
	friend class binarySearchTree<elemtype>;
private:
	elemtype data;
	node<elemtype>* left, * right;
	int height;
public:
	node()
	{
		left = nullptr;
		right = nullptr;
		height = 1;
	}
	node(const elemtype& e, node<elemtype>* l = nullptr, node<elemtype>* r = nullptr, int h = 1)
	{
		data = e;
		left = l;
		right = r;
		height = h;
	}

};


template <class elemtype>
class binarySearchTree
{
private:
	node<elemtype>* root;
	int max(int& a, int& b)
	{
		return a > b ? a : b;
	}
	bool search(const elemtype& x, node<elemtype>* r)
	{
		if (!r)return false;
		if (r->data == x)return true;
		else if (x < r->data)return search(x, r->left);
		else return search(x, r->right);
	}
	void insert(const elemtype& x, node<elemtype>*& r)
	{
		if (!r)
		{
			r = new node<elemtype>(x);//这里能new主要得益于 & 形参r和外部的实参是同一个东西
			return;
		}
		if (x == r->data)return;
		if (x < r->data)
			insert(x, r->left);
		else insert(x, r->right);
	}
	void LL(node<elemtype>*& t)
	{
		node<elemtype>* newroot = t->left;
		t - left = newroot->right;
		newroot->right = t;
		t->height = (t->left->height > t->right->height ? t->left->height : t->right->height)+1;
		newroot->height = max(newroot->left->height, newroot->right->height)+1;
	}
	void RR(node<elemtype>*& t)
	{
		node<elemtype>* newroot = t->right;
		t->right = newroot->left;
		newroot->left = t;
		t->height = max(t->left->height, t->right->height)+1;
		newroot->height = max(newroot->left->height, newroot->right->height)+1;
	}
	void LR(node<elemtype>*& t)
	{
		RR(t->left);
		LL(t);
	}
	void RL(node<elemtype>*& t)
	{
		LL(t->right);
		RR(t);
	}
	int height(node<elemtype>* t)
	{
		if (!t)return 0;
		return t->height;
	}
	

	//删除是个复杂操作
	//需要找替身节点
	//替身节点可以选择左子树的最大值，或者右子树的最小值
	void remove(const elemtype& x, node<elemtype>*& r)
	{
		if (!r)return;
		if (x < r->data)remove(x, r->left);
		else if (x > r->data)remove(x, r->right);
		else
		{
			if (!r->left || !r->right)//待删除的节点只有一个孩子或者是叶子节点
			{
				node<elemtype>* tmp = r;
				r = (r->left) ? r->left : r->right;//这一步真的很巧 囊括了三种情况
				delete tmp;
				return;
			}
			else
			{
				node<elemtype>* p, * substitute;
				p = r-> right;//这里选用的是右子树的最小值作为替身
				while (p)
				{
					p = p->left;
				}
				substitute = p;
				r->data = substitute->data;
				remove(substitute->data, r->right);//从右子树的根开始递归的删除
				//这里为什么是从r->right开始往下递归 其实这已经是有记录的最近的节点了 上面的那个p已经直接是substitude
				//还有一种更极端的情况 就是x只有右子 然后右子中最小的直接和x相连 这种思路可以囊括这些情况
			}

		}


	}

public:
	bool search1(const elemtype& x)const
	{
		return search(x, root);
	}
	bool search2(const elemtype& x)const
	{
		node<elemtype>*p = root;
		while (p)
		{
			if (p->data == x)return true;
			else if (x < p->data)p = p->left;
			else p = p->right;
		}
		return false;
	}
	void insert2(const eleltype& x)
	{
		node<elemtype>* p;
		if (!root)
		{
			root = new node < elemtype(x);
			return;
		}
		p = root;
		while (p)
		{
			if (x == p->data)return;
			if (x < p->data)
			{
				if (!p->left)
				{
					p->left = new node<elemtype>(x);
					return;
				}
				p = p->left;
			}
			else
			{
				if (!p->right)
				{
					p->right = new node<elemtype>(x);
					return;
				}
				p = p->right;
			}
		}
	}
	void insert1(const elemtype& x)
	{
		insert(x, root);
	}
	void remove1(const elemtype& e)
	{
		remove(e, root);
	}
	void remove2(const elemtype& x)
	{
		if (!root)return;
		node<elemtype>* p = root, * parent=nullptr;
		while (p)
		{
			if (x < p->data)
			{
				parent = p;
				p = p->left;
				continue;
			}
			if (x > p->data)
			{
				parent = p;
				p = p->right;
				continue;
			}
			//开始删除
			if (!p->left && !p->right)
			{
				if (!parent)
				{
					root = nullptr;
					return;
				}
				if (x < parent->data)
				{
					parent->left = nullptr;
					delete p;
					return;
				}
				else
				{
					parent->right = nullptr;
					delete p;
					return;
				}
			}
			if (!p->left || !p->right)
			{
				if (!parent)root = (p->left) ? p->left : p->right;
				else
				{
					if (x < parent->data)
						parent->left = p->left ? p->left ? p->right;
					else 
						parent->right = p->left ? p->left ? p->right;
				}
				delete p;
				return;
			}
			node <elemtype>* q, * substitude;
			parent = p;
			q = p->left;//左边子树的最大值
			while (q->right)
			{
				parent = q;
				q = q->right;
			}
			substitude = q;
			elemtype s;
			s = q->data;
			q->data = substitude->data;
			substitude->data = s;
			p = substitude;//将待删除的节点指针替换为替身 重新返回循环

		}
	}
	void AVLinsert(const elemtype& x, node<elemtype>*& t)
	{
		if (!t)t = new node<elemtype>(x);
		else if (x == t->data)return;
		else if (x >t->right)
		{
			AVLinsert(x, t->right);
			if (height(t->left) - height(t->right) == -2)//冲突
			{
				if (x > t->right->data)RR(t);
				else RL(t);
			}
			else t->height = (t->left->height > t->right->height ? t->left->height : t->right->height)+1;
		}
		else if (x < t->left)
		{
			AVLinsert(x, t->left);
			if (height(t->left) - height(t->right) == 2)
			{
				if (x < t->left->data)LL(t);
				else LR(t);
			}
			else t->height = (t->left->height > t->right->height ? t->left->height : t->right->height)+1;
		}
	}
	void AVLremove(const elemtype& x, node<elemtype>*& t)
	{
		if (!t)return;
		else if (x == t->data)remove(x,t);
		else if (x > t->right)
		{
			AVLremove(x, t->right);
			if (height(t->left) - height(t->right) == -2)//冲突
			{
				if (x > t->right->data)RR(t);
				else RL(t);
			}
			else t->height = (t->left->height > t->right->height ? t->left->height-1 : t->right->height-1);
		}
		else if (x < t->left)
		{
			AVLremove(x, t->left);
			if (height(t->left) - height(t->right) == 2)
			{
				if (x < t->left->data)LL(t);
				else LR(t);
			}
			else t->height = (t->left->height > t->right->height ? t->left->height-1 : t->right->height-1);
		}
	}



};