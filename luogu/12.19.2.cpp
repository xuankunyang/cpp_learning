#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
void is_prime(int);
int main()
{
	string s;
	cin >> s;
	int len = s.length();
	int maxn = 0,minn= len;
	for (char i='a';i<='z'&&s.length()>0;++i)
	{
		if (s.find(i) == string::npos)continue;
		string temp = s;
		while (temp.find(i) != string::npos)
		{
			temp.replace(temp.find(i), 1, "");
		}
		if (maxn < len - temp.length())
			maxn = len - temp.length();
		if (minn > len - temp.length())
			minn = len - temp.length();
		
	}
	is_prime(maxn-minn);
	return 0;
}
void is_prime(int n)
{
	if (n == 0 || n == 1)
	{
		cout << "No Answer" << endl << 0;;
		return;
	}
	for (int i = 2; i <= n / 2; ++i)
	{
		if (n % i == 0)
		{
			cout << "No Answer" << endl << 0;;
			return;
		}
	}
	cout << "Lucky Word" << endl<<n;
	return;
}