using namespace std;

#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>

#define abss(x) (((x) < 0) ? - (x) : (x))

bool cmp(double a,int b)
{
    return a>b;
}

int gcd(int a,int b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}

int main()
{
    int T,x,i,Case=1,n,gs,cnt,sum;

    scanf("%d",&T);

    while(T--)
    {
        cnt=0,sum=0;;
        scanf("%d",&n);

        for(i=0;i<n;i++)
        {
            scanf("%d",&x);
            if(x<0)
                cnt++;
            sum+=abss(x);
        }

        if(cnt==n)
            printf("Case %d: inf\n",Case++);
        else
        {
            cnt=n-cnt;
            gs=gcd(sum,cnt);
            while(1)
            {
                if(gs==1)
                    break;
                sum/=gs;
                cnt/=gs;
                gs=gcd(sum,cnt);
            }

            printf("Case %d: %d/%d\n",Case++,sum,cnt);
        }


    }

    return 0;
}
