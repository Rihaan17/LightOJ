using namespace std;

#include<iostream>
#include<queue>
#include<vector>
#include<cstdio>
#include<cstring>

#define max(a,b) ((a>b)?(a):(b))
#define min(a,b) ((a<b)?(a):(b))

struct data {
    int city, dist;
    bool operator < ( const data& p ) const {
        return dist > p.dist;
    }
};

vector<int>graph[510];
int dist[510],cost[510][510];
bool visited[501];

void dijkstra(int s)
{
    memset(visited,false,sizeof(visited));
    priority_queue<data>Q;
    data u,v;
    u.city=s;
    u.dist=0;
    memset(dist,-1,sizeof(dist));
    dist[s]=0;
    Q.push(u);

    while(!Q.empty())
    {
        u=Q.top();
        Q.pop();
        int i;

        for(i=0;i<graph[u.city].size();i++)
        {
            if(graph[u.city][i]==s||visited[u.city])
                continue;
            v.city=graph[u.city][i];
            v.dist=max(dist[u.city],cost[u.city][v.city]);

            if(dist[v.city]==-1)
            {
                dist[v.city]=max(dist[u.city],cost[u.city][v.city]);
                Q.push(v);
            }
            else
            {
                dist[v.city]=min(dist[v.city],max(cost[u.city][v.city],dist[u.city]));
                Q.push(v);
            }
        }
        visited[u.city]=true;
    }
}

int main()
{
    int t,Case=1,u,v,w,m,n,i;
    scanf("%d",&t);

    while(t--)
    {
        scanf("%d%d",&m,&n);
        memset(cost,0,sizeof(cost));

        for(i=0;i<n;i++)
        {
            scanf("%d%d%d",&u,&v,&w);

            if(cost[u][v]==0)
            {
                graph[u].push_back(v);
                graph[v].push_back(u);
                cost[u][v]=cost[v][u]=w;
            }
            else
            {
                cost[u][v]=cost[v][u]=min(w,cost[u][v]);
            }
        }

        int s;
        scanf("%d",&s);
        dijkstra(s);
        printf("Case %d:\n",Case++);

        for(i=0;i<m;i++)
        {
            if(dist[i]==-1)
            {
                printf("Impossible\n");
            }
            else
            {
                printf("%d\n",dist[i]);
            }
            graph[i].clear();
        }
    }

    return 0;
}
