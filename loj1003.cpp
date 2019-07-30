using namespace std;

#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<map>

#define BLaCK 3
#define GRaY 2
#define WHiTE 1
#define SIZE 10010

#define dinka cout<<"enter"<<endl

vector<int>graph[SIZE];

bool taken[SIZE],cyc;
int check[SIZE],ans;

void cycle(int s)
{
    int i;
    check[s]=GRaY;

    for(i=0;i<graph[s].size();i++)
    {
        if(check[graph[s][i]]==GRaY)
        {
               cyc=true;
               return;
        }

        cycle(graph[s][i]);
    }
    check[s]=BLaCK;
}

void dfs(int s)
{
    int i;
    if(taken[s]==false)
    {
        for(i=0;i<graph[s].size();i++)
            dfs(graph[s][i]);
        ans++;
        taken[s]=true;
    }
}


int main()
{
    int t,i,mp,Case=1,n;
    string s1,s2;
    scanf("%d",&t);

    while(t--)
    {
        scanf("%d",&n);

        map<string,int>m;

        mp=1;
        for(i=0;i<n;i++)
        {
            cin>>s1>>s2;
            if(!m[s1])
                m[s1]=mp++;
            if(!m[s2])
                m[s2]=mp++;

            graph[m[s1]].push_back(m[s2]);
        }


        for(i=1;i<mp;i++)
            check[i]=WHiTE;

        cyc=false;

        for(i=1;i<mp;i++)
        {
            if(check[i]==WHiTE)
            {
                cycle(i);
                if(cyc)
                    break;
            }
        }

        if(cyc)
        {
            printf("Case %d: No\n",Case++);
        }
        else
        {
            memset(taken,false,sizeof(taken));

            ans=0;

            for(i=1;i<mp;i++)
            {
                dfs(i);
            }

            if(ans==mp-1)
                printf("Case %d: Yes\n",Case++);
            else
                printf("Case %d: No\n",Case++);
        }

        for(i=1;i<mp;i++)
            graph[i].clear();
    }

    return 0;
}
