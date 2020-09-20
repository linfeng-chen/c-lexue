# include"stdio.h"
# include"stdlib.h"

#define N 400000
int time[N][2]={0};
int comp(const void*a,const void*b)
{
    return((int*)a)[1]-((int*)b)[1];
}
int main()
{
    long n,count=0,began,final;
    scanf("%ld",&n);
    for (long i = 1; i <= n; i++){
        scanf("%d %d",&time[i][0],&time[i][1]);
    }
    qsort(time[1],n,sizeof(int)*2,comp);
    began=time[1][0],final=time[1][1],count++;
    for (long i = 2; i <= n; i++)
        if(time[i][0]>=final)count++,began=time[i][0],final=time[i][1];
    printf("%ld\n",count);

    return 0;
}