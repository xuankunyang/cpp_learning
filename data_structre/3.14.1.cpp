#include <iostream>
#include <cstring>
using namespace std;

template<class elemtype>
class myqueue;
template<class elemtype>
class mystack1;

template <class elemtype>
class node
{
	friend class myqueue<elemtype>;
	friend class mystack1<elemtype>;
private:
	elemtype data;
	node* next;
public:
	node()
	{
		next = nullptr;
	}
	node(const elemtype& i, node<elemtype>* N = nullptr)
	{
		data = i;
		next = N;
	}
	
};
template <class elemtype>
class myqueue
{
private:
	node<elemtype>* head, * tail;
public:
	myqueue()
	{
		head = new node<elemtype>;
		tail = head;
	}
	void push(const elemtype& i)
	{
		node<elemtype>* tmp = new node<elemtype>(i,nullptr);
		tail->next = tmp;
		tail = tmp;
	}
	void pop()
	{
		node<elemtype>* tmp = head->next;
		if (tmp)
		{
			head->next = tmp->next;
			delete tmp;
		}
	}
	bool empty()
	{
		return head->next == nullptr;
	}
	elemtype front()
	{
		return head->next->data;
	}
	int size()
	{
		node<elemtype>* p = head->next;
		int ans = 0;
		while (p)
		{
			p = p->next;
			ans++;
		}
		return ans;
	}
	~myqueue()
	{
		node<elemtype>* p, * q;
		p = head->next;
		head->next = nullptr;
		while (p)
		{
			q = p->next;
			delete p;
			p = q;
		}
	}
};
const int N = 1e7;
char fruits[N],s[N];
int main()
{
	ios::sync_with_stdio, cin.tie(0), cout.tie(0);
	myqueue <char>stu;
	
	cin >> fruits;
	cin >> s;
	for (int i = 0; i < strlen(s); ++i)
	{
		stu.push(s[i]);
	}
	int t = 0,k=0;
	while (!stu.empty())
	{
		if (t == stu.size())break;
		char f = stu.front();
		stu.pop();
		if (fruits[k] == f)
		{
			t = 0;
			k++;
		}
		else
		{
			stu.push(f);
			t++;
		}

	}
	cout <<t;



	return 0;
}