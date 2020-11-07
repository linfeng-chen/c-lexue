# include "iostream"
# include "string.h"
#include "queue"
using namespace std;
typedef struct Gnode{
    char data;
    struct Gnode *left,*right;
}*Bigtree,Bitnode;

int search(char ino[],char c)
{
    for(int i=0;i<strlen(ino);i++)
        if(ino[i]==c) return i;
    return -1;
}
int crtbt(Bigtree &T,char last[], char ino[],int ps,int is,int n)
{
    if(n==0) return 0;
    else
    {
        int k = search(ino,last[ps+n-1]);
        if(k==-1) T=NULL;
        else
        {
            T = (Bigtree)malloc(sizeof(Bitnode));
            T->data = last[ps+n-1];
            if(k==is)
                T->left = NULL;
            else crtbt(T->left,last,ino,ps,is,k-is);
            if(k==is+n-1) T->right = NULL;
            else crtbt(T->right,last,ino,ps+k-is,k+1,n-(k-is)-1);
        }
    }
}

int cen_view(Bigtree T)
{
    //层次遍历
    queue<Bigtree>one;
    if(T==NULL) return 0;
    else
    {
        printf("%c",T->data);
        one.push(T);
        while(!one.empty())
        {
            Bigtree temp = one.front();
            one.pop();
            if(temp->left!=NULL){
                printf("%c",temp->left->data);one.push(temp->left);   
            }
            if(temp->right){
                printf("%c",temp->right->data);one.push(temp->right);
            }
        }
    }
}

int main()
{
    char last[100]={0},ino[100]={0};
    Bigtree T;
    scanf("%s",&ino);
    scanf("%s",&last);
    crtbt(T,last,ino,0,0,strlen(ino));
    cen_view(T);
    printf("\n");

    return 0;
}