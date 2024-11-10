#include <bits/stdc++.h>

using namespace std;

int n;
vector<pair<int,int>> points;
const double inf = 1e9;

double distance(pair<int,int>a,pair<int,int>b)
{
    return sqrt(pow(a.first-b.first,2)+pow(a.second-b.second,2));
}

double count_C(pair<int,int>a,pair<int,int>b,pair<int,int>c)
{
    return distance(a,b) + distance(a,c) + distance(b,c);
}

double merge(vector<pair<int,int>>points,double min_dis)
{
    if(points.size() == 3)
    {
        return count_C(points[0],points[1],points[2]);
    }
    sort(points.begin(),points.end(),[](auto u,auto v){return u.second < v.second;});
    for(int i = 0;i<points.size()-2;++i)
    {
        for(int j = i+1;j<points.size()-1;++j)
        {
            if(distance(points[i],points[j]) >= 3*min_dis)//sqrt(17)/2，画图看
            {
                break;
            }
            for(int k = j+1;k<points.size();++k)
            {
                double dis = count_C(points[i],points[j],points[k]);
                if(dis >= min_dis)
                {
                    break;
                }
                min_dis = min(min_dis,dis);
            }
        }
    }
    return min_dis;
}

double solve(int lh,int rh)
{
    if(rh-lh<=3)
    {
        return inf;
    }
    int mid = (lh+rh)/2;
    double min_dis = inf;
    min_dis = min(min_dis,solve(lh,mid));
    min_dis = min(min_dis,solve(mid,rh));
    vector<pair<int,int>> gap;
    for(int i = lh;i<rh;++i)
    {
        if(abs(points[i].first - points[mid].first)<min_dis/2)
        {
            gap.push_back(points[i]);
        }
    }
    if(gap.size()<3)
    {
        return min_dis;
    }
    double gap_dis = merge(gap,min_dis);
    return min(gap_dis,min_dis);
}



int main()
{
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int x,y;
    cin>>n;
    for(int i = 0;i<n;++i)
    {
        cin>>x>>y;
        points.push_back(make_pair(x,y));
    }
    sort(points.begin(),points.end());

    cout<<setprecision(9)<<fixed<<solve(0,n);


    return 0;
}