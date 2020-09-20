#include "stdio.h"
#include "math.h"


int main()
{
    unsigned long long n,winenumber,i;
    scanf("%lld",&n);
    
    while (n--)
    {
        scanf("%lld",&winenumber);
        for(i=0;;i++)
        {
            if (pow(2,i)>=winenumber) break;
        }
        printf("%lld\n",i);
    
    }
    
    return 0;
}