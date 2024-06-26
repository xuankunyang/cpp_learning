#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

template<class elemtype>
class linkqueue;

template <class elemtype>
class linknode
{
	friend class linkqueue<elemtype>;
private:
	elemtype data;
	linknode* next;
public:
	linknode()
	{
		next = nullptr;
	}
	linknode(const elemtype& i, linknode<elemtype>* N = nullptr)
	{
		data = i;
		next = N;
	}

};
template <class elemtype>
class linkqueue
{
private:
	linknode<elemtype>* head, * tail;
public:
	linkqueue()
	{
		tail = head=nullptr;
	}
	void push(const elemtype& i)
	{
		if(!tail)
		{
			tail = head = new linknode<elemtype>(i, nullptr);
			return;
		}
		tail->next = new linknode<elemtype>(i, nullptr);
		tail =tail->next;
	}
	void pop()
	{
		linknode<elemtype>* tmp = head;
		if (tmp)
		{
			head = tmp->next;
			delete tmp;
		}
		if (!head)tail = nullptr;
	}
	bool empty()
	{
		return head == nullptr;
	}
	elemtype front()
	{
		return head->data;
	}
	int size()
	{
		linknode<elemtype>* p = head;
		int ans = 0;
		while (p)
		{
			p = p->next;
			ans++;
		}
		return ans;
	}
	~linkqueue()
	{
		linknode<elemtype>* p, * q;
		p = head;
		head = nullptr;
		while (p)
		{
			q = p->next;
			delete p;
			p = q;
		}
	}
};
const int N2 = 1030;
int ls1[N2], rs1[N2];
bool vis1[N2];
linkqueue<int> q1;

void display()
{
	int p;
	while (!q1.empty())
	{
		p = q1.front();
		if (!p)return;
		q1.pop();
		cout << p <<endl;
		q1.push(ls1[p]);
		q1.push(rs1[p]);
	}
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	memset(vis1, 0, sizeof vis1);
	int n;
	cin >> n;
	int height = log2(n + 1);
	int s = pow(2, height - 1)-1;
	int x, y, z,root;
	for (int i = 1; i <= s ; ++i)
	{
		cin >> x >> y >> z;
		ls1[x] = y, rs1[x] = z;
		vis1[y] = 1, vis1[z] = 1;
	}
	for (int i = 1; i <= n; ++i)
	{
		if (!vis1[i])
		{
			root = i; 
			break;
		}
	}
	q1.push(root);
	display();

	return 0;
}
