#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template<class elemtype>
struct less1
{
	bool operator()(const elemtype& left, const elemtype& right)
	{
		return left < right;
	}
};

template<class elemtype>
struct greater1
{
	bool operator()(const elemtype& left, const elemtype& right)
	{
		return left > right;
	}
};
template<class elemtype,class container=vector<elemtype>,class compare= less1<elemtype>>
class mypriority_queue
{
private:
	container c;
	void adjustup(size_t child)
	{
		compare com;
		size_t parent = (child - 1) / 2;
		while (child)
		{
			if (com(c[parent], c[child]))// c[child]>c[parent]
			{
				swap(c[parent], c[child]);
				child = parent;
				parent = (child - 1) / 2;
			}
			else break;
		}
	}
	void adjustdown(size_t parent)
	{
		size_t child = parent * 2 + 1;
		compare com;
		while (child < c.size())
		{
			if (child + 1 < c.size() && com(c[child], c[child + 1]))
				child++;
			if (com(c[parent], c[child]))
			{
				swap(c[child], c[parent]);
				parent = child;
				child = parent * 2 + 1;
			}
			else break;
		}
	}
public :
	void push(const elemtype& x)
	{
		c.push_back(x);
		adjustup(c.size() - 1);
	}
	void pop()
	{
		if (empty())
			return;
		swap(c[0], c[c.size() - 1]);
		c.pop_back();
		adjustdown(0);
	}
	elemtype& top()
	{
		return c[0];
	}
	size_t size()const
	{
		return c.size();
	}
	bool empty() const 
	{
		return c.empty();
	}

};

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	mypriority_queue<int, vector<int>, less1<int>>q;
	int m, n,x;
	cin >> m >> n;
	for (int i = 1; i <= m + n; ++i)
	{
		cin >> x;
		q.push(x);
	}
	for (int i = 1; i <= m + n; ++i)
	{
		cout << q.top()<<" ";
		q.pop();
	}

	return 0;
}