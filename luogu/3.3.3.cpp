#include <iostream>
#include <iomanip>
using namespace std;
double a14, b14, c14, d14;
double f(double x)
{
	return a14 * x * x * x + b14 * x * x + c14 * x + d14;
}

int main()
{
	ios::sync_with_stdio, cin.tie(0), cout.tie(0);
	cin >> a14 >> b14 >> c14 >> d14;
	int s = 0;
	double lh, rh;
	for (int i = -100; i < 100; ++i)
	{
		lh = i;
		rh = i + 1;
		double y1 = f(lh), y2 = f(rh);
		if (!y1)
		{
			cout << setprecision(2)<<fixed<<lh << " ";
			s++;
		}
		if (y1 * y2 < 0)
		{
			while (rh - lh >= 0.001)
			{
				double mid = (rh + lh) / 2;
				if (f(mid) * f(rh) <= 0)lh = mid;
				else rh = mid;
			}
			cout << setprecision(2) << fixed << rh << " ";
			s++;
		}
		if (s == 3)break;
		
	}
	



	return 0;
}