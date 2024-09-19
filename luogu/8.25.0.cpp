#include <bits/stdc++.h>

using namespace std;

vector<string> map44;
int l44;

void search44(int x0,int y0)
{
    int ans = 0;
    int lx = x0,rx = x0;
    int uy = y0,dy = y0;
    while(lx>=0&&rx<l44&&map44[lx][y0]==map44[rx][y0])
    {
        ans = max(ans,rx-lx+1);
        lx--;
        rx++;
    }
    while(uy>=0&&dy<l44&&map44[x0][uy]==map44[x0][dy])
    {
        ans = max(ans,dy-uy+1);
        uy--;
        dy++;
    }
    cout<<ans<<endl;
}


int main()
{
    int q;
    cin>>l44>>q;
    string str;
    for(int i=0;i<l44;++i)
    {
        cin>>str;
        map44.push_back(str);
    }
    int x,y;
    for(int i = 0;i<q;++i)
    {
        cin>>x>>y;
        search44(x-1,y-1);
    }



    return 0;
}