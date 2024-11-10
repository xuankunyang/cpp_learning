#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> a,t;
int tt[1000005];

vector<int> count(vector<int>left,vector<int>right)
{
    if(left[left.size()-1]<right[0])
    {
        for(auto i:right)
        {
            left.push_back(i);
        }
        return left;
    }
    if(left[0]>right[right.size()-1])
    {
        vector<int>res;
        for(auto i:right)
        {
            t[i] += left.size();
            res.push_back(i);
        }
        for(auto i :left)
        {
            t[i] += right.size();
            res.push_back(i);
        }
        return res;
    }
    int i = 0,j = 0;
    vector<int> res;
    while(i<left.size()&&j<right.size())
    {
        if(left[i]>right[j])
        {
            t[right[j]] += (left.size()-i);
            res.push_back(right[j++]);
        }
        else
        {
            t[left[i]] += j;
            res.push_back(left[i++]);
        }
    }
    if(i<left.size())
    {
        while(i<left.size())
        {
            res.push_back(left[i]);
            t[left[i++]] += right.size();
        }
    }
    else if(j<right.size())
    {
        while(j<right.size())
        {
            res.push_back(right[j++]);
        }
    }
    return res;
}

vector<int> solve(int lh,int rh)
{
    if(lh == rh-1)
    {
        vector<int> res;
        res.assign(a.begin()+lh,a.begin()+rh);
        return res;
    }
    int mid = (rh+lh)/2;
    vector<int>up_left,up_right;
    up_left = solve(lh,mid);
    up_right = solve(mid,rh);
    return count(up_left,up_right);
}



int main()
{
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n;
    int x;
    for(int i = 0;i<n;++i)
    {
        cin>>x;
        a.push_back(x);
        t.push_back(0);
    }
    t.push_back(0);
    solve(0,n);
    
    
    for(int i = 1;i<t.size();++i)
    {
        cout<<t[i]<<" ";
    }
    
    



    return 0;
}