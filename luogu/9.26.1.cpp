#include <bits/stdc++.h>

using namespace std;

string s;
int n;

int dp(int x)
{
    int res = 2;
    char l = s[x-1],r = s[x];
    for(int i = x-2;i>=0;--i)
    {
        if(s[i] == l)res++;
        else if(s[i] == 'w')res++;
        else break;
    }
    for(int i = x+1;i<3*n;++i)
    {
        if(s[i] == r)res++;
        else if(s[i] == 'w')res++;
        else return res;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

    cin>>n;
    cin>>s;
    s = s + s + s;
    int ans = -1;
    for(int i = n;i<2*n;++i)
    {
        if(s[i] == s[i-1])continue;
        if(s[i]!='w'&&s[i-1]!='w')
            ans = max(ans,dp(i));
        else if(s[i]=='w'&&s[i-1]!='w')
        {
            s[i] = 'r';
            ans = max(ans,dp(i));
            s[i] = 'b';
            ans = max(ans,dp(i));
            s[i] = 'w';
        }
        else if(s[i-1]=='w'&&s[i]!='w')
        {
            s[i-1] = 'r';
            ans = max(ans,dp(i));
            s[i-1] = 'b';
            ans = max(ans,dp(i));
            s[i-1] = 'w';
        }
        else 
        {
            s[i-1] = 'r',s[i] = 'b';
            ans = max(ans,dp(i));
            s[i-1] = 'b',s[i] = 'r';
            ans = max(ans,dp(i));
            s[i] = 'w',s[i-1] = 'w';
        }
    }

    if(ans == -1)ans = n;
    else if(ans > n)ans = n;
    cout<<ans;
    return 0;
    
}