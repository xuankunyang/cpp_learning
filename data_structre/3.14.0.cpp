#include <iostream>
#include<cstring>
using namespace std;

template<class elemtype>
class mystack
{
private:
	elemtype* a;
	int Top;
	int size;
	
public:
	mystack(const int& s)
	{
		size = s;
		a = new elemtype[s];
		Top = -1;
	}
	void push(const elemtype& i)
	{
		a[++Top] = i;
	}
	elemtype top()
	{
		return a[Top];
	}
	bool empty()const
	{
		return Top == -1;
	}
	void pop()
	{
		if (empty())return;
		Top--;
	}
	~mystack()
	{
		delete[]a;
	}
	elemtype getlast()
	{
		elemtype t = top();
		pop();
		if (empty())return t;
		elemtype res = getlast();
		push(t);
		return res;
	}
	void reverse()
	{
		if (empty())return;
		elemtype ans = getlast();
		reverse();
		push(ans);
	}
	void display()
	{
		for (int i = 0; i <= Top; ++i)
			cout << a[i];
	}
};

int main()
{
	ios::sync_with_stdio, cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	mystack<char> s(n);

	for (int i = 0; i < n; ++i)
	{
		char ch;
		cin >> ch;
		if (s.empty())s.push(ch);
		else if (s.top() == ch)s.pop();
		else s.push(ch);
	}
	if (s.empty())cout << "";
	else s.display();




	return 0;
}