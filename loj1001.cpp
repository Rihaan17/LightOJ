using namespace std;

#include<iostream>
#include<cstring>

int main()
{
    int cheak[30],T,num;
    cin>>T;

    while(T--)
    {
        cin>>num;
        if(num>10)
        {
            cout<<num-10<<" "<<10<<endl;
        }
        else
        {
            cout<<0<<" "<<num<<endl;
        }
    }

    return 0;
}
