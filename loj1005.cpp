using namespace std;

#include<iostream>
#include<cstring>
#include<cstring>
#include<cstdio>
#include<algorithm>

typedef long long int ll_d;

ll_d dp[55][902];
int n,k;

ll_d solve(int row, int cnt)
{
        if(cnt==k) return 1;
        if(row<=0) return 0;

        if(dp[row][cnt]!=-1) return dp[row][cnt];

        ll_d r1,r2;

        r1 = solve(row-1,cnt+1)*(n-cnt);
        r2 = solve(row-1,cnt);

        return dp[row][cnt] = r1+r2;
}

int main()
{
        int t,Case=1;
        scanf("%d",&t);

        while(t--)
        {
                 memset(dp,-1,sizeof(dp));
                scanf("%d %d",&n,&k);
                printf("Case %d: %lld\n",Case++,solve(n,0));
        }

        return 0;
}
