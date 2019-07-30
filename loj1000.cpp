using namespace std;

#include<iostream>

int main()
{
    int a,b,T,Case=1;
    cin>>T;

    while(T--)
    {
        cin>>a>>b;
        cout<<"Case "<<Case++<<": "<<a+b<<endl;
    }
    return 0;
}
