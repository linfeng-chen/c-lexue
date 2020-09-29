#include <iostream>
#include "cstring"
# include "vector"

#define N 300000

using namespace std;

long father[N] ={0},size[N] ={0},deep[N]={0},vis[N]={0};
//表示i节点的父亲节点，子节点个数，深度，标记数组
vector<long>tree[N];
long ji=0,ou=0;
long sum=0;
void dfs(long u)
{
    if(vis[u]==0)
    {
        deep[u] = deep[father[u]]+1,size[u]=1,vis[u]=1;
        if(deep[u]%2==0) ou++;
        else ji++;
    }
    for(long i=0;i<tree[u].size();i++)
    {
        if(vis[tree[u][i]]==0) 
        {
            father[tree[u][i]] = u;
            dfs(tree[u][i]);
            size[u] +=size[tree[u][i]];
        }
    }
}
int main()
{
    long n;
    scanf("%ld",&n);
    for(long i=1;i<=n-1;i++)
    {
        long a,b;
        scanf("%ld %ld",&a,&b);
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    dfs(1);
    for(long i=1;i<=n;i++)
    {
        sum +=size[i]*(n-size[i]);
    }
    long depth = ji*ou;
    printf("%ld\n",(depth+sum)/2);

    return 0;
}