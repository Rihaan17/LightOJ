#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>

using namespace std;

long long int a[1000000];

int main()
{
    int T,i=1,j,k;
    long long int P,L;
    scanf("%d",&T);
    while(T--)
    {
        j=0;

        scanf("%lld%lld",&P,&L);

        printf("Case %d:",i++);

        for(k=1;k<=(long long int)sqrt(P-L);k++)
        {
            if((P-L)%k==0)
            {
                if(k>L)
                    a[j++]=k;
                if(((P-L)/k)>L&&a[j-1]!=((P-L)/k))
                    a[j++]=(P-L)/k;
            }
        }

        if(j==0)
            printf(" impossible");
        else
        {
            sort(a,a+j);

            for(k=0;k<j;k++)
                printf(" %lld",a[k]);
        }

        printf("\n");
    }
    return 0;
}
