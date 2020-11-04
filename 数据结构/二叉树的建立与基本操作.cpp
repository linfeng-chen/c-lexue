# include "iostream"
# include "string.h"
# include "queue"
# include "math.h"

using namespace std;

typedef struct Gnode{
    char data;
    struct Gnode *left,*right;
}*Bigtree,Bitnode;

int creatBigtree(Bigtree &one,char s[])
{
    queue<Bigtree> tree;
    Bigtree need = one;
    
    for(int i=0;i<int(log2(strlen(s))+1);i++)
    {
        for(int j=1<<i;j<=(1<<(i+1))-1&&j<=strlen(s);j++)
        {
            //printf("%d",j);
            //printf("%c\n",s[j-1]);
            if(i==0)
            {
                one = (Bigtree)malloc(sizeof(Bitnode));
                need = one;
                one->data = s[j-1];one->right=NULL;one->left =NULL;
                tree.push(one);
            }
            else
            {
                if(j%2==0){

                    one = tree.front();
                    tree.pop();
                    if(one==NULL){
                        j++;
                        continue ; 
                    }
                    // printf("**%c\n",one->data);
                    if(s[j-1]=='#')one->left=NULL;
                    else{
                    one->left = (Bigtree)malloc(sizeof(Bitnode));
                    one->left->data =s[j-1]; one->left->left=NULL;one->left->right=NULL;
                    }

                    if(j<strlen(s))
                    {   
                        if(s[j]=='#') one->right==NULL;
                        else{
                        one->right = (Bigtree)malloc(sizeof(Bitnode));
                        one->right->data = s[j];
                        one->right->left=NULL;one->right->right=NULL;
                        }
                        j++;
                    }
                    tree.push(one->left);tree.push(one->right);
                }
            }
            
        }
        
    }
    one = need ;
    
    return 1;
}
int print(char ch)
{
    printf("%c",ch);
    return 1;
}
int aoin(Bigtree T,int deep)
{
    //凹入表示
    if(T)
    {
        if(deep!=1)
        for(int i=1;i<=(deep-1)*4;i++)
        printf(" ");
        printf("%c\n",T->data);
        if(T->left) aoin(T->left,deep+1);
        if(T->right)  aoin(T->right,deep+1); 
    }
    else return 1;
}
int preorder_view(Bigtree T)
{
    if(T)
    {
        printf("%c",T->data);
        if(T->left) preorder_view(T->left);
        if(T->right)  preorder_view(T->right);
    }
}
int inorder_view(Bigtree T)
{
    if(T==NULL) return 1;
    if(T)
    {
        if(T->left) inorder_view(T->left);
        printf("%c",T->data);
        if(T->right) inorder_view(T->right);
    }
}
int postorder_view(Bigtree T)
{
    if(T==NULL) return 1;
    if(T)
    {
        if(T->left) postorder_view(T->left);
        if(T->right) postorder_view(T->right);
        printf("%c",T->data);
        
    }
}
int counter=0;
int num(Bigtree T)
{
    if(T)
    {
        if(T->left==NULL &&T->right==NULL)
        counter++;
        if(T->left) num(T->left);
        if(T->right) num(T->right);
    }
}
int change(Bigtree &T)
{
    if(T)
    {
        Bigtree temp=NULL;
        temp = T->left;
        T->left = T->right;
        T->right = temp;
        if(T->left) change(T->left);
        if(T->right) change(T->right);
    }
}
int main()
{
    
    Bigtree one,need;
    char s[1000]={0};
    scanf("%s",&s);
    
    creatBigtree(one,s);
    printf("BiTree\n");
    aoin(one,1);
    printf("pre_sequence  : ");
    preorder_view(one);
    printf("\nin_sequence   : ");
    inorder_view(one);
    printf("\npost_sequence : ");
    postorder_view(one);
    num(one);
    printf("\nNumber of leaf: ");
    printf("%d\n",counter);

    change(one);
    printf("BiTree swapped\n");
    aoin(one,1);
    printf("pre_sequence  : ");
    preorder_view(one);
    printf("\nin_sequence   : ");
    inorder_view(one);
    printf("\npost_sequence : ");
    postorder_view(one);
    printf("\n");
    return 0;
}