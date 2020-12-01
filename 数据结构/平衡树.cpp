//
// Created by linfeng on 2020/11/29.
//
# include "iostream"
# include "cstring"
# include "vector"
using namespace std;
typedef struct Tree
{
    char data;
    int bf;
    struct Tree *left,*right;
}BaTree,*BTree;
typedef struct need
{
    char data;int length;
}Need;
vector<Need> N;
void R_rotate(BTree &p){
    BTree temp;
    temp = p->left;
    p->left = temp->right;
    temp->right = p; p = temp;
}//单支右旋
void L_rotate(BTree &p){
    BTree temp;
    temp = p->right;
    p->right = temp->left;
    temp->left = p; p = temp;
}//单支左旋
void Left_balance(BTree &T)
{
    BTree temp = NULL;
    temp = T->left;
    switch (temp->bf) {
        case 1:
            T->bf = temp->bf = 0;R_rotate(T);break;
        case -1:
            BTree ather = temp->right;
            switch (ather->bf) {
                case 1:T->bf = -1,temp->bf = 0;
                case 0: T->bf = 0,temp->bf=0;break;
                case -1:T->bf = 0,temp->bf = 1;break;
            }
            ather->bf = 0;
            L_rotate(T->left);R_rotate(T);
    }
}
void Right_balance(BTree &T)
{
    BTree temp = NULL;
    temp = T->right;
    switch (temp->bf) {
        case -1:T->bf = temp->bf = 0;L_rotate(T);break;
        case 1:
            BTree ather = temp->left;
            switch (ather->bf) {
                case 1:T->bf=0,temp->bf =-1;break;
                case 0: T->bf = temp->bf = 0;break;
                case -1:T->bf=1, temp->bf = 0;break;
            }
            ather->bf = 0;
            R_rotate(T->right);L_rotate(T);
    }
}
int insertAVL(BTree &one,char value,int &tall)
{
    if (!one){
        one = (BTree)malloc(sizeof(BaTree));
        one->data = value, one->bf = 0, one->left = one->right = NULL;
        tall = 1;
    }
    else{
        if (one->data==value){tall = 0; return 0;}//已经插入了
        else if (one->data > value){//去左子树找
            if(!insertAVL(one->left,value,tall))return 0;
            if (tall){
                switch (one->bf) {
                    case 1:Left_balance(one);tall = false;break;//原来的左子树比右子树高
                    case 0:one->bf = 1, tall = 1;break;//左右等高
                    case -1:one->bf = 0, tall = 0;break;
                }
            }
        }
        else{
            if (!insertAVL(one->right,value,tall)) return 0;//没有插入
            if (tall){
                switch (one->bf) {
                    case 1: one->bf = 0;break;//如果左子树高于右子树，此时等高
                    case 0: one->bf = -1,tall = 1;break;//原来等高
                    case -1: Right_balance(one);tall = 0;break;//原来时候右子树高于左子树，则现在需要对右子树作平衡处理
                }
            }
        }
    }
    return 1;
}
int preorder_view(BTree T)
{
    if(T)
    {
        printf("%c",T->data);
        if(T->left) preorder_view(T->left);
        if(T->right)  preorder_view(T->right);
    }
}
int inorder_view(BTree T)
{
    if(T==NULL) return 1;
    if(T)
    {
        if(T->left) inorder_view(T->left);
        printf("%c",T->data);
        if(T->right) inorder_view(T->right);
    }

}
int postorder_view(BTree T)
{
    if(T==NULL) return 1;
    if(T)
    {
        if(T->left) postorder_view(T->left);
        if(T->right) postorder_view(T->right);
        printf("%c",T->data);
    }
}
int rotate(BTree T,int deep)
{
    //将二叉树进行逆时针旋转90度
    if (T)
    {
        aoin(T->right,deep+1);
        for (int i = 1; i <=(deep-1)*4; ++i) {
            printf(" ");
        }
        printf("%c\n",T->data);
        aoin(T->left,deep+1);
    }

    else return 1;
}
int main()
{
    BTree one=NULL;
    char str[100]={0};
    int tall = 0;
    scanf("%s",&str);
    for (int i = 0; i < strlen(str); ++i) {
        insertAVL(one,str[i],tall);
    }
    printf("Preorder: ");
    preorder_view(one);
    printf("\n");
    printf("Inorder: ");
    inorder_view(one);
    printf("\n");
    printf("Postorder: ");
    postorder_view(one);

    printf("\nTree:\n");
    aoin(one,1);

    return 0;
}
