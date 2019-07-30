using namespace std;

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

#define Max(a,b) ((a>b)?(a):(b))

/*bool cmp(int a,int b)
{
    return a>b;
}*/

int arr[10010],k,n,w;
int dp[110][110];

int solve(int item,int m)
{
    if(item>=n||m<=0)
        return 0;
    if(dp[item][m]!=-1)
        return dp[item][m];

    int count=0,i;

    for(i=0;i+item<n;i++)
    {
        if(arr[item]+w>=arr[item+i])
            count++;
        else
            break;
    }

    //cout<<count;

    return dp[item][m]=Max((count+solve(item+i,m-1)),solve(item+1,m));
}

int main()
{
    int T,i,x,m,Case=1,temp,j,tw,ans;
    scanf("%d",&T);

    while(T--)
    {
        memset(dp,-1,sizeof(dp));

        scanf("%d%d%d",&n,&w,&m);

        for(i=0;i<n;i++)
        {
            scanf("%d%d",&x,&arr[i]);
        }


        sort(arr,arr+n);

        printf("Case %d: %d\n",Case++,solve(0,m));
    }

    return 0;
}




 /* if(item+1<=n-1)
    {
        int temp=arr[item]-arr[k];
        cout<<item<<" "<<k<<" "<<temp<<endl;

        if(temp<=w)
            return dp[item][m]=1+solve(item+1,m);
        else if(temp==w)
            return dp[item][m]=1+solve(item+1,m-1);
        else
        {
            if(m-1==0)
                return 0;

            k=item;
            int r1=solve(item+1,m-1);
            k=item+1;
            int r2=solve(item+2,m-1);
            return dp[item][m]=max(r1,r2);solve(item,m-1);
        }


    }

    return 1;

     int max=0;

        for(k=0;k<n;k++)
        {
            int flag=k;
            ans=1+solve(k+1,m);
            cout<<ans<<" ans"<<endl;
            if(ans>max)
                max=ans;
            k=flag;
        }*/









 /*for(i=0;i<n;i++)
        {
            temp=w;
            count=1;
            for(j=i;j<n;j++)
            {
                if(j<n-1)
                    tw=arr[j]-arr[j+1];//cout<<tw<<endl;

                if(tw<=temp&&j<n-1)
                {
                    temp-=tw;
                    count++;
                }
                else
                {
                    cost[i]=count;
                    break;
                }
            }
        }*/

       /* for(i=0;i<n;i++)
            cout<<cost[i]<<" ";

            cout<<endl;*/

        //sort(cost,cost+n,cmp);

        //ans=0;

        /*for(i=0;i<m;i++)
        {
            int max=0;
            for(j=1;j<n;j++)
            {
                if(cost[j]>cost[max])
                {
                    max=j;
                }
            }
            //ans+=cost[max];
            temp=max+cost[max];
            for(int k=max;k<temp;k++)
                cost[k]=0;
            for(int k=max-1;k>=0;k--)
            {
                if(((max)-k)<cost[k])
                    cost[k]=0;
            }
        }
        count=0;

        for(i=0;i<n;i++)
        {
            if(cost[i]==0)
                count++;
        }*/


       /* for(i=0;i<m;i++)
        {
            ans+=cost[i];//cout<<cost[i]<<" ";//endl;
        }*/



// sort(cost,cost+n-1);

       /* for(i=0;i<n-1;i++)
        {
            cout<<cost[i]<<endl;
        }*/
        /*int temp,k;

        for(i=0;i<n-1;i++)
        {
            temp=w;
            for(k=i;k<n-1;k++)
            {
                temp-=cost[k];
                if(temp<=0)
                {
                    if(temp<0)
                        k--;
                   break;
                }
            }
            ans[i]=k+2-i;
        }

        for(i=0;i<n-1;i++)
            cout<<ans[i]<<endl;*/


        /*int temp=w,temp2=m;
        for(i=0;i<n-1;i++)
        {
            temp-=cost[i];
            if(temp<=0)
            {
                if(temp==0)
                    i++;
                if(temp2-1!=0)
                    i--;
                temp2--;
                //m--;
                temp=w;
            }
            if(temp2==0)
                break;
        }*/


/*int arr[10010],W,M,n,dp[10010][110];

int maximum(int a,int b)
{
    if(a>=b)
        return a;
    return b;
}

int solve(int w,int m,int i)
{
    if(w>W||m>M||i+1>n)
        return 0;
    /if(dp[w][m]!=-1)
        return dp[w][m];/

    if((w+(arr[i+1]-arr[i]))<=W)
        return 1+ solve(w+(arr[i+1]-arr[i]),m+1,i+1);

    return 0;//dp[w][m] = solve(w,m+1);
}

int main()
{
    int T,i,x,ans,Case=1;
    scanf("%d",&T);

    while(T--)
    {
        memset(dp,-1,sizeof(dp));
        scanf("%d%d%d",&n,&W,&M);

        for(i=0;i<n;i++)
        {
            scanf("%d%d",&x,&arr[i]);
        }

        sort(arr,arr+n);
        ans=0;
        for(i=0;i<n;i++)
        {
            ans = maximum(ans,solve (0,0,i));
            cout<<ans<<endl;
        }


        printf("Case %d: %d\n",Case++,ans);
    }

    return 0;
}*/
