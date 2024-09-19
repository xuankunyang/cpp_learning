#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,x;
    int ans = 0;
    cin>>n;
    for(int i = 1;i<=n;++i)
    {
        cin>>x;
        ans^=x;
    }

    cout<<ans;

    return 0;
}