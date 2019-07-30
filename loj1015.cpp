using namespace std;

#include<iostream>

bool cheaque(int x)
{
    if(x<0)
        return false;
    else
        return true;
}


int main()
{
    int T,sum,num,n,Case=1;
    cin>>T;

    while(T--)
    {
        sum=0;
        cin>>n;
        while(n--)
        {
            cin>>num;
            if(cheaque(num))
            {
                sum+=num;
            }
        }
        cout<<"Case "<<Case++<<": "<<sum<<endl;
    }
    return 0;
}
