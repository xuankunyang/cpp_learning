#include <iostream>
#include <bitset>
using namespace std;
int main()
{
	//dhc�Ͽ����ҽ���ת������
	cout << bitset<8>(80) << endl;
	cout << bitset<8>(-80) << endl;

	//���ٲ��뷨:
	// ��ϯ���뷨������λ�ò��ޣ��ǲ��������ѡ���ǲ���head֮��
	// node* tmp=new node(x,head->next);
	// head->next=tmp;
	// 
	// �͵����ò���:
	// node *p=head->next;
	// head->next=nullptr;
	// while(p)
	// {
	// node *q=p->next;//�ֵ�Эͬ������¼
	// p->next=head->next;
	// head->next=p;//��ϯ����
	// p=q;
	// }
	//
	// ���������k��Ԫ��:
	// ����p��ǰ��k����p��q��һ����ǰ�ߵ�����м����k�����ߺ�q���Ǵ�
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
	// ���м�ڵ�:
	// p��������q��һ����p���ˣ�q����ans
	// 
	// 
	//
	//


	return 0;
}