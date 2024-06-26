#include <iostream>
#include <string>
using namespace std;
int main()
{
	int n,move;
	cin >> n;
	move = n % 26;
	string s;
	cin>>s;
	for (auto &i : s)
	{
		if (i + move > 122)
			i = i + move - 122 +96;
		else
			i += move;
	}
	cout << s;







	return 0;
}