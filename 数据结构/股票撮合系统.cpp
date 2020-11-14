# include "iostream"
# include "string.h"
# include "algorithm"
using namespace std;

typedef struct QNode{
    char code[5];
    float price;
    int number;
    char bs;
    struct QNode *next;
}QNode,*Queue;

typedef struct
{
    Queue front;
    Queue rear;   
}LinkQueue;

void initQueue(LinkQueue &q)
{
    //构造空队列
    q.front=q.rear=(Queue)malloc(sizeof(QNode));
    q.front->next = NULL;
}
void buy_sale(LinkQueue &q, char code[],float price, int number, char bs)//撮合队列
{
    
}
void inQueue(LinkQueue &q,char code[],float price, int number, char bs)
{
    Queue p;
    p = (Queue) malloc(sizeof(QNode));
    strcpy(p->code,code);
    p->price = price;
    p->number = number;
    p->bs = bs;
    p->next = NULL;
    q.rear->next = p;
    q.rear = p;

    printf("%s %f %d %c",q.rear->code,q.rear->price,q.rear->number,q.rear->bs);


}

int outQueue(LinkQueue &q, Queue&e)
{
    if(q.front==q.rear) return 0;
    Queue p;
    p = q.front->next;
    strcpy(e->code,p->code);
    e->price = p->price;
    e->number = p->number;
    e->bs = p->bs;
    q.front->next = p->next;
    if(q.rear==p) q.rear = q.front;
    free(p);
    
}
int main()
{
    LinkQueue buy,sale;
    initQueue(buy);initQueue(sale);
    while(true)
    {
        int choice;
        scanf("%d",&choice);
        if(choice==0)break;
        if(choice==1)
        {
            char code[5]={0};
            int number;
            float price;
            char bs;
            scanf("%s %f %d %c",&code,&price,&number,&bs);
            if(bs=='b') inQueue(buy,code,price,number,bs);
            if(bs=='s') inQueue(sale,code,price,number,bs);
        }
    }

    return 0;
}