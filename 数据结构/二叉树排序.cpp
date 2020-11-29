//
// Created by 19254 on 2020/11/26.
//
# include <iostream>
# include "algorithm"
using namespace std;
typedef  struct Tnode
{
    int data;
    struct Tnode *left,*right;
}TNode,*TreeNode;
bool search(TreeNode one,TreeNode temp, TreeNode &need, int key)
{
    if (!one){
        need = temp;
        return false;
    }//temp指向每次查找的父节点
    else if (key==one->data){
        need = one;
        return true;
    }
    else if (key<one->data) return search(one->left,one,need,key);
    else return search(one->right,one,need,key);
}
void insert(TreeNode &one,int key)
{
    TreeNode need = NULL,s=NULL;
    if (!search(one,NULL,need,key))
    {
        s = (TreeNode)malloc(sizeof(TNode));
        s->data = key;
        s->left = s->right = NULL;
        if(!need) one = s;
        else if(need->data > key) need->left = s;
        else need->right = s;
    }
}
int inorder(TreeNode T) //凹入表示
{
    if(T==NULL) return 1;
    if(T)
    {
        if(T->left) inorder(T->left);
        printf(" %d",T->data);
        if(T->right) inorder(T->right);
    }
}
int inorder_view(TreeNode T,int deep)
{
    if(T==NULL) return 1;
    if(T)
    {
        if(T->left) inorder_view(T->left,deep+1);
        for(int i=1;i<=(deep-1)*4;i++)
            printf(" ");
        printf("%d\n",T->data);
        if(T->right) inorder_view(T->right,deep+1);
    }
}
int main()
{
    TreeNode one = NULL;
    int num[1000] = {0};
    int i=0;
    while (true)
    {
        int a;
        scanf("%d ",&a);
        if(a==0) break;
        insert(one,a);
    }
    inorder_view(one,1);
    printf("\n");
    inorder(one);
    printf("\n");
    return 0;
}

