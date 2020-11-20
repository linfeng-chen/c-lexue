# include "iostream"
# include "cstring"
# include "queue"
using namespace std;

int road[101][101]={0};
int all_head[101]={0};
void shortpath_DJ(int began,int n,int Dq[100])//n为节点数量
{
    int P[100][100],fina[101]={0};//final[i]表示是否已经找到到i的最短路径
    for(int i=1;i<=100;i++)
    {
        if(all_head[i]!=0)
            fina[i] = 0,Dq[i] = road[began][i]==0?9999:road[began][i];
    }
    Dq[began] = 0,fina[began] = 1;
    one.push(began);
    for (int i = 2; i <=n; ++i) {
        //其余顶点
        int min = 9999,v=1;
        for (int j = 1; j <=100 ; ++j) {
            if(all_head[j]!=0&&fina[j]==0&&Dq[j]<min)
                v = j, min =  Dq[j];
        }
        fina[v] = 1;//到此节点的最短距离已经有了
        for (int j = 1; j <=100 ; ++j) {
            //更新距离
            if(all_head[j]!=0&&!fina[j]&&(min+(road[v][j]==0?9999:road[v][j])<Dq[j]))
                Dq[j] = min + road[v][j];
        }
    }

}
int main()
{
    int n,m,Dq[100]={0};
    char head;
    scanf("%d,%d,%c",&n,&m,&head);
    getchar();
    for(int i=1;i<=m;i++)
    {
        char first,second;
        int weight;
        scanf("<%c,%c,%d>",&first,&second,&weight);
        getchar();
        road[first-64][second-64] = weight;
        all_head[first-64]++,all_head[second-64]++;
    }
    shortpath_DJ(head-64,n,Dq);
    for (int i = 1; i <=100 ; ++i) {
        if(all_head[i]!=0)
            printf("%c:%d\n",i+64,Dq[i]);
    }
    return 0;
}