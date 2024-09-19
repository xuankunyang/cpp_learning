#include <bits/stdc++.h>
using namespace std;

vector<int> a,dp1,dp2;


int main()
{
    int x;
    while (cin>>x)
    {
        a.push_back(x);
    }
    reverse(a.begin(),a.end());

    
    for(int i = 0;i<a.size();++i)
    {
        int p = upper_bound(dp1.begin(),dp1.end(),a[i]) - dp1.begin();
        if(p == dp1.size())
        {
            dp1.push_back(a[i]);
        }
        else
        {
            dp1[p] = a[i];
        }    
    }
    
    reverse(a.begin(),a.end());
    
    cout<<dp1.size()<<endl;
    for(int i = 0;i<a.size();++i)
    {
        int p = lower_bound(dp2.begin(),dp2.end(),a[i]) - dp2.begin();
        if(p == dp2.size())
        {
            dp2.push_back(a[i]);
        }
        else
        {   
            dp2[p] = a[i];
        }
    }
    cout<<dp2.size()<<endl;

    return 0;
}