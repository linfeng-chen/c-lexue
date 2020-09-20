#include "stdio.h"
#define N 200020

int main()
{
    long n,h,number,i,j;
    long high[N]={0};
    scanf("%ld %ld",&n,&h);
    for(i=1;i<=n;i++)
        scanf("%ld",&high[i]);
    for(i=n;i>=2;i--)
    {
        if(high[i]<high[i-1]) number +=high[i-1]-high[i];
    }
    number +=h-high[1];
    printf("%ld\n",number);

    return 0;
}