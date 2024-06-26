#include <iostream>
#include <string>
using namespace std;

bool check3(int a, int b, int c)
{
	int w[9];
	w[0] = a / 100, w[1] = (a % 100) / 10, w[2] = a % 10;
	w[3] = b / 100, w[4] = (b % 100) / 10, w[5] = b % 10;
	w[6] = c / 100, w[7] = (c % 100) / 10, w[8] = c % 10;
	for (int i = 0; i < 9; ++i)
	{
		if (!w[i])return 0;
		for (int j = 0; j < 9; ++j)
		{
			if (i == j)continue;
			if (!(w[i] ^ w[j]))return 0;
		}
	}
	return 1;

}


int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int x;
	for (int i = 1; i < 4; ++i)
	{
		for (int j = 1; j < 10; ++j)
		{
			if (i == j)continue;
			for (int k = 1; k < 10; ++k)
			{
				if (i == k || j == k)continue;
				x = i * 100 + j * 10 + k;
				if (x > 329)return 0;
				if (check3(x, 2 * x, 3 * x))
				{
					cout << x << " " << 2 * x << " " << 3 * x << endl;
				}
			}
		}
	}

	return 0;
}