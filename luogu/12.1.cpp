#include<iostream>
#include<cstring>
using namespace std;
char* nand(char*, int);
bool ishw(char*);

int main()
{
	int step ,n;
	cin >> n;
	char p[10000] = { '\0' };
	cin >> p;
	for (step = 0; step <= 30; ++step)
	{
		if (ishw(p))break;
		else
		{
			char q[10000] = { '\0' };
			for (int i = 0; i < strlen(nand(p, n)); ++i)
			{
				q[i] = nand(p, n)[i];
			}
			for (int i = 0; i < strlen(q); ++i)
			{
				p[i] = q[i];
			}
			continue;
		}
	}
	if (step >= 0)cout << "STEP=" << step;
	else cout << "Impossible!";

	return 0;
}
char* nand(char* p, int n)
{
	if(n<=10)
	{
		int size = strlen(p);
		char* result = new char[size + 2];
		int jw = 0;
		for (int i = size - 1; i >= 0; --i)
		{
			result[size - 1 - i] = ((p[i] - '0') + (p[size - 1 - i] - '0') + jw) % n + '0';
			jw = ((p[i] - '0') + (p[size - 1 - i] - '0') + jw) / n;
		}
		if (jw != 0)
		{
			result[size] = jw + '0';
			result[size + 1] = '\0';
		}
		else
			result[size] = '\0';
		return result;
	}
	else
	{
		int size = strlen(p),jw=0;
		int* pp = new int[size];
		int* qq = new int[size];
		int *result = new int[size + 1];
		char* re = new char[size + 2];
		for (int i = 0; i < size; ++i)
		{
			if(p[i]>='A')
			{
				switch (p[i] - 'A')
				{
				case 0:pp[i] = 10; qq[size - 1 - i] = 10; break;
				case 1:pp[i] = 11; qq[size - 1 - i] = 11; break;
				case 2:pp[i] = 12; qq[size - 1 - i] = 12; break;
				case 3:pp[i] = 13; qq[size - 1 - i] = 13; break;
				case 4:pp[i] = 14; qq[size - 1 - i] = 14; break;
				case 5:pp[i] = 15; qq[size - 1 - i] = 15; break;
				default:break;
				}
			}
			else
			{
				pp[i] = p[i] - '0';
				qq[size - 1 - i] = p[i] - '0';
			}
		}
		for (int i = 0; i < size; ++i)//从浮点数加法那题里面学的jw，哈哈哈
		{
			result[i] = (pp[i] + qq[i] + jw) % n;
			jw = (pp[i] + qq[i] + jw) / n;
		}
		if (jw != 0)//讨论最后是否存在jw
		{
			result[size] = jw;
			for (int i = 0; i <=size; ++i)
			{
				switch (result[i])
				{//题目十以上的进制就只有16，我先写的十以内，取模就能解决
					//16分开讨论，写了好多石山代码
				case 0:re[i] = '0'; break;
				case 1:re[i] = '1'; break;
				case 2:re[i] = '2'; break;
				case 3:re[i] = '3'; break;
				case 4:re[i] = '4'; break;
				case 5:re[i] = '5'; break;
				case 6:re[i] = '6'; break;
				case 7:re[i] = '7'; break;
				case 8:re[i] = '8'; break;
				case 9:re[i] = '9'; break;
				case 10:re[i] = 'A'; break;
				case 11:re[i] = 'B'; break;
				case 12:re[i] = 'C'; break;
				case 13:re[i] = 'D'; break;
				case 14:re[i] = 'E'; break;
				case 15:re[i] = 'F'; break;
				}
			}
			re[size + 1] = '\0';//最后一位的处理比较关键
		}
		else
		{
			for (int i = 0; i < size; ++i)
			{
				switch (result[i])
				{
				case 0:re[i] = '0'; break;
				case 1:re[i] = '1'; break;
				case 2:re[i] = '2'; break;
				case 3:re[i] = '3'; break;
				case 4:re[i] = '4'; break;
				case 5:re[i] = '5'; break;
				case 6:re[i] = '6'; break;
				case 7:re[i] = '7'; break;
				case 8:re[i] = '8'; break;
				case 9:re[i] = '9'; break;
				case 10:re[i] = 'A'; break;
				case 11:re[i] = 'B'; break;
				case 12:re[i] = 'C'; break;
				case 13:re[i] = 'D'; break;
				case 14:re[i] = 'E'; break;
				case 15:re[i] = 'F'; break;
				}
			}
			re[size] = '\0';
		}
		return re;

	}
}
bool ishw(char* p)
{
	int size = strlen(p),yes=0;
	for (int i = 0; i <= size / 2; ++i)
	{
		if (p[i] == p[size - 1 - i])
			yes++;
		else break;
	}
	if (yes == size / 2 + 1)return true;
	else return false;
}
