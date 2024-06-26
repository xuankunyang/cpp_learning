#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int n;
	cin >> n;
	vector<vector<pair<string, int>>>stu(3, vector<pair<string, int>>(n + 1, make_pair("", 0)));
	vector<string>s(3);
	cin >> s[1] >> s[2];
	stu[1][1].first = s[1][0];
	stu[1][1].second = 1;
	for (int i = 1; i <= 2; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (i == 1)
			{
				if (j == 1)continue;
				stu[i][j].first = stu[i][j - 1].first + s[1][j - 1];
				stu[i][j].second = stu[i][j - 1].second;
			}
			else
			{
				if (j == 1)
				{
					stu[i][j].first = stu[i-1][j].first + s[2][j - 1];
					stu[i][j].second = stu[i-1][j].second;
				}
				else
				{
					if (stu[i-1][j].first==stu[i][j-1].first)
					{
						stu[i][j].first = stu[i - 1][j].first + s[2][j - 1];
						stu[i][j].second = stu[i - 1][j].second+stu[i][j-1].second;
					}
					else if (stu[i - 1][j].first < stu[i][j - 1].first)
					{
						stu[i][j].first = stu[i - 1][j].first + s[2][j - 1];
						stu[i][j].second = stu[i - 1][j].second;
					}
					else
					{
						stu[i][j].first = stu[i][j-1].first + s[2][j - 1];
						stu[i][j].second = stu[i][j-1].second;
					}
				}
			}
		}
	}
	
	cout << stu[2][n].first << endl;
	cout << stu[2][n].second << endl;

	return 0;
}