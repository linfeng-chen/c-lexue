#include "stdio.h"
#define N 200020

/*
int solve1(long high[],long h,long n)//超时版本，但答案可行
{
    long i,number,j;
    for(i=h;i>=1;i--)
    {   
        for(j=1;j<=n;j++)
        {
            if(high[j]<i&&high[j+1]>=i)
            {
                number++;
                //printf("i = %d,j = %d\n",i,j);
            }
           
        }
    }
    printf("%ld\n",number);
}*/
long solve2(long high[],long h,long n)//复杂度为o(n),可行版本
{
    long i,num;
    for(i=n;i>=2;i--)
    {
        if(high[i]<high[i-1]) num +=high[i-1]-high[i];
    }
    num=num+(h-high[1]);
    
    return num;
}
int main()
{
    long n,h,number,i;
    long high[N]={0};
    scanf("%ld %ld",&n,&h);
    for(i=1;i<=n;i++)
        scanf("%ld",&high[i]);
    number = solve2(high,h,n);
    printf("%ld\n",number);
    return 0;
}