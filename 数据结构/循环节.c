#include <stdio.h>  
#include <stdlib.h>  
  
typedef struct node  
{   int         data;  
    struct node * next;  
} NODE;  
  
void output( NODE *, int );  
//void change( int, int, NODE * );  

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
                break;
            }
        }
        if(temp==1) break;
        a++;
        p = q;
    }
}
  
void output( NODE * head, int kk )  
{   
    int k=0;  
    printf("0.");  
    while ( head->next != NULL && k<kk )  
    {   printf("%d", head->next->data );  
        head = head->next;  
        k ++;  
    }  
    printf("\n");  
}  
  
int main()  
{   int n, m,k;  
    NODE * head;  
  
    scanf("%d%d%d", &n, &m, &k);  
    head = (NODE *)malloc( sizeof(NODE) );  
    head->next = NULL;  
    head->data = -1;  
    change( n, m, head );  
    output( head,k );  
    return 0;  
}  
     
