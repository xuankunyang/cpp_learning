#include <iostream>
using namespace std;

int main()
{
    int a[10];
    int reach;
    for(int i=0;i<10;++i)
    {
        cin>>a[i];
    }
    cin>>reach;
    int num = 0;
    int j = 0;
    while(j<10)
    {
        if(a[j]<=reach+30)
            num++;
        ++j;
    }
    
    cout<<num<<endl;
    

    return 0;
}