#include "stdio.h"
#include "stdlib.h"
#define N 10000

long dp[2020][2020]={0};
int main()
{
    long n,v;
    scanf("%ld %ld",&n,&v);
    dp[0][0] =1;
    for(long i=1;i<=n;i++)
    {
        long temp;
        scanf("%ld",&temp);
        for(long j=0;j<v;j++)
        {
            dp[i][j] +=dp[i-1][j];//不选择当前物品时
            dp[i][j] %= 10000000;
            long k= (j+temp)%v;//选择了当前物品
            dp[i][k] +=dp[i-1][j];
            dp[i][k] %=10000000;
        }

    }
    printf("%ld\n",(dp[n][0]-1)%10000000);
        

    return 0;
}