# include "stdio.h"
#include "string.h"
#include "math.h"
# define N 500000
char str[N]={0};
long first[N]={0},second[N]={0};

int main()
{
    long i=1,j,n,temp,count=0,max=0;
    char s;
    scanf("%ld",&n);getchar();
    while(n--)
    {
        temp = 0,count =0,str[0]='.';
        while((s=getchar())!='\n')
        {
            temp++,str[temp]=s,count +=(s=='('?1:-1);
            if((s==')'&&str[temp-1]=='('))
            str[temp]='\0',str[temp-1]='\0',temp=temp-2;
        }
        if(strlen(str)-1==abs(count))
        {
            count>=0?first[count]++:second[-count]++;
            max=abs(count)>max?abs(count):max;
        }
        memset(str,0,sizeof(str[0])*(temp+1));
    }
    count=0;
    for(i=1;i<=max;i++)
    {
        if(first[i]!=0&&second[i]!=0) count +=first[i]<second[i]?first[i]:second[i];
    }
    printf("%ld\n",first[0]!=0?count+(first[0]/2):count);
    return 0;
}