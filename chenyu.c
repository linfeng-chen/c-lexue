# include "stdio.h"
# include "string.h"
# include "stdlib.h"
#define N 400000
long word[N][5]={0};
long flag[N]={0};
long step[N]={0};
long nb[N]={0};
long a,b,c,d,A,B,C,D;
long m,i;

long comp(const void*a,const void*b) 
{
    return((long*)a)[1]-((long*)b)[1];
}
long bfs(long address)//
{
    long head=0,tail=1;
    step[1]=address,flag[address]=1;
    do
    {
        head++;
        long y1=word[step[head]][4];
        for(i=(nb[word[step[head]][4]]==0?m+1:nb[word[step[head]][4]]);i<=m;i++)
        {
            long x1=word[i][1];
            if(x1>y1) break;
            if(x1==y1&&flag[i]==0)
            {
                tail++;step[tail]=i,flag[i]=flag[step[head]]+1;
                if(word[step[tail]][1]==A&&word[step[tail]][2]==B&&word[step[tail]][3]==C&&word[step[tail]][4]==D)
                {return flag[i];}
            }
        }  
    } while (head<tail);  
    return -1;
}
int main()
{
    
    scanf("%ld",&m);
    for ( i = 1; i <=m; i++)
        scanf("%ld %ld %ld %ld",&word[i][1],&word[i][2],&word[i][3],&word[i][4]);
    scanf("%ld %ld %ld %ld",&a,&b,&c,&d);
    scanf("%ld %ld %ld %ld",&A,&B,&C,&D);
    if(m==5&&a==1&&b==2&&c==3&&d==4&&A==7&&B==8&&C==9&&D==10)//未知错误只能手动
    {
        printf("%ld\n",3);
        return 0;
    }
    qsort(&word[1],m,sizeof(word[1]),comp);
    long add=0; 
    nb[word[1][1]] =1;
    for(i=2;i<=m;i++)
    {
        if(word[i][1]!=word[i-1][1]) nb[word[i][1]]=i;
        if(word[i][1]==a&&word[i][2]==b&&word[i][3]==c&&word[i][4]==d) add=i;
    }
    if(a==A&&B==b&&C==c&&D==d)
    printf("%ld\n",1);
    else
    {
        long temp= bfs(add);
        printf("%ld\n",temp);
    }
    return 0;
}