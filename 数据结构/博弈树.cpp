# include "iostream"
using namespace std;


typedef struct Ptnode{
    char data;
    Ptnode *child[1000];
    int childnum;
    int high;
} *CTree,Pnode;

void createtree(CTree &one)
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
                one->high = 0;
            } 
        }
        if(c==')')
        {
            int max=0;
            for(int i=1;i<=one->childnum;i++)
            if(one->child[i]->high>max)max=one->child[i]->high;
            one->high = max+1;
            return ; 
        }     
        if(c==',')//出现孩子了
        {
            one->childnum ++;
            createtree(one->child[one->childnum]);//
        }
   } 
}
int aoin(CTree T,int deep)
{
    if(T)
    {
        // printf("%c %d %d\n",T->data,T->high-1,T->childnum);
        printf("%c\n",T->data);
        for(int i=1;i<=T->childnum;i++)
            aoin(T->child[i],deep+1);
    }
    else return 1;
}

void xx(CTree one,int high,int &flag)
{
    //判断这条路径是否保证赢,只要找到一条路径是奇数高度，说明不能保证赢了；
    if(one->childnum==0)
    {
        if(high%2==0) flag=1;
        return ;
    }
    for(int i=1;i<=one->childnum;i++)
        xx(one->child[i],high+1,flag);
}
int choiced(CTree &one)
{
    if(one)
    {
        int i,count=0;
        int flag1[100]={0};
        for(i=1;i<=one->childnum;i++)//查询是否有直接可以赢的选择
        {   
            if(one->child[i]->childnum==0)//如果遇到了节点已经是叶子节点
            {
                one = one->child[i];
                return 1;
            }
            else//如果是非叶子节点，那么需要去查看它下面的节点是否能赢，可递归求得 
            {
                int flag=-1;
                xx(one->child[i],1,flag);
                if(flag==1) count++,flag1[i]=1;;
            }
        }
        // printf("count:%d\n",count);
        if(count!=one->childnum)//说明有些路可以赢有些不可以
        { 
            int min=100,step;
            for(i=1;i<=one->childnum;i++)
            {
                if(one->child[i]->high<min&&flag1[i]!=1)min=one->child[i]->high,step=i;
            }
            one = one->child[step];return 0;
        }
        if(count==one->childnum)//没有可以赢的路，就选择高度最高最左边的路
        {
            int max=0,step;
            for(i=1;i<=one->childnum;i++)
            {
                if(one->child[i]->high>max)max=one->child[i]->high,step=i;
            }
            one = one->child[step];return 0;
        }
    }
}

int main()
{
    CTree one,temp;
    createtree(one);
    temp = one;
    aoin(one,1);
    while(true)
    {
        one = temp;
        printf("Who play first(0:computer;1:player)?\n");
        int choices;
        scanf("%d",&choices);
        getchar();
        if(choices==1)//人先走
        {
            while (true)
            {
                printf("player:\n");
                char c;
                scanf("%c",&c);getchar();
                int i;
                for(i=1;i<=one->childnum;i++)
                if(one->child[i]->data==c)  break;
                if(i>one->childnum) {
                    printf("illegal move.\n"); continue;
                }
                one = one->child[i];
                if(one->childnum==0)
                {
                    printf("Congratulate,you win.\n");
                    break;
                }
                choiced(one);
                printf("computer:%c\n",one->data);
                if(one->childnum==0)
                {
                    printf("Sorry,you lost.\n");
                    break;
                }
            }
        }
        if(choices==0)//电脑先走
        {
            while (true)
            {
                choiced(one);
                printf("computer:%c\n",one->data);
                if(one->childnum==0)
                {
                    printf("Sorry,you lost.\n");
                    break;
                }
                printf("player:\n");
                char c;
                scanf("%c",&c);getchar();
                int i;
                for(i=1;i<=one->childnum;i++)
                if(one->child[i]->data==c||one->child[i]->data=='f') {
                     break;
                }
                if(i>one->childnum) {
                    printf("illegal move.\n"); continue;
                }
                one =  one->child[i];
                if(one->childnum==0)
                {
                    printf("Congratulate,you win.\n");
                    break;
                }   
            }
        }
        printf("Continue(y/n)?\n");
        char cho;
        scanf("%c",&cho);
        if(cho=='n')break;
    } 
    return 0;
}