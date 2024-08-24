#include <bits/stdc++.h>

using namespace std;

const int p[] = {0,3,5,7,11,13,17,19,23,29,31,37};
const int d[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
int a[100];
int primes[100000];
int tot = 0,t = 0,T;
char s[10];

bool is_prime(int x)
{
    for (int i=2;i*i<=x;++i)
    {
        if(x % i == 0)return 0;
    }
    return 1;
}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    for(int i = 1;i<=12;++i)
    {
        for(int j=1;p[j] <= d[i];++j)
        {
            if(is_prime(i*100+p[j]))
                a[++t] = i*100+p[j];
        }
    }
    for(int i = 4;i<=9999;i+=4)
    {
        if((i%100||!(i%400)) && is_prime(i*10000+229))
            primes[++tot] = i*10000+229;
    }
    cout<<t<<endl;
    for (int i = 1;i<=9999;++i)
    {
        for(int j = 1;j<=t;++j)
        {
            if(is_prime(i*10000+a[j]))
                primes[++tot] = i*10000+a[j];
        }
    }
    cout<<tot<<endl;

    cin>>T;
    while(T--)
    {
        cin>>(s+1);
        int cnt = 0;
        for(int i = 1;i<=tot;++i)
        {
            int now =primes[i],flag = 1;
            for(int j = 8;flag&&j;--j,now/=10)
            {
                if(s[j] != '-' && s[j] - '0' != (now % 10))
                    flag=0;
            }
            cnt += flag;
        }
        cout<<cnt<<endl;
    }



    return 0;
}