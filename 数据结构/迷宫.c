#include <stdio.h>
#include <stdlib.h>
int x[4]={1,-1,0,0,};
int y[4]={0,0,-1,1};
int mi[101][101]={0};
int n,m,t=0;
int num[101][101]={0}; 
int step[10000][3]={0};

//垃圾题目
//深搜不可，广搜可。
void dfs(int x0,int y0,int counter)
{
	if(x0==n&&y0==m)
	{
        ++t;
        if(t==1){
            for (int i = 1; i <counter; i++)
                printf("<%d,%d> ",step[i][1],step[i][2]);
            printf("\n");
        }
        return ;
	}
	for(int i=0;i<4;i++)
	{
		int a1=x0+x[i], a2=y0+y[i];
		if(a1>=1&&a1<=n&&a2>=1&&a2<=m&&mi[a1][a2]==0&&num[a1][a2]==0)
		{
			num[a1][a2]=1;
            step[counter][1] = a1,step[counter][2] = a2;
			dfs(a1,a2,counter+1);
			num[a1][a2]=0;	
		}
	}
	return;
} 

int bfs(int a0,int b0)
{
    int head = 0,tail=1,i;
    int need[1000][3]={0};
    step[1][1]=a0,step[1][2]=b0,num[a0][b0]=1,step[1][0]=0;//num记录行走状
    do
    {
        head++;
        for(i=0;i<4;i++)
        {
            int x_=step[head][1]+x[i];
            int y_=step[head][2]+y[i];
            if(x_>=1&&x_<=n&&y_>=1&&y_<=m&&num[x_][y_]==0&&mi[x_][y_]==0)//
            {
                tail++,step[tail][1]=x_,step[tail][2]=y_,num[x_][y_]=1,step[tail][0]=head;
                if(x_==n&&y_==m)//到达终点
                {
                    int count=1;
                    int temp = step[tail][0];
                    while (temp!=0)
                    {
                        need[count][1] =step[temp][1],need[count++][2]=step[temp][2]; 
                        temp = step[temp][0];
                    }
                    while (count-1)
                    {
                        printf("<%d,%d> ",need[count-1][1],need[count-1][2]);
                        count--;
                    }
                    printf("<%d,%d> \n",n,m);
                    return 1;
                }
            }
            
        }
    } while (head<tail);
     return -1;
}
int main() {
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
	{
        int temp;
		for(int j=1;j<=m;j++)
        {
            scanf("%d",&temp);
            if(temp==1)
            mi[i][j]=1;//表示有障碍 
        }
	}
    num[1][1]=1;
    step[1][1]=1,step[1][2]=1;
    //dfs(1,1,2);
    //if(t==0)printf("There is no solution!\n");
    int final = bfs(1,1);
    if(final==-1)
    printf("There is no solution!\n");
	return 0;
}