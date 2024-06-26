#include <iostream>
#include <string>
using namespace std;
int main()
{
	string s;
	getline(cin, s);
	for (auto &i : s)
	{
		if (i >= 'a' && i <= 'z')
			i -= 32;
	}
	cout << s;
	return 0;
}