#include <stdio.h>
#include <stdlib.h>
#include "string.h"

#define N 1000000

char num[17][17]={0};
char spin[5][5];//用来存放旋转之后的数据
int stepp[5][5]={0};//存放旋转的次数
int min=99999; 
int last[5][5]={0};

int spin_s(int n, int m){
    //将方块旋转,并判断是否合法
    //n，m表示第几行第几个
    int temp[5][5];//临时变量用于取出需要旋转的部分
    int a=1,b=1;
    //还没有被旋转过就从原数组中取出
    for(int i=(n-1)*4+1;i<=n*4;i++){
    for(int j=(m-1)*4+1;j<=m*4;j++){
            if(b>4)b=1;
            temp[a][b++] = num[i][j];
        }
        a++;
    } 
    a=1;//旋转
    for(int j=4;j>=1;j--){
        for(int i=1;i<=4;i++)
        spin[a][i] = temp[i][j];
        a++;
    }
    a=1,b=1;//放回原数组
    for(int i=(n-1)*4+1;i<=n*4;i++){
    for(int j=(m-1)*4+1;j<=m*4;j++){
            if(b>4)b=1;
            num[i][j] = spin[a][b++];
        }
        a++;
    } 
}

int ok(int n,int m)//判断行列是否出现相同数
{
    int flag[200]={0};
    for(int i=(n-1)*4+1; i<=n*4; i++)
    {
        for(int j=1;j<=m*4;j++)
        {
            flag[num[i][j]]++;
            if(flag[num[i][j]]==2)return -1;//出现两个相同的数，则不可以
        }
        memset(flag,0,sizeof(flag));
    }
    int flag1[200]={0};
    for(int j=(m-1)*4+1;j<=m*4;j++)
    {
        for(int i=1; i<=n*4; i++)
        {
            flag1[num[i][j]]++;
            if(flag1[num[i][j]]==2) return -1;//出现两个相同的数，则不可以
        }
        memset(flag1,0,sizeof(flag1));
    }
    return 1;
}
int dfs(int n,int m,int step)
{
    if(m==5)n++,m=1;
    if(n>4) return 0;
    for(int i=0; i<=3 ;i++)
    {
        if(i!=0)spin_s(n,m),step++,stepp[n][m]++;
        //printf("i=%d,n=%d,m=%d\n",i,n,m);
        if(ok(n,m)==1) 
        {
            if(n==4&&m==4)
            {
                if(step<min) copy(step);
                if(i!=0)
                for(int j=4-i; j>=1;j--)spin_s(n,m);//最后一块如果被动过，我们也需要将其还原回来
                stepp[n][m]=0;
                return 0;
            }
            dfs(n,m+1,step);
        }
    }
    spin_s(n,m),stepp[n][m]=0;//当旋转3次都不行，那我们需要将它再旋转一次回到开始状态
    return ;
}
//保存他的最小步数状态
void copy(int minx){
    min = minx;
    for(int i=1;i<=4;i++)
     for(int j=1;j<=4;j++)
      last[i][j] = stepp[i][j];

}
//打印数据
void view(int step){
    printf("%d\n",step);
    for(int i=1;i<=4;i++)
     for(int j=1;j<=4;j++)
     for(int k=last[i][j];k>=1;k--)
     printf("%d %d\n",i,j);
}
int main(){
    int t;
    scanf("%d",&t);
    getchar();
    while (t--){
        for(int i=1;i<=16;i++)
        {
            for (int j=1;j<=16;j++)
            num[i][j]=getchar();
                getchar();
        }
        dfs(1,1,0);
        view(min);
        min=999999,memset(stepp,0,sizeof(stepp));
    }

    return 0;
}