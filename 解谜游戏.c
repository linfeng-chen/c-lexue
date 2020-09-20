#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define N 100000
int flag[N][18]={0};
int copy[18][18]={0};
int transfor(int m)
{
    memset(flag,0,sizeof(flag));
    for(int i=0; i<(1<<m); i++)//二进制枚举//枚举每一个状态
    {
        for(int j=0; j<m; j++)//枚举该状态下二进制的每一位数值
        {
            if(i&(1<<j))//当前状态的第i位  是否为1(存在
                flag[i][j]=1;
        }
    }
}
int copyfunc(int light[18][18],int n,int m)
{
    //复制数组
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            copy[i][j] = light[i][j];
}
int test(int light[18][18],int n,int m)
{
    int count,min=99999;

    if(n==1&&m==1&&light[1][1]==0)
    {
        printf("%d\n",0);
        return 0;
    }
    //开始按下按钮
    transfor(m);
    for(int i=0;i<(1<<m);i++)
    {
        copyfunc(light,n,m);
        count=0;
        for(int j=1;j<=m;j++)
        {
            if(flag[i][j-1]==1)
            {
                count++;
                copy[1][j] = copy[1][j]==0?1:0;
                copy[1][j+1]=copy[1][j+1]==0?1:0;
                copy[1][j-1]=copy[1][j-1]==0?1:0;
                copy[2][j]=copy[2][j]==0?1:0;
            }
        }
        for(int j=2;j<=n;j++)
        {
            for(int k=1;k<=m;k++)
            {
                if(copy[j-1][k]==1)
                {
                    count++;
                    //printf("**%d %d\n",j,k);
                    copy[j][k]=copy[j][k]==0?1:0;
                    copy[j][k+1]=copy[j][k+1]==0?1:0;
                    copy[j][k-1]=copy[j][k-1]==0?1:0;
                    copy[j-1][k]=0;
                    copy[j+1][k]=copy[j+1][k]==0?1:0;
                }
            }
        }

        for(int k=1;k<=m;k++)
        { 
            if(copy[n][k]==1) break;
            if(k==m&&copy[n][k]==0)
            {
                min = count<min?count:min;
            }
        }
    }
    printf("%d\n",min);
}
int main()
{
    int n,m,i,j,light[18][18]={0};
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        scanf("%1d",&light[i][j]);
 
    test(light,n,m);
    return 0;
}