# include "iostream"
# include "string.h"


using namespace std;
int ht[1000][1000]={0};
int flag[1003]={0};

int Minispan(int n,int &sum)
{
    struct{
        int adjvex;
        int lowest;
    }closetedge[1000];
    for(int i=1;i<=n;i++)
    if(i!=1) closetedge[i].adjvex=1,closetedge[i].lowest = ht[1][i]==0?9999:ht[1][i];
    closetedge[1].lowest= 0;
    for(int i=1;i<=n-1;i++)//找出剩余的节点
    {
        int k=0,min=9999;
        for(int j=1;j<=n;j++) if(closetedge[j].lowest<min&&closetedge[j].lowest!=0) min=closetedge[j].lowest,k=j;
        //找到离最小生成树的距离最小的点
        //printf("%d %d %d\n",closetedge[k].adjvex,closetedge[k].lowest,k);
        sum +=closetedge[k].lowest;
        closetedge[k].lowest = 0;
        if(k==0) return 0;
        for(int j=1;j<=n;j++)
        {
            if(ht[k][j]<closetedge[j].lowest&&closetedge[j].lowest!=0)closetedge[j].adjvex = k,closetedge[j].lowest=ht[k][j]==0?9999:ht[k][j];
        }
    }
    return 1;
}

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        ht[a][b]=c,ht[b][a]=c;
    }
    int sum=0;
    int x = Minispan(n,sum);
    if(x==1)
    printf("%d\n",sum);
    else printf("-1\n");
    return 0;
}