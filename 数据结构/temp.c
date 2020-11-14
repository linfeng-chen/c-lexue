# include "stdlib.h"
#include "stdio.h"
int main()
{
   float h = (float)2/(float)116;
   float sum =0;
    for(int i=0;i<=116;i++)
    {
        
        if(i==0||i==116) sum +=0.5*((float)116/(116+2*i));
        else sum +=(float)116/(116+2*i);
    }
    sum = sum*h;
    printf("%f %f\n",h,sum);
}