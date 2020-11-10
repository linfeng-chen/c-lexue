# include "iostream"
using namespace std;

typedef struct 
{
    unsigned int weight;
    unsigned int parent,lchid,rchid;
}HNode,*HuffmanTree;

void select(HuffmanTree one,int n,int &s1,int &s2)
{
    int min=999,min2=999,flag=0,flag1;
    for(int i=1;i<=n;i++)
    {
        if(one[i].parent==0)
        if(one[i].weight<=min)flag=i,min = one[i].weight;
    }

    for(int i=1;i<=n;i++)
    {
        if(one[i].parent==0&&i!=flag)
        if(one[i].weight<=min2)flag1=i,min2=one[i].weight;
    }

    s1 = flag,s2=flag1;

}
int HuffmanTree_creat(HuffmanTree &one,int *w,int n)
{
    int sum=0;
    if(n<1) return 0;
    int m = n*2-1;
    one = (HuffmanTree)malloc(sizeof(HNode)*(m+1));
    HuffmanTree p = one+1;
    int i;
    for(i=1;i<=n;++i,++p,++w)
    p->weight = *w,p->lchid=0,p->rchid=0,p->parent=0;
    for(;i<=m;i++,p++)
    p->weight =0,p->lchid=0,p->rchid=0,p->parent=0;

    // for(i=1;i<=m;i++)
    // printf("%d %d %d %d\n",one[i].weight,one[i].lchid,one[i].rchid,one[i].parent);

    for(i=n+1;i<=m;i++)
    {
        int s1,s2;
        select(one,i-1,s1,s2);
        // printf("%d %d\n",s1,s2);
        one[s1].parent = i,one[s2].parent = i;
        one[i].lchid = s1,one[i].rchid = s2;
        one[i].weight = one[s1].weight+one[s2].weight;
        sum += one[i].weight;
    }
    
   // for(i=1;i<=m;i++)
   // printf("%d %d %d %d\n",one[i].weight,one[i].lchid,one[i].rchid,one[i].parent);
   return sum;
}

int main()
{
    HuffmanTree one;
    int n,weight[1000]={0};
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    scanf("%d",&weight[i]);

   printf("WPL=%d\n",HuffmanTree_creat(one,weight,n));

    return 0;
}