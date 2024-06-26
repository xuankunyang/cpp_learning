//#include<iostream>
//using namespace std;
//long long int jcf(int n);
//int main()
//{
//	int n;
//	long long int  s = 0;
//	cin >> n;
//	for (int i = 1; i <= n; ++i)
//	{
//		s += jcf(i);
//	}
//	cout << s;
//	return 0;
//}
//long long int jcf(int n)
//{
//	if (n == 0)return 1;
//	else return n * jcf(n - 1);
//}
#include <iostream>
using namespace std;
int result[3000] = { 0 };
int* jcf(int );
int* add(int**,int);
void show(int*);
int main()
{
	int n;
	cin >> n;
	int **a=new int*[n];
	for (int i = 0; i < n; ++i)
	{
		a[i] = jcf(i + 1);
	}
	show(add(a, n));
	return 0;
}
int * jcf(int n)
{
	int f[3000] = { 0 };
	
	f[0] = 1;
	for (int i = 2; i <= n; ++i)
	{
		int jw = 0;
		for (int j = 0; j < 3000; ++j)
		{
			int s = f[j] * i + jw;
			f[j] = s % 10;
			jw = s / 10;
		}
	}
	return f;
}
int* add(int** a,int n)
{
	int jw = 0;
	for (int i = 0; i < 3000; ++i)
	{
		int s = 0;
		for (int j = 0; j < n; ++j)
		{
			s += a[j][i];
		}
		result[i] = (s + jw) % 10;
		jw = (s + jw) / 10;
	}
	return result;
}
void show(int* result)
{
	int p = 3000 - 1;
	for (; p >= 0; --p)
	{
		if (result[p] != 0)break;
	}
	for (; p >= 0; --p)
		cout << result[p];
}