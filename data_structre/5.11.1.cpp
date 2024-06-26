#include <iostream>
#include <cstring>

using namespace std;
using ll = unsigned long long;

const int mod7 = 1e4+ 9;
const int N7 = 1e4 + 9;
const int base = 31;
char ch7[N7];
struct node
{
	char data[1501];
	bool filled = 0;
}hash7[N7];
int maxsize4 = 0;

int hashindex(const char& ch)
{
	if (ch >= '0' && ch <= '9')return ch - '0';
	else if (ch >= 'a' && ch <= 'z')return ch - 'a' + 10;
	else return ch - 'A' + 36;
}


void insert7(ll res,const char* ch)
{
	if (hash7[res].filled)
	{
		if (strcmp(hash7[res].data, ch) == 0)return;
		else
		{
			insert7((res++) % mod7, ch);
		}
	}
	else 
	{
		hash7[res].filled = 1;
		strcpy_s(hash7[res].data, ch);
	}

}

int main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n7;
	cin >> n7;
	for (int i = 0; i < n7; ++i)
	{
		cin >> ch7;
		unsigned long hash = 5381; // 改进的哈希函数，采用DJB2算法
		for(int j=0;j<strlen(ch7);++j)
		{
			hash = (((hash << 5) + hash) + ch7[j]) % mod7;
		}
		maxsize4 = hash > maxsize4 ? hash : maxsize4;
		insert7(hash, ch7);
	}
	int ans = 0;
	for (int i = 0; i <= maxsize4; ++i)
	{
		if (hash7[i].filled)
			ans++;
	}
	cout << ans << endl;

	
	return 0;
}
