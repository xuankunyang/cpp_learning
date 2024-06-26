#include <iostream>
#include<cmath>
#include <cstring>
using namespace std;
const int N1 = 1e5 + 5;
int tree1[N1];

void display_inorder(int x)
{
	if (tree1[2 * x] != -1)display_inorder(2 * x);
	cout << tree1[x] << " ";
	if (tree1[2 * x+1] != -1)display_inorder(2 * x+1);
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	memset(tree1, -1, sizeof tree1);
	int h;
	cin >> h;
	int size = pow(2, h)-1;
	for (int i = 1; i <= size; ++i)
	{
		cin >> tree1[i];
	}
	display_inorder(1);

	return 0;
}