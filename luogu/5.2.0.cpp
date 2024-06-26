#include <iostream>
#include <string>
#include <cstring>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

int n39;
char map39[105][105];
bool vis39[105][105];
int nx39[] = {1,-1,0,0,1,-1,1,-1};
int ny39[] = {0,0,1,-1,1,1,-1,-1};

void dfs17(const int& x, const int& y)
{
	for (int i = 0; i < 8; ++i)
	{
		queue<pair<int, int>>q;
		int lastx = x, lasty = y;
		int tmpx = x + nx39[i], tmpy = y + ny39[i];
		while (tmpx >= 0 && tmpx < n39 && tmpy >= 0 && tmpy < n39)
		{
			if (map39[lastx][lasty] == 'y' && map39[tmpx][tmpy] == 'i')
			{
				q.push({ lastx,lasty });
				lastx = tmpx;
				lasty = tmpy;
				tmpx = lastx + nx39[i];
				tmpy = lasty + ny39[i];
				continue;
			}
			else if (map39[lastx][lasty] == 'i' && map39[tmpx][tmpy] == 'z')
			{
				q.push({ lastx,lasty });
				lastx = tmpx;
				lasty = tmpy;
				tmpx = lastx + nx39[i];
				tmpy = lasty + ny39[i];
				continue;
			}
			else if (map39[lastx][lasty] == 'z' && map39[tmpx][tmpy] == 'h')
			{
				q.push({ lastx,lasty });
				lastx = tmpx;
				lasty = tmpy;
				tmpx = lastx + nx39[i];
				tmpy = lasty + ny39[i];
				continue;
			}
			else if (map39[lastx][lasty] == 'h' && map39[tmpx][tmpy] == 'o')
			{
				q.push({ lastx,lasty });
				lastx = tmpx;
				lasty = tmpy;
				tmpx = lastx + nx39[i];
				tmpy = lasty + ny39[i];
				continue;
			}
			else if (map39[lastx][lasty] == 'o' && map39[tmpx][tmpy] == 'n')
			{
				q.push({ lastx,lasty });
				lastx = tmpx;
				lasty = tmpy;
				tmpx = lastx + nx39[i];
				tmpy = lasty + ny39[i];
				continue;
			}
			else if (map39[lastx][lasty] == 'n' && map39[tmpx][tmpy] == 'g')
			{
				vis39[lastx][lasty] = 1;
				vis39[tmpx][tmpy] = 1;
				while (q.size())
				{
					auto t = q.front();
					vis39[t.first][t.second] = 1;
					q.pop();
				}
				break;
			}
			else break;
		}
	}
	

}

int main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	memset(vis39, 0, sizeof vis39);
	cin >> n39;
	for (int i = 0; i < n39; ++i)
	{
		cin >> map39[i];
	}
	for (int i = 0; i < n39; ++i)
	{
		for (int j = 0; j < n39; ++j)
		{
			if (map39[i][j] == 'y')dfs17(i, j);
		}
	}

	for (int i = 0; i < n39; ++i)
	{
		for (int j = 0; j < n39; ++j)
		{
			if (vis39[i][j])cout << map39[i][j];
			else cout << '*';
		}
		cout << endl;
	}


	return 0;
}