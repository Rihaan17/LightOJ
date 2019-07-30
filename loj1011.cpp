using namespace std;

#include<iostream>
#include<cstdio>
#include<string.h>
#include<stdlib.h>


#define maX(a,b) ((a>b)?(a):(b))


int Set(int N,int pos){return N=N | (1<<pos);}
//int reset(int N,int pos){return N= N & ~(1<<pos);}
bool check(int N,int pos){return (bool)(N & (1<<pos));}


int dp[1<<20];
int arr[20][20],n;
bool visited[1<<20];

int solve(int mask)
{
    int k = __builtin_popcount(mask);
    if(k==n)
    {
        return 0;
    }

    if(visited[mask])
        return dp[mask];

    int ans=0,i;

    for(i=0;i<n;i++)
    {
        if(check(mask,i)==0)
        {
            ans=maX(ans,(solve(Set(mask,i))+arr[k][i]));
        }
    }

    visited[mask]=true;
    return dp[mask]=ans;
}

int main()
{
    int T,Case=1;
    scanf("%d",&T);

    while(T--)
    {
        memset(visited,false,sizeof(visited));

        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                scanf("%d",&arr[i][j]);
        }

        printf("Case %d: %d\n",Case++,solve(0));
    }

    return 0;
}

