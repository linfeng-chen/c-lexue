# include"stdio.h"
#include "string.h"
#include "stdlib.h"
#define N 300000
#define M 20000

char str[N] = {0};
char target[M]={0};
int flag[M]={0};
int count[130]={0};
int main()
{
    long i,j,k,len,len1;
    gets(str);
    gets(target);
    len = strlen(str),len1 = strlen(target);

    for(i=0;i<len1;i++)
    {
        long temp=1;
        flag[len1]=0;
        j=0;
        for(k=i;k<len1+i;k++)
        {
            j=j;
            for(;j<len;j++)
            {
                if(str[j]==target[k>=len1?k-len1:k])
                {
                    flag[temp++] = j+1;
                    j=j+1;
                    break;
                }
            }
        }
        if(flag[len1]!=0)
        {
            for(k=1;k<len1;k++)
            printf("%d ",flag[k]);
            printf("%d\n",flag[k]);
            break;
        }
        //printf("%d %d\n",flag[temp-1],temp);
        if(len1>7000)
        i=i+temp-2;
        //printf("%c %d %d\n",target[i],i,temp);
    }
    
    return 0;
}