using namespace std;

#include<iostream>
#include<queue>
#include<cstring>
#include<cstdio>

struct info
{
    int x,y;
};

queue<info>Q;

char place[22][22];
int w,h,val[22][22];

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

bool validity(int x,int y)
{
    if(x>=0&&x<h&&y>=0&&y<w&&place[x][y]=='.'&&val[x][y]==0)
        return true;
    return false;
}


int main()
{
    int T,i,j,rx,ry,sx,sy,ans,Case=1;

    scanf("%d",&T);

    while(T--)
    {
        ans=0;
        scanf("%d%d",&w,&h);

        for(i=0;i<h;i++)
        {
            scanf("%s",place[i]);
        }

        info run,temp;
        memset(val,0,sizeof(val));


        while(!Q.empty())
            Q.pop();

        for(i=0;i<h;i++)
        {
            for(j=0;j<w;j++)
            {
                if(place[i][j]=='@')
                {
                    sx=i;
                    sy=j;
                }
            }
        }

        temp.x = sx;
        temp.y = sy;

        Q.push(temp);

        while(!Q.empty())
        {
            run = Q.front();
            Q.pop();

            for(i=0;i<4;i++)
            {
                rx = run.x+dx[i];
                ry = run.y+dy[i];

                if(validity(rx,ry))
                {
                    temp.x=rx;
                    temp.y=ry;
                    val[rx][ry]=1;

                    ans++;

                    Q.push(temp);
                }
            }
        }

        printf("Case %d: %d\n",Case++,ans+1);
    }

    return 0;
}



/*shakil solution by dfs(recursively)

#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
char maze[22][22];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int count,row,col;
void dfs(int x,int y)
{  maze[x][y]='#';
   for(int i=0;i<4;i++)
   { int nx=dx[i]+x;
     int ny=dy[i]+y;
    if(nx>=0 && ny>=0 && nx<row && ny<col && maze[nx][ny]=='.') { dfs(nx,ny);count++;}
   }
}

int main()
{  int T;
   cin>>T;
   for(int tt=1;tt<=T;tt++)
   {  count=1;
      cin>>col>>row;
      for(int i=0;i<row;i++) scanf("%s",maze[i]);
      for(int i=0;i<row;i++)
          for(int j=0;j<col;j++) if(maze[i][j]=='@') dfs(i,j);
      printf("Case %d: %d\n",tt,count);
   }
 return 0;
}*/
