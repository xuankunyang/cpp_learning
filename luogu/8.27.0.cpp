#include <bits/stdc++.h>
using namespace std;

int n,c;
int a[1005],s[25];
long long ans = 0;

int dfs46(int x,int sum)
{
    if(x<=0)return sum;
    if(x<=20&&s[x]+sum<=c)return s[x]+sum;
    if(sum+a[x]>c)return dfs46(x-1,sum);
    return max(dfs46(x-1,sum),dfs46(x-1,sum+a[x]));
}

int main()
{
    cin>>n>>c;
    s[0] = 0;
    for(int i = 1;i<=n;++i)
    {
        cin>>a[i];
        if(i<=20)
            s[i] = a[i] + s[i-1];
    }
    cout<<dfs46(min(41,n),0);





    return 0;
}