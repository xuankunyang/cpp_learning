#include <iostream>
using namespace std;
struct node
{
	int val;
	node* next;
};
int main()
{
	int n;
	cin >> n;
	node* head = new node;
	head->next = nullptr;
	node* head_bf = head;
	int t = 0;
	for (int i = 0; i < n; ++i)
	{
		int x;
		cin >> x;
		if (i != 0 && head->next->val != x)
		{
			if (t == 0)
			{
				head = head->next;
			}
			else
			{
				head->next = new node;//�����new���ظ��ĵ�һ�������ǻᱻ��������
				node* p = new node;
				p->val = x;
				p->next = nullptr;
				head->next = p;
				t = 0;
				continue;
			}
		}
		else if (i != 0 && head->next->val == x)
		{
			t++;
			if (i == n - 1)
			{
				head->next = nullptr;
				break;//����ظ������
			}
		}
		node* p = new node;
		p->val = x;
		p->next = nullptr;
		head->next = p;
	}
	while (head_bf->next)
	{
		cout << head_bf->next->val << " ";
		head_bf = head_bf->next;
	}
	cout << endl;
	return 0;
}