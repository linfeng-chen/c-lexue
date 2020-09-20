# include "stdio.h"
# include "stdlib.h"
#define N 300000
long long ball[N][3];
struct ball
{
    long long x1,x2,x3,address;
};
struct ball max_ball [N];
int comp(const void*p1,const void*p2)
{
    struct ball*c = (struct ball*)p1;
    struct ball*d = (struct ball*)p2;
    if(c->x1!=d->x1) return c->x1-d->x1;
    else{
        if(c->x2!=d->x2) return c->x2-d->x2;
        else return c->x3-d->x3; }
}
int main()
{
    long long n,x1,x2,x3,max,min,i,j,max_all=0,add=0;
    scanf("%lld",&n);
    for(long i=1;i<=n;i++)
    {
        scanf("%lld %lld %lld",&x1,&x2,&x3);
        max = x1>x2?(x1>x3?x1:x3):(x2>x3?x2:x3);min = x1<x2?(x1<x3?x1:x3):(x2<x3?x2:x3);
        max_ball[i].x1=max,max_ball[i].x2=x1+x2+x3-max-min,max_ball[i].x3=min,max_ball[i].address=i;
    }
    qsort(&max_ball[1],n,sizeof(max_ball[1]),comp);
    for(i =1;i<=n;i++)
        if(max_ball[i].x3>max_all) max_all=max_ball[i].x3,add=max_ball[i].address;
    min =max_all;
    long long add1=0,add2=0;
    for(i=n;i>1;i--)
    {
        if(max_ball[i].x1==max_ball[i-1].x1&&max_ball[i].x2==max_ball[i-1].x2)
        {
            x1=max_ball[i].x3+max_ball[i-1].x3,x2=max_ball[i].x1,x3=max_ball[i].x2;
            max=x1<x2?(x1<x3?x1:x3):(x2<x3?x2:x3);
            if(max>min) min=max,add1=max_ball[i].address,add2=max_ball[i-1].address;    
        }
    }
    if(add1==0)printf("%lld\n%lld\n",1,add);
    else printf("%lld\n%lld %lld\n",2,add1,add2);
    return 0;
}