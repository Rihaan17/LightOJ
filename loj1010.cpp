/*using namespace std;

#include<iostream>
#include<cstdio>

int main()
{
    long long int T,m,n,Case=1,ans;
    scanf("%lld",&T);

    while(T--)
    {
        scanf("%lld %lld",&m,&n);
        if(m==1||n==1)
        {
            ans=m*n;
        }
        else if(m==2||n==2)
        {
            if((m*n)<=8)
                ans=4;
            else
            {
                if(((m*n)%8)<4)
                    ans = (m*n)%8;
                else ans = 4;
                ans = (((m*n)/8)*4)+ans;
            }

        }
        else
        {
            if(m%2)
            {
                ans=((m-(m/2))*(n-(n/2)))+((m/2)*(n/2));
            }
            else
            {
                ans=(m/2)*n;
            }
        }


        printf("Case %lld: %lld\n",Case++,ans);
    }

    return 0;
}*/


#include<stdio.h>
#include<math.h>

int main()
{
    long long int T;
    int cases = 1;
    scanf("%lld",&T);
    while(T--)
    {
        long long int m,n,d,rem,ans;
        scanf("%lld%lld",&m,&n);
        if(m==1 || n==1){
            ans = m*n;
        }else if(m==2&&n==2){
            ans = m*n;
        }else if(m>2&&n>2){
            if(m%2==0 && n%2==0){
                ans = (n/2)*m;
            }else{
                ans = ((n/2)*m)+ceil((float)m/2);
            }
        }else{
            m>n?d=m:d=n;
            if(d%4==0){
                ans = d;
            }else if(d%4==3){
                ans = d+1;
            }else{
                rem = d%4;
                ans = ((d/4)*4)+(rem*2);
            }
        }
        printf("Case %d: %lld\n",cases++,ans);
    }

    return 0;
}
