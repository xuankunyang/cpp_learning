#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;
int main()
{
	char p[1000] = {'\0'};
	cin.getline(p, 1000);
	long long xsl[100] = { 0 }, xsr[100] = { 0 },dpoint=0,csl=0,csr=0;
	int t = 0,k=0,h=0;//系数的计数
	bool flag = true;
	static char ans='\0';
	for (int i = 0; i < strlen(p); ++i)
	{
		if (p[i] == '=')
		{
			flag = false;
			dpoint = i;
		}
		if (p[i] >= 'a' && p[i] <= 'z'&&flag)
		{
			ans = p[i];
			long long s = 1;
			for (int m = i-1; m >= 0 && (p[m] >= '0' && p[m] <= '9') ; --m)
			{
				if (p[m] >= '0' && p[m] <= '9')
				{
					xsl[t] += (p[m] - '0') * s;
					s *= 10;
				}
				if (m >= 1 && p[m - 1] == '-')
				{
					xsl[t] *= (-1);
					t++;
					break;
				}
				else if(m >= 1 && p[m - 1] == '+')
				{
					t++;
					break;
				}
				else if (m == 0)
				{
					t++;
					break;
				}
			}
			if (i == 0)
			{
				xsl[t] = 1;
				t++;
			}
			else if (p[i - 1] == '+')
			{
				xsl[t]=1;
				t++;
			}
			else if (p[i - 1] == '-')
			{
				xsl[t] = -1;
				++t;
			}
		}
		else if (p[i] >= 'a' && p[i] <= 'z' && !flag)
		{
			long long s = 1;
			for (int m = i - 1; m >= 0 && (p[m] >= '0' && p[m] <= '9'); --m)
			{
				if (p[m] >= '0' && p[m] <= '9')
				{
					xsr[k] += (p[m] - '0') * s;
					s *= 10;
				}
				if (m > dpoint && p[m - 1] == '-')
				{
					xsr[k] *= (-1);
					k++;
					break;
				}
				else if (m > dpoint && (p[m - 1] == '+'||p[m-1]=='='))
				{
					k++;
					break;
				}
			}
			if (p[i-1]=='=')
			{
				xsr[k] = 1;
				k++;
			}
			else if (p[i - 1] == '+')
			{
				xsr[k] = 1;
				k++;
			}
			else if (p[i - 1] == '-')
			{
				xsr[k] = -1;
				++k;
			}
		}
	}
	for (int i =dpoint;i>=0;i--)
	{
		if ((p[i] == '+' || p[i]=='-' || i==dpoint) && p[i - 1] >= '0' && p[i - 1] <= '9')
		{
			long long s = 1, sum = 0;
			for (int m = i - 1; m >= 0 && p[m] >= '0' && p[m] <= '9'; --m)
			{
				sum += (p[m] - '0') * s;
				s *= 10;
				if (m >= 1 && p[m - 1] == '-')
				{
					csl -= sum;
					break;
				}
				else if (m >= 1 && p[m - 1] == '+')
				{
					csl += sum;
					break;
				}
				else if (m == 0)
				{
					csl += sum;
					break;
				}
			}
		}
	}
	for (int i = strlen(p); i > dpoint; --i)
	{
		if ((p[i] == '+' || p[i] == '-'||i==strlen(p)) && p[i - 1] >= '0' && p[i - 1] <= '9')
		{
			long long s = 1,sum = 0;
			for (int m = i - 1; m >= 0 && p[m] >= '0' && p[m] <= '9'; --m)
			{
				sum += (p[m] - '0') * s;
				s *= 10;
				if (m >dpoint && p[m - 1] == '-')
				{
					csr -= sum;
					break;
				}
				else if (m >dpoint && p[m - 1] == '+')
				{
					csr += sum;
					break;
				}
				else if (m > dpoint && p[m - 1] == '=')
				{
					csr += sum;
					break;
				}
			}
		}
	}
	long long xs=0;
	for (int i = 0; i < 100; ++i)
	{
		xs += (xsl[i] - xsr[i]);
	}
	long double cs = csr - csl;
	if (cs == 0)
		cout <<ans<<"=0.000";
	else
	{
		long double answer = cs / xs;
		cout <<ans<<"=" << setprecision(3) << fixed << answer;
	}
	return 0;
}