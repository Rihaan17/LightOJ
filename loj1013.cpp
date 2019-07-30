using namespace std;

#include<iostream>
#include<cstring>
#include<cstdio>

#define max(a,b) ((a>b)?(a):(b))
#define ull_d unsigned long long int

int dp1[35][35],l1,l2,ans1;
ull_d dp2[32][32][62];

char str1[32],str2[32];

int lcs(int x,int y)
{
        if(x>=l1||y>=l2)
                return 0;

        if(dp1[x][y]!=-1)
                return dp1[x][y];

        if(str1[x]==str2[y])
                return dp1[x][y] = 1+lcs(x+1,y+1);
        else
                return dp1[x][y] = max(lcs(x,y+1),lcs(x+1,y));
}

ull_d solve(int x, int y, int idx)
{
        if(idx==ans1)
        {
                if(x==l1&&y==l2) return 1;
                return 0;
        }

        if(dp2[x][y][idx]!=-1) return dp2[x][y][idx];

        if(x==l1) return dp2[x][y][idx] = solve(x,y+1,idx+1);
        else if(y==l2) return dp2[x][y][idx] = solve(x+1,y,idx+1);

        if(str1[x]==str2[y]) return dp2[x][y][idx] = solve(x+1,y+1,idx+1);
        return dp2[x][y][idx] = solve(x,y+1,idx+1)+solve(x+1,y,idx+1);
}

int main()
{
        int t,Case=1;
        ull_d ans2;
        scanf("%d",&t);

        while(t--)
        {
                scanf("%s%s",str1,str2);
                l1 = strlen(str1);
                l2 = strlen(str2);

                memset(dp1,-1,sizeof(dp1));
                ans1 = l1+l2-lcs(0,0);
               // cout<<l1+l2-ans1<<endl;

                memset(dp2,-1,sizeof(dp2));
                ans2 = solve(0,0,0);

                printf("Case %d: %d %llu\n",Case++,ans1,ans2);
        }

        return 0;
}
