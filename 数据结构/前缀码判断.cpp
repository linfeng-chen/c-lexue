# include "iostream"
# include "string.h"
using namespace std;

typedef struct node{
    char data;
    struct node *left,*right;

}Node,*Tree;

int compare(Tree &one,char s[])
{
    Tree temp = one;
    for(int i=0;i<strlen(s);i++)
    {
        Tree two;
        if(s[i]=='0')two= one->left;
        if(s[i]=='1')two= one->right;
        if(i==strlen(s)-1&&two!=NULL) return -1;//前缀出现了
        if(two!=NULL&&two->left==NULL&&two->right==NULL&&i<strlen(s))return -1;
        if(two==NULL)
        {
            two = (Tree)malloc(sizeof(Node));
            two->data = s[i];
            two->left = NULL,two->right = NULL;
            if(s[i]=='0') one->left=two;
            else one->right=two;
            one = two;
        }
        else one = two; 
    }
    return 1;
}
char need[200000]={0};
char s[200000]={0};
int main()
{

    int n,flag=0;
    Tree one,two;
    one = (Tree)malloc(sizeof(Node));
    one->data='x',one->left=NULL,one->right=NULL;
    two = one;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        memset(s,0,sizeof(s));
        scanf("%s",&s);
        if(flag==1) continue ;
        int x = compare(one,s);
        one = two;
        if(x==-1) flag = 1,strcpy(need,s);
    }
    if(flag==1) printf("%s\n",need);
    else printf("YES\n");
    return 0;
}