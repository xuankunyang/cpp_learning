#include <iostream>
#include<string>
using namespace std;
int find(const string& s1, const string& s2);
int maxborder(string sub);
int main()
{
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);
	int tag = find(s1, s2);
	while (tag!=-1)
	{
		if(tag!=0)
		{
			cout << tag << endl;
		}
		tag = find(s1, s2);
	}
	for (int i = 1; i <= s2.length(); ++i)
	{
		cout << maxborder(s2.substr(0, i)) << " ";
	}
	return 0;
}
int find(const string& s1, const string& s2)
{
	static auto pos = s1.begin();
	int left = pos - s1.begin();
	string ss = s1.substr(left,s1.length()-left);
	if (ss.find(s2) != -1)
	{
		pos++;
		static int last = (int)ss.find(s2) + left + 1;
		static bool flag = true;
		if ((int)ss.find(s2) + left + 1 != last || flag)
		{
			flag = false;
			last = (int)ss.find(s2) + left + 1;
			return last;
		}
		else return 0;
	}
	return -1;
}
int maxborder(string sub)
{
	if (sub.length() == 1)
		return 0;
	int len = 0;
	for (int i = 0; i < sub.length() / 2; ++i)
	{
		if (sub[i] == sub[sub.length() - 1 - i])
			len++;
		else break;
	}
	return len;
}