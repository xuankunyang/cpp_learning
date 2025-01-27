#include <bits/stdc++.h>

using namespace std;

int a[100005];
int n;

int main()
{
    ios::sync_with_stdio(0),cin.tie(0), cout.tie(0);

    cin>> n;

    long long total_profit = 0;

    priority_queue<int, vector<int>, greater<int>> prices;

    for(int i = 1; i <= n; ++i)
    {
        cin>>a[i];
        if(prices.size())
        {
            int min_price = prices.top();
            if(a[i] > min_price)
            {
                total_profit += (a[i] - min_price);
                prices.pop();
                prices.push(a[i]);
            }
        }
        prices.push(a[i]);
    }

    cout << total_profit;
    
    

  
    



    return 0;
}