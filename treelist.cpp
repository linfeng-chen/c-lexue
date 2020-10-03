#include <iostream>
#include "algorithm"
#include "vector"

#define N 210005

using namespace std;
vector<int>tree[N],need[N];

int a[N]={0}, flag[N]={0},root[N]={0};
int flag1[N]={0};
int dfs_flag(int root)//如果父节点有排序标记，则其所有子节点不需要排序，将所有子节点的标记赋为0
{
    if(tree[root].size()==0)return 0;
    for(int i=0;i<tree[root].size();i++)
    {
        flag[tree[root][i]] = 0,flag1[tree[root][i]]=1;
        int temp = tree[root][i];
        dfs_flag(temp);
    }
}
int dfs(int root)
{
    need[root].push_back(a[root]);
    if(flag[root]==1) dfs_flag(root);//如果有排序标记，就对其子节点全部赋0
    else if(flag[root]==0&&flag1[root]==0)sort(tree[root].begin(),tree[root].end());//没有标记，就对其下一层子节点排序

    for(int i=0;i<tree[root].size();i++)
    {
        int temp = tree[root][i];
        dfs(temp);
        for(int j=0;j<need[temp].size();j++)
        need[root].push_back(need[temp][j]);
        need[temp].clear();
    }
    if(flag[root]==1) sort(need[root].begin(),need[root].end());
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
    {
        if(root[i]==0) tree_root = i;//根节点
    }
   // printf("%ld\n",tree_root);

    dfs(tree_root);

    printf("[%d",need[tree_root][0]);
    for(int i=1;i<need[tree_root].size();i++)
        printf(",%d",need[tree_root][i]);
    printf("]\n");
    

    return 0;
}