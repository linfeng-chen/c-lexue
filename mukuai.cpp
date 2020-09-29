#include "iostream"
#include "algorithm"
#define model 2147483647
using namespace std;


long dp[2020][2020]={0};
long head[2020]={0};
long number[2020] ={0};
int main()
{
    long n,a,b;
    scanf("%ld",&n);
    scanf("%ld %ld",&a,&b);
    for(long i=2;i<=n;i++)
        scanf("%ld",&number[i]);
    dp[1][a]=1,head[1] = b;
    for(long i=2;i<=n;i++){
        head[i] = number[i];
        for(long j=1;j<=2020;j++){
            long left = min(head[i-1],j),right = max(head[i-1],j);
            if(number[i]<=left){
               dp[i][right] +=dp[i-1][j];dp[i][right] %=model;     
            }
            else if(number[i]>=right){
                dp[i][left] +=dp[i-1][j]; dp[i][left] %=model;
            }
            else{
                dp[i][left] +=dp[i-1][j],dp[i][right] +=dp[i-1][j];
                dp[i][left] %=model; dp[i][right] %=model;
            }
        }

      /*  for(long j=1;j<=6;j++)
        printf("%ld ",dp[i][j]);
        printf("\n");*/
    }
    long sum = 0;
    for(long i=1;i<=2020;i++){
        sum +=dp[n][i];
        sum %=model;
    }
    printf("%ld\n",sum);
    return 0;
}