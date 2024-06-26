#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

stack<pair<int, int>>mono_stk1;

void update(int price)
{
	int day = 1;
	while (!mono_stk1.empty() && mono_stk1.top().first <= price)
	{
		day += mono_stk1.top().second;
		mono_stk1.pop();
	}
	mono_stk1.push({ price,day });
}


int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n,x;
	cin >> n;
	vector<int>b;
	for (int i = 1; i <= n; ++i)
	{
		cin >> x;
		update(x);
		b.push_back(mono_stk1.top().second);
	}
	for (const auto& i : b)
	{
		cout << i << " ";
	}


	return 0;
}