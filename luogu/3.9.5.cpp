#include <iostream>
#include <string>

using namespace std;

int ls22[30], rs22[30];
string s1, s2;

void dfs10(string pre, string mid)
{
	if (pre.empty())return;
	char root = pre[0];
	int k = mid.find(root);//以root为根 分别切割前序和中序 左右左右递归
	pre.erase(pre.begin());
	string leftpre = pre.substr(0, k);
	string rightpre = pre.substr(k);
	string leftmid = mid.substr(0, k);
	string rightmid = mid.substr(k + 1);
	dfs10(leftpre, leftmid);//后序 左子树-右子树-根
	dfs10(rightpre, rightmid);
	cout << root;

}



int main()
{
	ios::sync_with_stdio, cin.tie(0), cout.tie(0);
	cin >> s2 >> s1;
	dfs10(s1, s2);

	return 0;
}