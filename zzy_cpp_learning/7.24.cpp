#include <iostream>
using namespace std;

int add(int ,int );

void add1(int a,int b)
{
    cout<<a+b<<endl;
}



int main()
{
    cout<<"hello zzy!";
    int x,y;
    cin>>x>>y;
    int sum = add(x,y);
    add1(x,y);



    return 0;
}

int add(int a,int b)
{
    cout<<a+b<<endl;
    return a+b;
}