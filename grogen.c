# include "stdio.h"
# include "stdlib.h"
#define N 300000


struct dragon
{
    long long x,y,z;
};
struct dragon good[N];
struct dragon bad[N];

int comp(const void*p1,const void*p2)
{
    struct dragon*c = (struct dragon*)p1;
    struct dragon*d = (struct dragon*)p2;
    return c->x-d->x;
}
int comp1(const void*p1,const void*p2)
{
    struct dragon*c = (struct dragon*)p1;
    struct dragon*d = (struct dragon*)p2;
    return d->z-c->z;
}
int main()
{
   long long n,i,j,x,y,count1=1,count2=1,money=0,power=0;
    scanf("%lld",&n);
    for(i=1;i<=n;i++){
        scanf("%lld %lld",&x,&y);
        if(y>=0) good[count1].x=x,good[count1++].y=y;
        else bad[count2].x=x,bad[count2].y=y,bad[count2++].z=x+y;
    }

    qsort(&good[1],count1-1,sizeof(good[1]),comp);
    qsort(&bad[1],count2-1,sizeof(bad[1]),comp1);
    for(i=1;i<count1;i++)
    {
        //printf("%lld %lld\n",good[i].x,good[i].y);
        if(power<good[i].x)money +=good[i].x-power,power=good[i].x+good[i].y;
        else power +=good[i].y;
    }
    //printf("%lld %lld\n",power,money);
    for(i=1;i<count2;i++)
    {
        //printf("%lld %lld\n",bad[i].x,bad[i].y);
        if(power<bad[i].x)money+=bad[i].x-power,power=bad[i].x+bad[i].y;
        else power +=bad[i].y;
    }
    printf("%lld\n",money);
    return 0;
}