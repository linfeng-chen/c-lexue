#include "stdio.h"
#include "string.h"

int main()
{
    int T,a,b,t,k,i,j,sum=0,time=0,need=0;
    scanf("%d",&T);
    while (T--)
    {
       scanf("%d %d %d %d",&a,&b,&t,&k);
       for(i=1;i<=k;i++)
       {
            time +=t;
            if(time>b) time =time%(b);
            if(i!=k)
            {
                if(time<a)need=time;
                else if(time==a) time =0; 
                else if(a<time&&time<b)
                {
                    time = 0;
                }
                else if(time==b)
                {
                    time =0;
                }
           }
           if(time ==b) time =0;
       }
       printf("%d\n",time);
        time =0;
    }
    
    return 0;
}