#include<iostream>
using namespace std;
int maxlr1(int, int, int, int,int,int);
int maxlr2(int, int, int, int,int);
int search(int, int, int, int, int);
int main()
{
	int expect, price[1000] = { 0 }, sale[1000] = {0},m=0,per,exsale,outer;
	cin >> expect;
	int t = 0;
	do
	{
		cin >> price[t] >> sale[t];
		++t;
	} while (price[t - 1] != -1);
	cin >> per;
	bool flag = true;
	for (int i = 0; i < t - 2; ++i)
	{
		flag = false;
		for (int k = 0; k < t - 2 - i;++k)
		{
			if (price[k] > price[k + 1])
			{
				int temp = price[k],tmp=sale[k];
				price[k] = price[k + 1];
				price[k + 1] = temp;
				sale[k] = sale[k + 1];
				sale[k + 1] = tmp;
				flag = true;
			}
		}
		if (!flag)break;
	}
	for (int i = 0; i < t - 2; ++i)
	{
		if (m < maxlr1(price[i], sale[i], price[i + 1], sale[i + 1], price[0],expect))
			m = maxlr1(price[i], sale[i], price[i + 1], sale[i + 1], price[0],expect);
	}
	if (m < maxlr2(price[t - 2], sale[t - 2], price[0], per,expect))
		m = maxlr2(price[t - 2], sale[t - 2], price[0], per,expect);
	for (int i = 0; i < t - 2; ++i)
	{
		if (search(expect, price[i], sale[i], price[i + 1], sale[i + 1]) != -1)
		{
			exsale = search(expect, price[i], sale[i], price[i + 1], sale[i + 1]);
			break;
		}
	}
	if ((exsale * (expect - price[0]) - m) % exsale == 0)
		outer = (exsale * (expect - price[0]) - m) / exsale;
	else if (exsale * (expect - price[0]) - m < 0)
		outer = (exsale * (expect - price[0]) - m) / exsale - 1;
	else outer = (exsale * (expect - price[0]) - m) / exsale + 1;

	cout << -outer;
	return 0;
}
int maxlr1(int price1, int sale1, int price2, int sale2,int cb,int expect)
{
	int max = 0;
	int sale = sale1;
	for (int i = price1; i <= price2; ++i)
	{
		if (i == expect)
		{
			sale += (sale1 - sale2) / (price1 - price2);
			continue;
		}
		int lr = (i - cb) * sale;
		if (lr > max)
			max = lr;
		sale += (sale1 - sale2) / (price1 - price2);
	}
	return max;
}
int maxlr2(int maxprice, int maxsale, int cb, int per,int expect)
{
	int sale = maxsale,max=0;
	for (int i = maxprice;sale>0; ++i,sale-=per)
	{
		if (i == expect)continue;
		if (max < (i - cb) * sale)
			max = (i - cb) * sale;
	}
	return max;
}
int search(int expect, int price1, int sale1, int price2, int sale2)
{
	if (expect >= price1 && expect <= price2)
		return sale1 - (sale1-sale2)*(expect - price1) / (price2 - price1);
	return -1;
}