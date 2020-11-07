# include "iostream"
# include "queue"
using namespace std;

typedef struct gnode
{
    char data;
    int left,right;
}GNode;
typedef struct bttree{
    GNode nodes[100];
    int num_nods;
} Bigtree;

int search(GNode temp,Bigtree two,Bigtree one,int k,int k1, int m)
{
    int i;
    for(i=0;i<m;i++)
        if(two.nodes[i].data==temp.data) break;
    
    char a=one.nodes[temp.left==-1?k:temp.left].data,b=one.nodes[temp.right==-1?k:temp.right].data;
    char c=two.nodes[two.nodes[i].left==-1?k1:two.nodes[i].left].data,d=two.nodes[two.nodes[i].right==-1?k1:two.nodes[i].right].data;
    if((a==c&&b==d)||(a==d&&b==c))   
    return 1;

    return -1;
}
int compare(Bigtree one,Bigtree two,int m,int k,int k1)
{
    //比较两个二叉树节点的子节点是否相同
    queue<GNode>need;
    if(one.nodes[k].data==two.nodes[k1].data)
    {
        char a=one.nodes[one.nodes[k].left==-1?k:one.nodes[k].left].data,b=one.nodes[one.nodes[k].right==-1?k:one.nodes[k].right].data;
        char c=two.nodes[two.nodes[k1].left==-1?k:two.nodes[k1].left].data,d=two.nodes[two.nodes[k1].right==-1?k:two.nodes[k1].right].data;
        if((a==c&&b==d)||(a==d&&b==c))
        need.push(one.nodes[k]);//重复了可改为上面的函数，懒得改
        else return -1;

        while(!need.empty())
        {
            GNode temp = need.front();
            need.pop();
            if(temp.left!=-1)
            {
                if(search(one.nodes[temp.left],two,one,k,k1,m)==1)//
                need.push(one.nodes[temp.left]);
                else return -1;
            }
            if(temp.right!=-1)
            {
                if(search(one.nodes[temp.right],two,one,k,k1,m)==1)//
                need.push(one.nodes[temp.right]);
                else return -1;
            }
        }
    }
    else return -1;

    return 1;
}
int main()
{
    Bigtree one,two;
    int n,m;
    scanf("%d",&n);
    getchar();
    for(int i=0;i<n;i++)
    {
        char data,left,right;
         scanf("%c %c %c",&data,&left,&right);
        getchar();
        one.nodes[i].data = data;one.num_nods=0;
        if(left!='-')one.nodes[i].left= left-'0',one.num_nods++;
        else one.nodes[i].left=-1;
        if(right!='-')one.nodes[i].right=right-'0',one.num_nods++;
        else one.nodes[i].right=-1;
    }
    
    scanf("%d",&m);
    getchar();
    for(int i=0;i<m;i++)
    {
        char data,left,right;
        scanf("%c %c %c",&data,&left,&right);
        getchar();
        two.nodes[i].data = data;two.num_nods=0;
        if(left!='-')two.nodes[i].left= left-'0';
        else two.nodes[i].left=-1;

        if(right!='-')two.nodes[i].right = right-'0';
        else two.nodes[i].right=-1;
    }

    int k,k1;
    for(int i=0;i<n;i++)
        if(one.nodes[i].data=='A'){
           k=i;break; 
        } 
    for(int i=0;i<m;i++)
        if(two.nodes[i].data=='A'){
           k1=i;break; 
        }
    if(compare(one,two,m,k,k1)==-1)printf("No.\n");
    else printf("Yes.\n");
    return 0;
}