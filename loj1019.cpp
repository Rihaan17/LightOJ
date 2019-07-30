using namespace std;

#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
#include<cstdio>
#include <utility>

#define INF 1000000500
#define min(a,b) ((a<b)?(a):(b))


vector<int>edge[205];
int cost[205],w[2000][2000],N,i;


void dijkstra (int s) {

    priority_queue<int>Q;

    for(int i=1;i<=N;i++)
        cost[i] = INF;
    cost[s] = 0;
    Q.push(s);

    while(!Q.empty())
    {
        long long int u = Q.top();
        Q.pop();

        for(i=0;i<edge[u].size();i++)
        {
            long long int v = edge[u][i];

            if(cost[v]>(cost[u]+w[u][v]))
            {
                cost[v]=cost[u]+w[u][v];
                Q.push(v);
            }
        }
    }
}

int main()
{
    int Wx,u,v,T,e,Case=1,j;
    scanf("%d",&T);

    while(T--)
    {
        scanf("%d%d",&N,&e);

        for(i=1;i<=1010;i++)
        {
            for(j=1;j<=1010;j++)
                if(i!=j)
                    w[i][j] = INF;
                else
                    w[i][j] = 0;
        }
        for(i=1;i<=e;i++)
        {
            cin>>u>>v>>Wx;

            if(w[u][v]!=INF)
            {
                if(w[u][v]>Wx)
                {
                     w[u][v]=Wx;
                     w[v][u]=Wx;
                }

            }
            else
            {
                edge[u].push_back(v);
                edge[v].push_back(u);

                w[u][v]=Wx;
                w[v][u]=Wx;
            }

        }

        dijkstra(1);


        if(cost[N]==INF)
            printf("Case %d: Impossible\n",Case++);
        else
            printf("Case %d: %d\n",Case++,cost[N]);
        }

        for(i=1;i<=N;i++)
            edge[i].clear();



    return 0;
}


















/*
//Author : Rezwanul Islam Maruf
//AUST ,CSE
//25-th batch..
*/
/*
#include <stdio.h>
#include <iostream>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <string>
#include <string.h>
#include <queue>
#include <vector>
#include <stack>
#include <map>
#include <list>
#include <cstdlib>
#include <sstream>
#include <set>

#define FOR(i,n) for(i=1;i<=n;i++)
#define REP(i,n) for(i=0;i<n;i++)
#define init(i,a,n) for(i=0;i<n;i++)a[i]=i
#define INF 1000000500
#define ms0(a) memset(a,0,sizeof(a))
#define msn(a,n) memset(a,n,sizeof(a))
#define i64  long long
#define u64 unsigned long long
#define DB double
#define LD long double
#define eps 1e-6
#define SQR(x) ((x)*(x))
#define pb push_back
#define all(x) sort(x.begin(),x.end())
#define Reverse(x) reverse(x.begin(),x.end())

#define II ({int a; scanf(" %d", &a); a;})
#define SS(s) scanf("%s",&s)
#define DD ({DB a; scanf(" %lf", &a); a;})
#define LL  ({i64  a; scanf(" %lld", &a); a;})
#define LU  ({u64  a; scanf(" %llu", &a); a;})
#define CS printf("Case %d: ",cs++)
#define PI 3.1415926535897932384626433832795
#define NP next_permutation
#define PP prev_permutation
#define mp make_pair
#define PII pair <int , int>
#define SI set<int>
#define ins insert

#define FRD freopen("in.txt", "r", stdin)
#define FWR freopen("out.txt", "w", stdout)



int aComp(const void * a, const void * b){return (*(int*)a-*(int*)b );}
int dComp(const void * a, const void * b){return (*(int*)b-*(int*)a );}
//qsort (array,size, sizeof(int), aComp);


//Debugger
#define debug_matrix(mat,row,col)for(int i=0;i<row;i++){for(int j=0;j<col;j++) cout<<mat[i][j]<<" ";cout<<endl;}
#define debug_val(x) cout<<x<<endl
#define debug_arr(x,n){for(int i=0;i<=n;i++){if(i)cout<<" ";cout<<x[i];}cout<<endl;}
#define forstl(i,n) for(__typeof((n).begin())i =(n).begin();i!=(n).end();i++)

int cs=1;
//

using namespace std;

struct EDGE{
    int node ,cost;
    EDGE (int a ,int b){
        node = a;
        cost = b;
    }
    bool operator < ( const EDGE &x) const{
        return  x.cost < cost ;
    }
};

vector< EDGE >edges[ 205 ];
int n ,m ,dist[ 205 ];

void DJ( int source )
{
    int i ;
    FOR( i,n) dist[ i ] =INF ;
    dist[ source ] = 0;
    priority_queue< EDGE >Q ;
    Q.push( EDGE(source , 0 ) );
    while( !Q.empty())
    {
      int currPos  = Q.top().node ;
      int currCost = Q.top().cost ;
      Q.pop();
      REP( i , edges[currPos].size() ){
        int nxtPos  = edges[currPos][i].node ;
        int nxtCost = edges[currPos][i].cost ;

        if( dist[ currPos ] + nxtCost < dist[ nxtPos ] ){
            dist[ nxtPos ] = dist[ currPos ] + nxtCost ;
            Q.push( EDGE( nxtPos , dist[nxtPos] ) );
        }
      }
    }
}


int main()
{
    int i,test = II ;
    while(test--){
        n = II , m = II ;
        REP(i,m){
            int u = II , v = II , w = II ;
            edges[ u ].pb( EDGE(v,w) );
            edges[ v ].pb( EDGE(u,w) );
        }
        DJ(1);CS ;

        if( dist[ n ] == INF )puts( "Impossible" );
        else    cout << dist[ n ] << endl ;

        FOR(i,n){
            edges[ i ].clear();
        }

    }
}
*/
