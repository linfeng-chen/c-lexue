# include "stdio.h"
# include "stdlib.h"

typedef struct Lnode
{
    int coef;
    int expn;
    struct Lnode *next;

}Lnode, *Linklist;

void CreatePolyn (Linklist &P, int m)
{
    P = (Linklist)malloc(sizeof(Lnode));
    Linklist head = P;
    P->next = NULL;
    for(int i=1;i<=m;i++)
    {
        Linklist q = (Linklist) malloc(sizeof(Lnode));
        scanf("%d %d",&q->coef,&q->expn);
        q->next = P->next;
        P->next = q;
        P = q;
    }
  /*  while(head->next!=NULL)
    {
        printf("%d %d ",head->next->coef,head->next->expn);
        head = head->next;
    }
    printf("\n");*/
    P = head;

}

void AddPolyn(Linklist &p, Linklist q)
{
    Linklist head = p;
    Linklist pa = p->next, qa = q->next;
    while(pa&&qa)
    {   
       // printf("%d %d\n",pa->expn,qa->expn);
        if(pa->expn < qa->expn)//如果a的指数小于b
        {
            p = pa, pa = pa->next;
        }
        else if (pa->expn > qa->expn)//a的指数大于b
        {
            q->next = qa->next;
            qa->next = pa, p->next = qa, p = p->next;
            qa = q->next;
        }
        else//a的指数等同于b
        {
            int sum = pa->coef + qa->coef;
            if(sum!=0)
            {
                pa->coef = sum;
                p = pa;
                pa = pa->next;
                q = qa;
                qa = qa->next;
            }

            else//删除p中当前节点
            {
                pa = pa->next;
                p->next = pa;
                qa = qa->next;
                q ->next = qa;
            }
            
        }
    }
    if(qa!=NULL) p->next = qa;
    //printf("%d %d\n",p->coef,p->expn);
    //printf("%d %d\n",qa->coef,qa->expn);
    // while(head->next!=NULL)
    // {
    //     printf("<%d %d>",head->next->coef,head->next->expn);
    //     head = head->next;
    // }
    p = head;
}
void Print(Linklist p)
{
    if(p->next==NULL)
    {
        printf("<0,0>\n");
        return ;
    }
    while(p->next->next!=NULL)
    {
        printf("<%d,%d>,",p->next->coef,p->next->expn);
        p = p->next;
    }
    printf("<%d,%d>\n",p->next->coef,p->next->expn);
}
int main()
{
    int choice,n1;
    Linklist Pa,Pb,Pc;
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
        scanf("%d",&n1);
        CreatePolyn(Pa,n1);
        scanf("%d",&n1);
        CreatePolyn(Pb,n1);
        scanf("%d",&n1);
        CreatePolyn(Pc,n1);
        Print(Pa);
        Print(Pb);
        Print(Pc);
        AddPolyn(Pa,Pb);
        Print(Pa);
        AddPolyn(Pa,Pc);
        Print(Pa);
        break;
    
    default:
        break;
    }

    return 0 ;
}
