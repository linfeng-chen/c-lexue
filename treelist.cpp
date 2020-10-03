#include <iostream>
#include "algorithm"
#include "vector"
#include "cstring"
#define N 210005
using namespace std;

vector<int>tree[N];
int a[N]={0}, flag[N]={0},root[N]={0};
int temp[N]={0},final[N]={0};
int counter=0 ,sum=0;

int dfs_flag(int root)//如果父节点有排序标记，则其所有子节点不需要排序
{
    for(int i=0;i<tree[root].size();i++)
    {
        temp[++counter] = a[tree[root][i]];
        dfs_flag(tree[root][i]);
    }
    return counter;
}
int dfs(int root)
{
    if(flag[root]==1)//如果有排序标记
    {
        final[++sum] = a[root],counter=0;
        int tem=dfs_flag(root),one = sum;
        for(int i=1;i<=tem;i++)final[++sum] = temp[i];
        sort(&final[one],&final[sum+1]);
        memset(temp,0,(tem+1)*sizeof(int));
    }
    else //没有标记，就对其下一层子节点排序
    {
        final[++sum] = a[root];
        sort(tree[root].begin(),tree[root].end());
        for(int i=0;i<tree[root].size();i++)
            dfs(tree[root][i]);
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)scanf("%d",&flag[i]);
    for(int i=1;i<=n-1;i++)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        tree[a].push_back(b);
        root[b]++;
    }
    int tree_root = 0;
    for(int i=1;i<=n;i++) 
        if(root[i]==0) tree_root = i;//根节点
    dfs(tree_root);
    printf("[%d",final[1]);
    for(int i=2; ;i++)
    if(final[i]!=0)
        printf(",%d",final[i]);
    else break;
    printf("]\n");
    

    return 0;
}