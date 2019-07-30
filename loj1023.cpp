using namespace std;

#include<iostream>
#include<cstdio>
#include<algorithm>

int factorial(int x)
{
    int i,ans=1;

    for(i=2;i<=x;i++)
        ans*=i;
    return ans;
}

char ch[27]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
int n;

void solve()
{
    int i,j,x,y;
    char temp;
    for(i=n-1;i>0;i--)
    {
        if(ch[i]>ch[i-1])
            break;
    }

    i--;

    for(j=n-1;j>i;j--)
    {
        if(ch[j]>ch[i])
            break;
    }

    temp=ch[i];
    ch[i]=ch[j];
    ch[j]=temp;

    x=i+1;
    y=n-1;

    while(x<y)
    {
        temp=ch[x];
        ch[x]=ch[y];
        ch[y]=temp;
        x++;
        y--;
    }

    for(i=0;i<n;i++)
        printf("%c",ch[i]);
    printf("\n");
}

int main()
{
    int i,t,j,k,Case=1;
    scanf("%d",&t);

    while(t--)
    {
        scanf("%d%d",&n,&k);
        printf("Case %d:\n",Case++);

        for(i=0;i<n;i++)
            printf("%c",ch[i]);
        printf("\n");

        if(n<5)
        {
            int fac=factorial(n);
            if(k<=fac)
            {
                for(i=0;i<k-1;i++)
                {
                    solve();
                }
            }
            else
            {
                for(i=0;i<fac-1;i++)
                {
                    solve();
                }
            }

        }
        else
        {
                for(i=0;i<k-1;i++)
                {
                   solve();
                }
        }
        sort(ch,ch+n);
    }

    return 0;
}




/*using namespace std;

#include<iostream>
#include<cstdio>
#include<algorithm>

int factorial(int n)
{
    int i,ans=1;

    for(i=2;i<=n;i++)
        ans*=i;
    return ans;
}

int main()
{
    char ch[27]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    int i,t,j,n,k,Case=1;
    scanf("%d",&t);

    while(t--)
    {
        scanf("%d%d",&n,&k);
        printf("Case %d:\n",Case++);

        if(n<5)
        {
            int fac=factorial(n);
            if(k<=fac)
            {
                for(i=0;i<k;i++)
                {
                    for(j=0;j<n;j++)
                    {
                        cout<<ch[j];
                    }
                    cout<<endl;
                    next_permutation(ch,ch+n);
                }
            }
            else
            {
                for(i=0;i<fac;i++)
                {
                    for(j=0;j<n;j++)
                    {
                        cout<<ch[j];
                    }
                    cout<<endl;
                    next_permutation(ch,ch+n);
                }
            }

        }
        else
        {
                for(i=0;i<k;i++)
                {
                    for(j=0;j<n;j++)
                    {
                        cout<<ch[j];
                    }
                    cout<<endl;
                    next_permutation(ch,ch+n);
                }
        }
        sort(ch,ch+n);
    }

    return 0;
}*/
