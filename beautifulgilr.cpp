#include <iostream>
#include "cstring"
#include "algorithm"
using namespace std;

const long long N=600000;
long long dp[4][N]={0},number[N];


int main()
{
    long long n;
    scanf("%lld",&n);
    for(long long i=1;i<=n;i++)
        scanf("%lld",&number[i]);
    
    for (long long i = 1; i <= 3; i++)
    {
        long long max_up = -(1<<30);
        //printf("%ld\n",max_up);
        for(long long j=i;j<=n;j++)
        {
            
            if(i==j) dp[i][j] = dp[i-1][j-1]+number[j];
            else
            {
                max_up = max(dp[i-1][j-1],max_up);
                dp[i][j] = max(dp[i][j-1],max_up) + number[j];
            }
        }
    }
    long long need = -(1<<30);
        for(long long i=3;i<=n;i++)
    if(dp[3][i]>=need) need = dp[3][i];

    printf("%lld\n",need);
    

    return 0;
}