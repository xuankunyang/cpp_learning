#include <iostream>
#include <iomanip>
using namespace std;
int n1, r1;
const int N1 = 21;
int q[N1];
void dfs2(int a)
{
	if (a > r1)
	{
		for (int i =1; i < a; ++i)
			cout << setw(3) << q[i];
		cout << endl;
		return;
	}
	for (int i = q[a - 1] + 1; i <= n1; ++i)
	{
		q[a] = i;
		dfs2(a + 1);
	}


}

int main()
{
	q[0] = 0;
	ios::sync_with_stdio, cin.tie(0), cout.tie(0);
	cin >> n1 >> r1;
	dfs2(1);

	return 0;
}