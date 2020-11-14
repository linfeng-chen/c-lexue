# include "iostream"
# include "vector"
# include "queue"
using namespace std;

int flag[100]={0};
void bfs(vector<int>one[100],int a,char head[100],int num)
{
    queue<int>temp;
    temp.push(a);
    flag[a] = 1;
    printf("%c",head[a+1]);
    do
    {
        int x =temp.front(); temp.pop();
        for(int i=one[x].size()-1;i>=0;i--)
        {
            if (flag[one[x][i]]==0) 
            {
                printf("%c",head[one[x][i]+1]);
                temp.push(one[x][i]);
                flag[one[x][i]]=1;
            }
        }

    } while(temp.size()!=0);
    for(int i=0;i<num;i++)
        if(flag[i]==0) printf("%c",head[i+1]);
    
}
int main()
{   
    vector<int>one[100];
    char head[100]={0};
    char c;
    int a=1;
    while((c=getchar())!='*')
    {
        head[a++] = c;
        getchar();
    }
    while(true)
    {
        int h,t;
        scanf("%d,%d",&h,&t);
        
        if(h==-1&&t==-1) break;
        one[h].push_back(t),one[t].push_back(h);
    }
    printf("the ALGraph is\n");
    for(int i=1;i<a;i++)
    {
        printf("%c",head[i]);
        for(int j=one[i-1].size()-1;j>=0;j--)
        printf(" %d",one[i-1][j]);
        printf("\n");
    }
    printf("the Breadth-First-Seacrh list:");
    bfs(one,0,head,a-1);
    printf("\n");
    return 0;
}