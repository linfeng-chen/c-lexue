# include "stdio.h"
# include "string.h"

#define N 100000
int step[60]={0};
int step1[60]={0};
int n,m,x,y;
long long number=0;

int dfs1(int sum,int set)//敌方
{
    if(set>n)return 0;
    for(int i=0;i<=sum;i++)
    {
        step1[set] = i;
        sum -=i;
        if(sum>=0) dfs1(sum,set+1);
        if(sum==0&&set==n)
        {
            //prin1();
            if(compare()==1)number++,number=number%998244353;
        }
        sum+=i;
    } 
}
int dfs(int sum,int set)//我方
{
    if(set>n) return 0;
    for(int i=0;i<=sum;i++)
    {
        step[set] = i;
        sum -=i;
        if(sum>=0) dfs(sum,set+1);
        if(sum==0&&set==n) 
        {
            // prin();
            dfs1(y,1);
        }
        sum+=i;
    }
}

int compare()
{
    int counter =0;
    for(int i=1;i<=n;i++)
    if(step[i]>step1[i]) counter +=3;
    else if(step[i]==step1[i]) counter+=1;
   // printf("%d\n",counter);
    if(counter>=m) return 1;
    else return 0;
}


int prin()
{
        for(int j=1;j<=n;j++)
        printf("%d ",step[j]);
        printf("\n");
}
int prin1()
{
        for(int j=1;j<=n;j++)
        printf("%d ",step1[j]);
        printf("\n");
}
int main()
{
    
    scanf("%d %d %d %d",&n,&m,&x,&y);
    dfs(x,1);
    printf("%lld\n",number);
    return 0;
}