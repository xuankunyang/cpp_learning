#include<iostream>
using namespace std;

template <class elemtype>
class maxstack
{
private:
	elemtype* arr;
	int Top;
	elemtype* maxelem;
	size_t maxsize;
	size_t size;
	void doublespace(elemtype* a)
	{
		elemtype* tmp;
		tmp = new elemtype[maxsize * 2];
		for (int i = 0; i < maxsize; ++i)
		{
			tmp[i] = a[i];
		}
		delete[] a;
		a = tmp;
	}
public:
	maxstack(size_t inisize = 100)
	{
		maxsize = inisize;
		arr = new elemtype[maxsize];
		maxelem = new elemtype[maxsize];
		Top = -1;
		size = 0;
	}
	void push(const elemtype& x)
	{
		if (Top >= maxsize)
		{
			doublespace(arr);
			doublespace(maxelem);
		}
		if (empty())
		{
			arr[++Top] = x;
			maxelem[Top] = x;
		}
		else
		{
			if (maxelem[Top] < x)
			{
				maxelem[++Top] = x;
				arr[Top] = x;
			}
			else
			{
				maxelem[++Top] = maxelem[Top - 1];
				arr[Top] = x;
			}
		}
		size++;
	}
	void pop()
	{
		if (empty())return;
		Top--;
		size--;
	}
	elemtype top()const
	{
		return arr[Top];
	}
	bool empty()
	{
		return Top == -1;
	}
	elemtype getmax()
	{
		return maxelem[Top];
	}
};

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	maxstack<int>s;
	int n, op, x;
	cin >> n;
	while (n--)
	{
		cin >> op;
		switch (op)
		{
		case 0:
			cin >> x;
			s.push(x);
			break;
		case 1:
			if (s.empty())
			{
				cout << "Empty" << endl;
				break;
			}
			s.pop();
			break;
		case 2:
			if (s.empty())
			{
				cout << "Empty" << endl;
				break;
			}
			cout << s.top() << endl;
			break;
		case 3:
			if (s.empty())
			{
				cout << "Empty" << endl;
				break;
			}
			cout << s.getmax() << endl;
			break;
		}
	}



	return 0;
}