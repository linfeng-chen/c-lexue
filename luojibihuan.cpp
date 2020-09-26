#include <iostream>
#include "cstring"
#include <vector>
#define N 400000

using namespace std;
vector<long>tree[N];
long step[N]={0};

long bfs(long first,long second)
{
        long head=1,tail=1;
        step[1] = second;
        do
        {
            for(long it=0;it<tree[step[head]].size();it++)
            {
                if(tree[step[head]][it]==first) return 1;
                tail++,step[tail]=tree[step[head]][it];
            }
             head++; 
        } while (head<tail);
    return 0;
}

int main()
{
    long i,n,m,need=0;
    scanf("%ld %ld",&n,&m);
    for( i=1;i<=m;i++)
    {
        long a,b;
        scanf("%ld %ld",&a,&b);
        tree[a].push_back(b);
        if(need==0)
        {
            long x=bfs(a,b);
            if(x==1) need=i;
        }    
    }

    if(need!=0) printf("%ld\n",need);
    else printf("-1\n");

    return 0;
}