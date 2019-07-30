/*
Author: Golam Rahman Tushar
........Aust Cse 27th batch.........
*/

//{ Template

//{ C-headers
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <climits>
#include <cfloat>
#include <cctype>
#include <cassert>
#include <ctime>
//}
//{ C++-headers
#include <iostream>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <utility>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>

using namespace std;
//}

//}
//{ Floating-points
#define EPS DBL_EPSILON
#define abs(x) (((x) < 0) ? - (x) : (x))
#define zero(x) (abs (x) < EPS)
#define equal(a,b) (zero ((a) - (b)))
#define PI 2 * acos (0.0)
//}

#define INF 1<<29
#define ll long long
#define N 10007

template <typename T>
std::string to_string(T const& value) {
    stringstream sstr;
    sstr << value;
    return sstr.str();
}
//}

template <class T> T gcd(T a,T b){if(b==0) return a;else return gcd(b,a%b);}
template <class T> T lcm(T a,T b){return (a*b)/gcd(a,b);}
template <class T> T power( T a, T b){if(b==0) return 1; T x=a;for(T i=2;i<=b;i++) a=a*x;return a;}
template <class T> T BigMod(T a,T b,T c){if(a==0) return 0;if(b==0) return 1;if(b%2==0){T x=BigMod(a,b/2,c)%c;return (x*x)%c;}else return  ((a%c)*BigMod(a,b-1,c)%c)%c;}

bool visited[N];
vector<int>graph[N], ans[N];
int disc[N], back[N], level, root;

void dfs(int u, int par) {

    visited[u] = true;
    disc[u] = back[u] = ++level;

    for(int i = 0;i<graph[u].size();i++) {

        int v = graph[u][i];
        if(v==par) continue;

        if(!visited[v]) {
            dfs(v, u);
            if(back[v]>disc[u]) {
                if(u>v) ans[v].push_back(u);
                else ans[u].push_back(v);
            }

        }
        back[u] = min(back[u], back[v]);
    }
}

int main ()
{
    freopen("input.txt","r",stdin);
    int t, u, v, m, n, i, Case = 1;
    scanf("%d",&t);

    while(t--) {
        scanf("%d",&n);
        for(i=0;i<=n;i++) {
            visited[i] = false;
            graph[i].clear();
            ans[i].clear();
        }

        for(i=0;i<n;i++) {
            char c1, c2;
            scanf("%d %c%d%c",&u,&c1,&m,&c2);
            while(m--) {
                scanf("%d",&v);
                graph[u].push_back(v);
                graph[v].push_back(u);
            }
        }

        level = 0;
        for(i=0;i<n;i++) {
            if(visited[i]==false) {
                root = i;
                dfs(i,-1);
            }
        }

        int cnt = 0;
        for(i=0;i<n;i++) {
            int temp = ans[i].size();
            if(temp>=1) {
                cnt+=temp;
                sort(ans[i].begin(), ans[i].end());
            }
        }

        printf("Case %d:\n",Case++);
        printf("%d critical links\n",cnt);
        for(i=0;i<n;i++) {
            for(int j=0;j<ans[i].size();j++) {
                printf("%d - %d\n",i, ans[i][j]);
            }
        }
    }
    return 0;
}

/*
3

8
0 (1) 1
1 (3) 2 0 3
2 (2) 1 3
3 (3) 1 2 4
4 (1) 3
7 (1) 6
6 (1) 7
5 (0)

0

2
0 (1) 1
1 (1) 0
*/
