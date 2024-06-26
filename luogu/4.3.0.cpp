#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int n;
	cin >> n;
	vector<queue<pair<string, int>>>stu(3);
	vector<string>s(3);
	cin >> s[1] >> s[2];
	string head (1,s[1][0]);
	stu[1].push({ head,1});
	for (int j = 1; j <= n; ++j)
	{
		for (int i = 1; i <= 2; ++i)
		{
			if (i == 1)
			{
				if (j == 1)continue;
				stu[i].push({ stu[i].front().first + s[1][j - 1] ,1 });
				stu[i].pop();
			}
			else
			{
				if (j == 1)
				{
					stu[i].push({ stu[i - 1].front().first + s[2][j - 1],1 });
				}
				else
				{
					if (stu[i - 1].front().first == stu[i].front().first)
					{
						stu[i].push({ stu[i - 1].front().first + s[2][j - 1],stu[i - 1].front().second + stu[i].front().second });
						stu[i].pop();
					}
					else if (stu[i - 1].front().first< stu[i].front().first)
					{
						stu[i].push({ stu[i - 1].front().first + s[2][j - 1],stu[i - 1].front().second });
						stu[i].pop();
					}
					else
					{
						stu[i].push({ stu[i].front().first + s[2][j - 1],stu[i].front().second });
						stu[i].pop();
					}
				}
			}
		}
	}

	cout << stu[2].front().first << endl;
	cout << stu[2].front().second << endl;

	
	return 0;
}