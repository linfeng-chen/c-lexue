# include "stdlib.h"
# include "stdio.h"
#include "string.h"
# define N 600000
long long  x_big[N]={0},x_small[N]={0};
long long  y_big[N]={0},y_small[N]={0};
long long x_1=0,x_2=0,y_1=0,y_2=0;
long long need[N]={0};

//pos:位置,x_big[]数据为小根堆
void insert(long long val,long long pos,long long heap[])//将元素入堆
{
    heap[pos]=val;
    long long temp = pos;
    while (temp>1)
    {
        long long root = temp/2;
        if(heap[root]>val)//">"为小根堆，"<"为大根堆
            heap[root] = heap[root]^heap[temp],heap[temp] = heap[root]^heap[temp],heap[root]=heap[root]^heap[temp];
        else break;
        temp = root;
    } 
}
void insert1(long long val,long long pos,long long heap[])//将元素入堆，大根堆
{
    heap[pos]=val;
    long long temp = pos;
    while (temp>1)
    {
        long long root = temp/2;
        if(heap[root]<val)//">"为小根堆，"<"为大根堆
            heap[root] = heap[root]^heap[temp],heap[temp] = heap[root]^heap[temp],heap[root]=heap[root]^heap[temp];
        else break;
        temp = root;
    } 
}

long long pop(long long heap[],long long *pos)//推出堆顶,小根堆
{
    long long temp = heap[1];//将堆顶元素暂存
    heap[1] = heap[*pos];
    long long root=1;
    while (2*root < *pos)
    {
        long long left = 2*root,right=2*root+1;
        if(right>=pos||heap[left]<heap[right])
        {
            if(heap[root]>heap[left])
            heap[root] = heap[root]^heap[left],heap[left] = heap[root]^heap[left],heap[root]=heap[root]^heap[left],root=left;
            else break;
        }
        else
        {
            if(heap[root]>heap[right])
            heap[root] = heap[root]^heap[right],heap[right] = heap[root]^heap[right],heap[root]=heap[root]^heap[right],root=right;
            else break;
        }
    }
    *pos = *pos-1;
    return temp;
}
long long pop1(long long heap[],long long *pos)//推出堆顶，大根堆
{
    //printf("~~~%lld\n",*pos);
    long long temp = heap[1];//将堆顶元素暂存
    heap[1] = heap[*pos];
    long long root=1;
    while (2*root < *pos)
    {
        long long left = 2*root,right=2*root+1;
        if(right>=pos||heap[left]>heap[right])
        {
            if(heap[root]<heap[left])
            heap[root] = heap[root]^heap[left],heap[left] = heap[root]^heap[left],heap[root]=heap[root]^heap[left],root=left;
            else break;
        }
        else
        {
            if(heap[root]<heap[right])
            heap[root] = heap[root]^heap[right],heap[right] = heap[root]^heap[right],heap[root]=heap[root]^heap[right],root=right;
            else break;
        }
    }
    *pos=*pos-1;
    return temp;
}
int main()
{
    long long n,i,j,t,x,y,mid_x,mid_y;
    scanf("%lld",&t);
    j=0;
    while (++j<=t)
    {
        scanf("%lld",&n);
        scanf("%lld %lld",&mid_x,&mid_y);
        for  (i = 2; i <=n ; i++)
        {
            scanf("%lld %lld",&x,&y);
            if(x>mid_x) insert(x,++x_1,x_big);//放入小根堆中
            else insert1(x,++x_2,x_small);//放入大根堆中
            if(y>mid_y) insert(y,++y_1,y_big);//y同理
            else insert1(y,++y_2,y_small);
            
            
            need[i] = need[i-1]+abs(x-mid_x)+abs(y-mid_y);
            if(abs(x_1-x_2)>=2)//两堆中个数相差2
            {
                if(x_1>x_2){//如果小根堆中多余大根堆
                    insert1(mid_x,++x_2,x_small);
                    mid_x =pop(x_big,&x_1);
                    need[i] = need[i]-(mid_x-x_small[1]);
                }
                else if(x_1<x_2)//大根堆多
                {
                    insert(mid_x,++x_1,x_big);
                    mid_x = pop1(x_small,&x_2);
                    need[i] = need[i]-(x_big[1]-mid_x);
                    //printf("%lld\n",need[i]);
                }
            }
            if(abs(y_1-y_2)>=2)
            {
                if(y_1>y_2){//如果小根堆中多余大根堆
                    insert1(mid_y,++y_2,y_small);
                    mid_y=pop(y_big,&y_1);
                    need[i] = need[i]-(mid_y-y_small[1]);
                }
                else if(y_1<y_2)//大根堆多
                {
                    insert(mid_y,++y_1,y_big);
                    mid_y = pop1(y_small,&y_2);
                    need[i] = need[i]-(y_big[1]-mid_y);
                }
            }
            
        }
        printf("Case: %lld\n",j);
        for(i=1;i<=n;i++)
        printf("%lld.0000\n",need[i]);
        memset(x_big,0,n);
        memset(x_small,0,n);
        memset(y_big,0,n);
        memset(y_small,0,n);
        memset(need,0,n);
        x_1=0,x_2=0,y_1=0,y_2=0;
        
    }
    
 
    return 0;
}