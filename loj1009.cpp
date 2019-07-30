using namespace std;

#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>

#define max(a,b) ((a>b)?(a):(b))

vector<int>graph[20010];

bool visited[20010];
int num[20010];

int solve(int s)
{
    int g,l=0;
    queue<int>Q;
    Q.push(s);
    visited[s]=true;
    num[s]=0;
    g=1;

    while(!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        int temp = (num[u]+1)%2;

        for(int i=0;i<graph[u].size();i++)
        {
            if(visited[graph[u][i]]==false)
            {
                num[graph[u][i]] = temp;
                visited[graph[u][i]]=true;

                if(temp==0) g++;
                else l++;

                Q.push(graph[u][i]);
            }
        }
    }

    return max(g,l);
}

int main()
{
    int t,n,i,source[10010],k,u,v,Case=1;
    scanf("%d",&t);

    while(t--)
    {
        k=0;
        scanf("%d",&n);
        memset(visited,false,sizeof(visited));

        for(i=0;i<n;i++)
        {
            scanf("%d%d",&u,&v);

            graph[u].push_back(v);
            graph[v].push_back(u);

            if(visited[u]==false&&visited[v]==false)
            {
                source[k++]=u;
            }

            visited[u]=visited[v]=true;
        }

        memset(visited,false,sizeof(visited));
        int ans=0;

        for(i=0;i<k;i++)
        {
            if(visited[source[i]]==false)
            {
                ans+=solve(source[i]);
            }
        }

        printf("Case %d: %d\n",Case++,ans);

        for(i=0;i<20005;i++)
            graph[i].clear();
    }

    return 0;
}
