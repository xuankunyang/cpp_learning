#include <iostream>
using namespace std;

int main()
{
	//森林表示法：每棵树要先用二叉树表示出来，再把各个树的根节点看作兄弟建立二叉树
	//树的遍历：先根遍历，后根遍历
	//有趣的是：树的先根遍历等价于对应二叉树的先序遍历，后根遍历等价于对应二叉树的中序遍历
	//森林的先序遍历，中序遍历（等价于对每棵子树的后根遍历，及对应二叉树的中序遍历）

	//二叉树求高度：借鉴前序遍历的非递归算法，增加一个栈储存对应节点的层次数，弹出的元素用一个max来维护
	//二叉树表示的树：借鉴上述方法，压入右孩子的时候，层次和parent一样，因为他们其实是同层次的，接着还是用一个max维护
	//由二叉树求所有节点的子节点
	// if(!root)return ;
	// queue<node<elemtype>*>q;
	// node<*elemtype>*p;
	// while(!q.empty())
	// {
	// p=q.front();
	// q.pop();
	// cout<<p->data<<":";
	// if(p->left)
	// {
	// q.push(p->left);
	// cout<<p->left->data;
	// p=p->left;
	// while(p->right)
	// {
	// q.push(p->right);
	// cout<<p->right->data;
	// p=p->right;
	// }
	// }
	// }
	// 
	// 优先队列
	// 堆（完全二叉树），大根堆，小根堆
	// 
	//



	return 0;
}