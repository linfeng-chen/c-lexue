/*
 * @Author: LF-52 
 * @Date: 2020-09-23 20:01:12 
 * @Last Modified by: LF-52
 * @Last Modified time: 2020-09-23 21:10:49
 */
#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#define N 2000000
int du[4]={1,-1,0,0,};
int lf[4]={0,0,-1,1};
char map[102][102]={0};

char flag[102][102][50]={0};
int step[N][3]={0};
int counter[N][3]={0};
int x1,y1,x2,y2;

long bfs(int n,int m,int k)
{
    int head = 0,tail=1;
    step[1][1]=x1,step[1][2]=y1,flag[x1][y1][0]=1;//flag记录行走状态
    counter[x1][y1]=0;//时间
    do
    {
        head++;
        int time =counter[step[head][1]][step[head][2]]+1;
        for(int i=0;i<4;i++)
        {
            int x=step[head][1]+lf[i],y=step[head][2]+du[i];

            if(x>=1&&x<=n&&y>=1&&y<=m&&map[x][y]=='.')//没有怪兽的位置
            {
                if(flag[x][y][time%k]==0) //在这个时刻没有来过
                 {
                    tail++,step[tail][1]=x,step[tail][2]=y,flag[x][y][time%k]=1,counter[x][y]=time;
                    //printf("#x=%d y=%d\n",x,y);
                    if(x==x2&&y==y2)//到达终点
                    {
                        return time;
                    }
                }
            }
            if(x>=1&&x<=n&&y>=1&&y<=m&&map[x][y]=='*')//有怪兽的位置
            {
                if(time%k==0&&flag[x][y][time%k]==0){
                    tail++,step[tail][1]=x,step[tail][2]=y,flag[x][y][time%k]=1,counter[x][y]=time;
                   // printf("###time=%d x=%d y=%d tail=%d\n",time,x,y,tail);
                    if(x==x2&&y==y2) {
                        return time;
                    }
                }
            }
            
        }
    } while (head<tail);
     return -1;
}

int main()
{
    long t,i;
    scanf("%ld",&t);
    while (t--)
    {
        long n,m,k;
        scanf("%ld %ld %ld",&n,&m,&k);
        for (long i = 1; i <=n; i++)  
                scanf("%s",&map[i][1]);
        for (long i = 1; i <=n; i++)  
            for(long j=1;j<=m;j++) {
                if(map[i][j]=='S') map[i][j]='.',x1=i,y1=j;
                if(map[i][j]=='E') x2=i,y2=j,map[i][j]='.';
            }
        printf("%d\n",bfs(n,m,k));
        memset(flag,0,102*102*50);
    }
    return 0;
}