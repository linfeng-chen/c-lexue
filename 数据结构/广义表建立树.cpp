# include "iostream"
# include "stack"

using namespace std;
typedef struct Ptnode{
    char data;
    Ptnode *child[1000];
    int childnum;
} *CTree,Pnode;
void createtree(CTree &one,int &du)
{
   char c; 
   while((c = getchar())!='\n')
   {
        if(c=='(')
        {
            c = getchar();
            if(c!=')')
            {
               one = (CTree)malloc(sizeof(Pnode));
                one->data = c;
                one->childnum = 0;
            } 
           // cout<<c<<endl;
        }
        if(c==')') return ;
        if(c==',')//出现孩子了
        {
            one->childnum ++;
            if(one->childnum>du)du = one->childnum;
           //cout<<c<<" "<<one->childnum<<endl;
            createtree(one->child[one->childnum],du);//
        }
   }
   
}
int aoin(CTree T,int deep)
{
    //凹入表示
    if(T)
    {
        if(deep!=1)
        for(int i=1;i<=(deep-1)*4;i++)
        printf(" ");
        printf("%c\n",T->data);
        for(int i=1;i<=T->childnum;i++)
        {
            aoin(T->child[i],deep+1);
        }
    }

    else return 1;
}
int search(CTree T,int &num,int du)
{
    if(T)
    {
        if(T->childnum==du) num++;
        for(int i=1;i<=T->childnum;i++)
        {
           search(T->child[i],num,du);
        }
    }
}
int main()
{
    
    CTree one=NULL;
    int du=0;
    createtree(one,du);
    aoin(one,1);
    printf("Degree of tree: %d\n",du);
    for(int i=0;i<=du;i++)
    {
        
        int num =0;
        search(one,num,i);
        printf("Number of nodes of degree %d: %d\n",i,num);
    }
    return 0;
}