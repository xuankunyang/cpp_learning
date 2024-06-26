#include<iostream>
using namespace std;
int time(const int* p, int s);
void sort(int* p, int s);
int zuhe(const int* p, const int truenum, int* position, int start, int size, int num, int pp);
int main()
{
	int s1, s2, s3, s4;
	cin >> s1 >> s2 >> s3 >> s4;
	int* p1 = new int[s1];
	int* p2 = new int[s2];
	int* p3 = new int[s3];
	int* p4 = new int[s4];
	for (int i = 0; i < s1; ++i)
	{
		cin >> p1[i];
	}
	for (int i = 0; i < s2; ++i)
	{
		cin >> p2[i];
	}
	for (int i = 0; i < s3; ++i)
	{
		cin >> p3[i];
	}
	for (int i = 0; i < s4; ++i)
	{
		cin >> p4[i];
	}
	int final = time(p1, s1) + time(p2, s2) + time(p3, s3) + time(p4, s4);
	cout << final;

	return 0;
}
void sort(int* p, int s)
{
	bool flag;
	for (int i = 0; i < s - 1; ++i)
	{
		flag = true;
		for (int t = 0; t < s - i - 1; ++t)
		{
			if (p[t] > p[t + 1])
			{
				int temp = p[t];
				p[t] = p[t + 1];
				p[t + 1] = temp;
				flag = false;
			}
		}
		if (flag)
			break;
	}
}
int time(const int* p, int s)
{
	int sum = 0;
	for (int i = 0; i < s; ++i)
	{
		sum += p[i];
	}
	int half = sum / 2 + 1,temp=sum;
	for (int m = 1; m <= s / 2+1; ++m)
	{
		int* q = new int[m];
		int zh = zuhe(p, m, q, 0, s, m, 0);
		if (zh >= half && zh < temp)
			temp = zh;

		delete[]q;
	}
	return temp;


}
int zuhe(const int *p, const int truenum,int *position, int start, int size, int num,int pp)
{
	if (pp==truenum)
	{
		int zh = 0;
		for (int s = 0; s < truenum; ++s)
		{
			zh += p[position[s]];
		}
		return zh;
	}
	for (int i = start; i <= size - num; ++i)
	{
		position[pp++] = i;
		zuhe(p,truenum,position,i + 1, size - i-1, num - 1,pp);
	}
	
}