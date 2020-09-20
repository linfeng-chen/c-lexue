# include "stdio.h"
# include "string.h"
#include "math.h"
#define N 100000
long num[N]={0};
int flag[N]={0};
unsigned char need[N][3];
long  transfor(long first,long second,long three,long n)
{
    if(n==2)
    {
         num[first*(1<<6)+second]++,flag[first*(1<<6)+second]=2;
         return first*(1<<6)+second;
    }
    if(n==3)
    {
        num[first*(1<<12)+second*(1<<6)+three]++;
        flag[first*(1<<12)+second*(1<<6)+three]=3;
        return first*(1<<12)+second*(1<<6)+three;
    }
}
int print(long num,long unicode)
{
    if(num==2)
    {
        printf("%c%c",need[unicode][0],need[unicode][1]);
    }
    if(num==3)
    {
        printf("%c%c%c",need[unicode][0],need[unicode][1],need[unicode][2]);
    }  
}
int main()
{
    unsigned char s1,s2,s3;
    long number,i;

    printf("%d\n",' '<<6);
    while ((s1=getchar())!=255)
    {
        if(s1>=192&&s1<=223)
        {
            s2=getchar();
            number = transfor(s1&31,s2&63,0,2);
            need[number][0]=s1,need[number][1]=s2;
        }
        else if(s1>223)
        {
            s2=getchar();
            s3=getchar();
            printf("%d %d %d\n",s1,s2,s3);
            number = transfor(s1&31,s2&63,s3&63,3);
            need[number][0]=s1,need[number][1]=s2,need[number][2]=s3;
        }
    }
    long count=0;
    for (i = 0; i < 100000; i++)
    {
        if(num[i]>=2)
        {
            count++;
            print(flag[i],i);
            printf(" 0x%04x %ld\n",i,num[i]);
        }
    }
    if(count==0)printf("No repeat!\n");
    return 0;
}