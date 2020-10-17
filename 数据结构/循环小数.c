/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */  
 
#include <stdio.h>  
#include <stdlib.h>  
typedef struct node  
{   int         data;  
    struct node * next;  
} NODE;  
  
NODE * find( NODE * , int * );  
void outputring( NODE * );  
void change( int , int , NODE * );  
void outputring( NODE * pring )  
{   NODE * p;  
    p = pring;  
    if ( p == NULL )  
        printf("NULL");  
    else  
        do  {   printf("%d", p->data);  
            p = p->next;  
        } while ( p != pring );  
    printf("\n");  
    return;  
}  


int flag[1000]={0},flag1[30000]={0};
void change(int n, int m, NODE *head)
{
    int i,j,k,began=0;
    int x=0,a=1;
    NODE *p = head,*q=NULL;
    while(1)
    {
        x = (n*10)/m;
        n =(n*10)%m;
        flag[a] = x;
        flag1[a] = n; 
        q = (NODE*) malloc (sizeof(NODE));
        q->data = x;
        q->next == NULL;
        p->next = q;

        if(x==0&&n==0)//被整除了
        {
            p->next = NULL;
            break;
        }
        int temp = 0;
        NODE *need = head;
        for(i=1;i<a;i++)
        {
            need = need->next;
            if(flag[i]==x&&flag1[i]==n)
            {
                temp = 1;
                p->next = need;
                head ->data = i;
                break;
            }
        }
        if(temp==1) break;
        a++;
        p = q;
    }
}

NODE * find( NODE * head, int * n ) 
{ 
    NODE *p = head;
    if(head->data==-1)
    {
        *n=0;
        return NULL;
    }
    int a = 1;
    //printf("**%d\n",head->data);//将开始节点的位置储存在头节点的数据中
    while (p->next!=NULL && a++<=head->data)
    {
        //printf("%d",p->next->data);
        p = p->next;
    }//找到循环节开始
    NODE *q = p;
    int sum=0;
    do { 
            sum++;
            q = q->next;  
        } while ( q != p );  
    *n = sum;
    return p;
} 
int main()  
{   int n, m;  
    NODE * head, * pring;  
  
    scanf("%d%d", &n, &m);  
    head = (NODE *)malloc( sizeof(NODE) );  
    head->next = NULL;  
    head->data = -1;  
  
    change( n, m, head );  
    pring = find( head, &n );  
    printf("ring=%d\n", n);  
    outputring( pring );  
  
    return 0;  
}  
  

  
