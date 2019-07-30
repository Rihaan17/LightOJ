using namespace std;

#include<iostream>
#include<cstring>
#include<cstdio>





/*using namespace std;

#include<iostream>
#include<cstring>
#include<cstdio>

#define max 10000+5

int arr[max];

int function(int n)
{
    if(arr[n]!=-1)
    {
        return arr[n];
    }
    else
        return arr[n] = ( function(n-1) % 10000007  + function(n-2)  % 10000007+ function(n-3)  % 10000007+ function(n-4)  % 10000007+ function(n-5) % 10000007 + function(n-6)  % 10000007);
}

int main()
{
    int T,n,Case=1,a,b,c,d,e,f;
    scanf("%d",&T);

    while(T--)
    {
        memset(arr,-1,sizeof arr);
        scanf("%d %d %d %d %d %d %d", &a, &b, &c, &d, &e, &f, &n);

        arr[0]=a;
        arr[1]=b;
        arr[2]=c;
        arr[3]=d;
        arr[4]=e;
        arr[5]=f;
        printf("Case %d: %d\n", Case++, function(n) % 10000007);
    }
    return 0;
}*/
