#include "stdio.h"
#define N 200020

int main()
{
    long n,h,number,i,j;
    long high[N]={0};
    scanf("%ld %ld",&n,&h);
    for(i=1;i<=n;i++)
        {
            scanf("%ld",&high[i]);
            if (i>=2&&i<=n-1)
            {
                if(high[i-1]<high[i])
                number +=high[i]-high[i-1];
            }
            
        }
    number+=h-high[n];
 
    printf("%ld\n",number);

    return 0;
}