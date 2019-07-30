using namespace std;

#include<iostream>
#include<cstdio>
#include<cstring>

#define max(a,b) ((a>b)?(a):(b))

long long int dp[205][105],arr[205][105];
int n;

long long int solve(int i,int j)
{
    if(i>=2*n)
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];

    if(i<n)
    {
        return dp[i][j]=max(solve(i+1,j)+arr[i][j],solve(i+1,j+1)+arr[i][j]);
    }

    else
    {
        if(j==0)
            return dp[i][j]=solve(i+1,j)+arr[i][j];
        else if(j==(2*n)-i-1)
            return dp[i][j]=solve(i+1,j-1)+arr[i][j];
        else
            return dp[i][j]=max(solve(i+1,j-1)+arr[i][j],solve(i+1,j)+arr[i][j]);
    }
}

int main()
{
    int T,i,j,Case=1;
    scanf("%d",&T);

    while(T--)
    {
        scanf("%d",&n);

        memset(dp,-1,sizeof dp);

        for(i=1;i<=n;i++)
        {
            for(j=0;j<i;j++)
                scanf("%lld",&arr[i][j]);
        }

        for(i=n+1;i<2*n;i++)
        {
            for(j=0;j<(2*n)-i;j++)
                scanf("%lld",&arr[i][j]);
        }

        printf("Case %d: %lld\n",Case++,solve(1,0));
    }

    return 0;
}
