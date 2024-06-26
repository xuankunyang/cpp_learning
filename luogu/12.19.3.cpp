#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int change(int lh, int rh,string ss);
void operate(string);
string trans(int c);
int main()
{
	int n;
	cin >> n;
	string* s = new string[n];
	for (int i = 0; i < n; ++i)
	{
		getline(cin, s[i]);
	}
	for (int i = 0; i < n; ++i)
	{
		operate(s[i]);
	}

	delete[]s;
	return 0;
}
int change(int lh, int rh,string ss)
{
	int s = 1,result=0;
	for (int i = rh - 1; i >= lh; --i)
	{
		result += s * (ss[i] - '0');
		s *= 10;
	}
	return result;
}
void operate(string ss)
{
	string result;
	static char op;
	if (ss[0] >= 'a' && ss[0] <= 'c')
		op = ss[0];
	int lh1=0, lh2=0, rh1=0,rh2=ss.length(),i;
	for ( i = 0; i < ss.length(); ++i)
	{
		if (i == 0 && ss[i] >= '0' && ss[i] <= '9')
		{
			break;
		}
		else if (ss[i] == ' ')
		{
			lh1 = i+1;
			break;
		}
	}
	i++;
	for (; i < ss.length(); ++i)
	{
		if (ss[i] == ' ')
		{
			rh1 = i;
			lh2 = i + 1;
		}
	}
	int a = change(lh1, rh1, ss);
	int b = change(lh2, rh2, ss);
	int c;
	switch (op)
	{
	case 'a':
		c = a + b;
		result = trans(a) + "+" + trans(b) + "=" + trans(c);
		cout << result << endl << result.length() << endl;
		break;
	case 'b':
		c = a - b;
		result = trans(a) + "-" + trans(b) + "=" + trans(c);
		cout << result << endl << result.length() << endl;
		break;
	case 'c':
		c = a * b;
		result = trans(a) + "*" + trans(b) + "=" + trans(c);
		cout << result << endl << result.length() << endl;
		break;
	}
}
string trans(int c)
{
	string result;
	int cc = abs(c), p = 0;
	while (cc > 0)
	{
		result[p] = (cc % 10) + '0';
		cc /= 10;
		p++;
	}
	if (c < 0)result[p] = '-';
	return result;
}