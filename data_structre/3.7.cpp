#include <iostream>
#include <bitset>
using namespace std;
int main()
{
	//dhc上课问我进制转换，乐
	cout << bitset<8>(80) << endl;
	cout << bitset<8>(-80) << endl;

	//快速插入法:
	// 首席插入法，插入位置不限，那插入的最优选择是插在head之后
	// node* tmp=new node(x,head->next);
	// head->next=tmp;
	// 
	// 就地逆置操作:
	// node *p=head->next;
	// head->next=nullptr;
	// while(p)
	// {
	// node *q=p->next;//兄弟协同，做记录
	// p->next=head->next;
	// head->next=p;//首席插入
	// p=q;
	// }
	//
	// 输出倒数第k个元素:
	// 先让p让前走k步，p、q再一起往前走到最后，中间隔着k步，走后q就是答案
	// node *p=head->next;
	// while(p&(k--))
	// {
	// p=p->next;
	// }
	// if(!p)return;
	// q=head;
	// while(p&q)
	// {
	// p=p->next;
	// q=q->next;
	// }
	// ans::q
	// 
	// 找中间节点:
	// p走两步，q走一步，p到了，q就是ans
	// 
	// 
	//
	//


	return 0;
}