using namespace std;

#include<iostream>
#include<cstdio>
#include<cmath>

typedef unsigned long long int ull_d;

#define N 5000000+10
bool prime[N];
ull_d phi[N];

void phi_value(ull_d x)
{
        for(ull_d i = x;i<=N;i+=x)
        {
                if(phi[i]==0)
                        phi[i]=i;
                phi[i] *= (x-1);
                phi[i] /= x;
        }
}

void sieve()
{
        ull_d i,j;
        int sq = (int)sqrt(N);
        prime[2]=true;
        phi_value(2);

        for(i=3;i<=sq;i+=2)
        {
                if(prime[i]==false)
                {
                        phi_value(i);
                        for(j=i*i;j<=N;j+=2*i)
                                prime[j]=true;
                }
        }

        for(;i<=N;i+=2)
                if(prime[i]==false)
                   phi_value(i);
}

void sum()
{
        ull_d i;
        for(i=2;i<=N;i++)
                phi[i] = (phi[i]*phi[i]+phi[i-1]);
}

int main()
{
        int Case=1,t;
        ull_d a,b;
        sieve();
        sum();
        scanf("%d",&t);

        while(t--)
        {
                scanf("%llu%llu", &a, &b);
                printf("Case %d: %llu\n",Case++,phi[b]-phi[a-1]);
        }

        return 0;
}
