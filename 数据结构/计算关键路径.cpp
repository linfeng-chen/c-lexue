//
// Created by 19254 on 2020/11/19.
//
# include "algorithm"
# include "iostream"
# include "vector"
# include "deque"
# include "cstring"
#include "queue"
using namespace std;
typedef struct tail{
    int last;
    int weight;
}Tail;
int flag[50] = {0};
vector<int> road;

void find_indu(vector<Tail>one[100],int indegree[100],int n)
{
    for(int i=0;i<n;i++)
        for(int j=0;j<one[i].size();j++)
            indegree[one[i][j].last]++;
}
void exchange(char str[100],int n)
{
    int counter = 0,i;
    for(i=0;i<strlen(str);i++)
        if(str[i]==',')break;
    for (int j = n*(i+1); j < (n+1)*(i+1)-1&&j<strlen(str); ++j) {
        printf("%c",str[j]);
    }
}
bool comp(Tail a, Tail b)
{
    return a.last<b.last;
}
int change(queue<int>one,char name[])
{
    exchange(name,one.front());one.pop();
    while (!one.empty()){
        printf("-");
        exchange(name,one.front());one.pop();
    }
    printf("\n");
}
int  topupaixu(vector<Tail>one[100],int n,int time[100],deque<int>&need,char name[100])
{
    //拓扑排序+最早发生时间
    int indegree[100]={0};//入度
    find_indu(one,indegree,n);
    deque<int>nice;
    queue<int>sorts;
    for (int i = 0; i < n; ++i) {
        if(!indegree[i]) nice.push_back(i),need.push_back(i);
    }
    int count = 0;
    while (!nice.empty())
    {
        int temp = nice.front();nice.pop_front();
        count++;sorts.push(temp);
        sort(one[temp].begin(),one[temp].end(),comp);
        for (int i = 0; i < one[temp].size(); ++i) {
            indegree[one[temp][i].last]--;
            if(indegree[one[temp][i].last]==0)
            {
                if(one[temp][i].last < nice.front())
                {
                    int a = nice.front();
                    nice.pop_front(),nice.push_back(one[temp][i].last),nice.push_back(a);
                    need.pop_front(),need.push_back(one[temp][i].last),need.push_back(a);
                }
                else
               nice.push_back(one[temp][i].last),need.push_back(one[temp][i].last);
            }
            if(time[temp]+one[temp][i].weight > time[one[temp][i].last]) time[one[temp][i].last] = time[temp]+one[temp][i].weight;
        }
    }
    if(count<n) return 1;
    change(sorts,name);
}

void dfs(vector<int>keyroad[50],int begin,int end,char name[])
{
    if(begin==end)
    {
       for(int i=0;i<road.size();i++)
           if (i==0)
           exchange(name,road[i]);
           else{
               printf("-");exchange(name,road[i]);
           }
       printf("\n");
        return;
    }
    for(int i=0;i<keyroad[begin].size();i++)
    {
        if(flag[keyroad[begin][i]]==0)
        {
            flag[keyroad[begin][i]]=1;
            road.push_back(keyroad[begin][i]);
            dfs(keyroad,keyroad[begin][i],end,name);
            flag[keyroad[begin][i]]=0;
            road.pop_back();
        }
    }
    return;
}
void criticalPath(vector<Tail>one[100],int n,char name[100])
{
    int time_later[100] = {0},time[100]={0},flag[100]={0};
    deque<int> need;
    queue<int> final;
    vector<int>keyroad[50];
    if(topupaixu(one,n,time,need,name)==1) {
        printf("NO TOPOLOGICAL PATH\n");
        return;
    }//判断是否有通路
    for(int j=0;j<n;j++) time_later[j] = time[n-1];
    while (!need.empty())//求最迟发生时间
    {
       int temp = need.back();
       need.pop_back();
       for(int i=0;i<one[temp].size();i++)
       {
           int dut = one[temp][i].weight, tail = one[temp][i].last;
           if(time_later[tail]-dut < time_later[temp]) time_later[temp] = time_later[tail] - dut;
       }
    }
    for(int i=0;i<n;i++){
        for (int j = 0; j < one[i].size(); ++j) {
            int tail = one[i][j].last, dut = one[i][j].weight;
            int ee = time[i], el = time_later[tail] -dut;

            if(ee == el)
            {
                //printf("*%d %d %d %d\n",ee,el,i,tail);//exchange(name,i);exchange(name,tail);
                keyroad[i].push_back(tail);
                if(final.empty()||final.back()!=i&&flag[i]==0)final.push(i),flag[i]++;
                if(flag[tail]==0)final.push(tail),flag[tail]++;
            }
        }
    }//求每条弧的最早最晚发生时间
//    change(final,name);
    road.push_back(0);
    dfs(keyroad,0,n-1,name);
}
int main()
{
    int n,m,i;
    vector<Tail>one[100];
    Tail temp;
    char name[100]={0};
    scanf("%d,%d",&n,&m);
    scanf("%s",&name);
    getchar();
    int a,b,c;
    scanf("<%d,%d,%d>",&a,&b,&c);
    temp.last = b,temp.weight = c;
    one[a].push_back(temp);
    for (int i = 2; i <= m; ++i) {
        scanf(",<%d,%d,%d>",&a,&b,&c);
        temp.last = b,temp.weight = c;
        one[a].push_back(temp);
    }
    criticalPath(one,n,name);
    return  0;
}
