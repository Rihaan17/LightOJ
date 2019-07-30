using namespace std;

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

int main()
{
    int T,arr[50005],i,x,n,w,Case=1,temp,count;
    scanf("%d",&T);

    while(T--)
    {
        scanf("%d%d",&n,&w);

        for(i=0;i<n;i++)
        {
            scanf("%d%d",&x,&arr[i]);
        }


        sort(arr,arr+n);

        x=arr[0];
        count=1;
        for(i=1;i<n;i++)
        {
            if((arr[i]-x)>w)
            {
                 count++;
                x=arr[i];
            }
        }

        printf("Case %d: %d\n",Case++,count);
    }

    return 0;
}
