// Created by linfeng on 2020/12/12.
# include "iostream"
# include "queue"
using namespace std;
typedef struct address{
    int x, y, length, direction;
    //direction为-1表示为起始点，1为水平直线，0为竖直直线
}Addr;
int n,m,maps[100][100]={0};
int x[4]={1,-1,0,0,};
int y[4]={0,0,-1,1};
int Search(int beginX,int beginY,int flags[100][100])
{
    //利用广搜查询是否可以走,如果遇到了0，则继续走如果了非0，则需要判断这个点是否可以消去，如果不可以
    //则不选此路。
    Addr temp;
    queue<Addr>one;
    int flag[100][100]={0};
    int target = 0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(flags[i][j]==1)flag[i][j]=1;//记录上次的走过的路
    temp.x = beginX, temp.y = beginY, temp.length = 0,temp.direction = -1;
    one.push(temp);flag[beginX][beginY] = 1;
    do{
        Addr his = one.front();one.pop();
        int nowX = his.x, nowY = his.y, length = his.length, direction = his.direction;
        for (int i = 0; i < 4; ++i) {
            int nextX = nowX +x[i], nextY = nowY +y[i];
            if(nextX>=0 && nextX<n && nextY>=0 && nextY<m && flag[nextX][nextY]==0){
                temp.x = nextX, temp.y = nextY;
                //判断直线是否加1
                int nextLength, nextdirection;
                if(direction==-1)nextLength =length+1, nextdirection = (i==2||i==3)?1:0;
                else if((i==2||i==3)&&direction==0) nextLength =length+1, nextdirection=1;
                else if((i==0||i==1)&&direction==1) nextLength =length+1, nextdirection=0;
                else nextLength = length, nextdirection = (i==2||i==3)?1:0;
                temp.length = nextLength,temp.direction = nextdirection;
                //printf("~ %d %d %d %d\n",nextX,nextY,maps[nextX][nextY],nextLength);
                if(maps[nextX][nextY] == 0)
                    one.push(temp), flag[nextX][nextY] = 1;
                else if (Search(nextX,nextY,flag)==1)//此点可以被消去
                    one.push(temp), flag[nextX][nextY] = 1;
                if(maps[nextX][nextY]==maps[beginX][beginY]&&nextLength<3)
                    maps[nextX][nextY] = 0,target = 1;
            }
        }
    }while (!one.empty());
    if(target==1){ maps[beginX][beginY]=0; return 1; }
    return 0;
}
int main()
{
    int beginX, beginY, endX, endY;
    int flags[100][100]={0};
    scanf("%d %d",&n,&m);
    for (int i = 0; i <n ; ++i)
        for (int j = 0; j <m ; ++j)
            scanf("%d",&maps[i][j]);
    scanf("%d %d",&beginX,&beginY);
    scanf("%d %d",&endX,&endY);
    int x= Search(beginX,beginY,flags);
    if(x==0)printf("FALSE\n");
    else printf("TRUE\n");
    return 0;
}
