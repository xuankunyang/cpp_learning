#include <iostream>
using namespace std;
int main()
{
	//又是一个下雨的周一

	//链式结构相较于顺序结构更便于插入删除
	//srtuct 默认都是public class 默认private
	//delete释放的是指针所对的空间而非指针本身
	//new 后面跟着的是class的构造函数 所以最后要跟（） struct则不用
	//插入操作：
	//tmp=new node<elemtype>();
	//tmp->data=x;
	//tmp->next=p->next;
	//p->next=tmp;
	//改进后的操作：
	//p->next =new node<elemtype>(x,p->next);// 另一类构造函数 从后往前执行
	//删除操作:
	//while(p&&(--i))
	//{p=p->next;}
	// if(!p)return;
	//node*tmp=p->next;
	//if(!tmp)return ;
	//p->next=tmp->next;
	//delete tmp;
	//清空操作:
	//node* p=head;
	// node* q=p->next;
	// p->next=nullptr;
	// p=q;
	// while(p)
	// {
	// q=p->next;
	// delete p;
	// p=q;
	// }
	// 兄弟协同法
	//
	
	





	return 0;
}