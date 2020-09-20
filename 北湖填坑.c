#include "stdio.h"
#define N 100020
int main()
{

    long T,n,high[N],i,j,k,max_high,water,first,second,temp;
    scanf("%ld",&T);
    while(T--)
    {
        water=0;
        scanf("%d",&n);
        for(i=1;i<=n;i++)
            scanf("%ld",&high[i]);

        max_high = 0;
        first = 0;
        for(i=2;i<=n-1;i++)
        {
            if(high[i]<high[i-1])
            {
                first = i;
                //printf("@%ld\n",i);//debug
                
                for(j=i+1;j<=n;j++)
                {
                    if(high[j]>=high[first]) first = j;
                    if(high[j]>high[i-1])
                    {
                        first = j;
                        break;
                    }
                }
                //printf("j = %d\n",j);
                max_high = high[i-1]<high[first]?high[i-1]:high[first];

                //printf("*%ld %ld\n",first,max_high);//debug

                for(k=i;k<first;k++)
                    water +=max_high-high[k];

                i=k;
            }
        }
        printf("%ld\n",water);

    }
    return 0;
}