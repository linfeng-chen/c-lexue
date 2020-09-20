//
// Created by 付与千钟 on 2020/9/14.
//
# include "stdio.h"
# include "stdlib.h"
#define N 500000
long num[N]={0},own[N]={0},pai[N]={0};
long counter=0;

long tui(long n,long began)//如果1在手上
{
    long max = 0;
    for (long i=began+1;i<=n+began;i++)
    {
         if(pai[i]!=0)max = n-pai[i]+1+i-began>max?n-pai[i]+1-began+i:max;
         else max = i-began>max?i-began:max;   
    }
    return max;
}
long continu1(long began,long n)//满足递增时是否满足后面的可用
{
    long flag=1,i;
    for(i=began;i<=n;i++)
    {
        if(own[i]==0) return 0;
        else own[pai[flag++]]++;   
    }
    return 1;
}
long charge(long n,long flag_1)//如果1在牌堆
{
    long i ;
    for(i =flag_1+1;i<=n;i++)//判断是否是递增序列
    if(pai[i]<pai[i-1]) return 0; //如果不是则把1推出，归到第一种情况
    if(i==n+1)//是递增序列，判断后面的是否可用
    {
        if(continu1(pai[i-1]+1,n)==1) return n-pai[i-1];
        else return 0;
    }
}
long tuichu1(long n)//将1推出
{
    for(long i=1;i<=n;i++)
    {
        own[pai[i]]++;
        if(pai[i]==1) return i;
    }
}
int main()
{
    long n,i,j,flag=1,flag_1=0;
    scanf("%ld",&n);
    for (long k = 1; k <=n ; k++) {
        scanf("%ld",&num[k]);
        own[num[k]]++;
    }
    for (long k = 1; k <=n;k++) 
    {
        scanf("%ld",&pai[k]);
        if(pai[k]!=k) flag=0;
        if(pai[k]==1)flag_1=k;
    }
    if (flag==1)
        printf("%ld\n",0);
    else
    {
        if(own[1]==1)printf("%ld\n",tui(n,0));//1在手上需要的次数
        else//1在牌堆中
        {
            if(charge(n,flag_1)==0)
            {
                long x1=tuichu1(n);
                counter =x1+tui(n,x1);
                printf("%ld\n",counter);
            }
            else printf("%ld\n",charge(n,flag_1));
        }
    }

    return 0;
}

