/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */  
 
#include <iostream>  
using namespace std;  
  
typedef int ElemType;  
typedef struct node  
{   ElemType    data;  
    struct node * next;  
} NODE;  
typedef NODE * LinkList;  
  
void output( LinkList );  
void change( int, int, NODE * );  
LinkList createList( ElemType );  
void inverse( LinkList );   
  
LinkList createList( ElemType finish )  //finish：数据结束标记   
{  
    ElemType x;  
    NODE *newNode;   
    LinkList first = new NODE;   // 建立头结点  
    first->next = NULL;  
    first->data = finish;  
    cin >> x;                 // 约定以finish结束连续输入  
    while ( x != finish )  
    {  
        newNode = new NODE;      // 建立新结点  
        newNode->data = x;  
        newNode->next = first->next; // ①  
        first->next = newNode;       // ②  
        cin >> x;  
    }  
    return first;  
}  


void inverse( LinkList head)
{
    LinkList p = new NODE, q = head;
    NODE *newNode;  
    p->next = NULL;
    while(q->next!=NULL)
    {
        newNode = new NODE;
        newNode->data = q->next->data;
        newNode->next = p->next;
        p->next = newNode;
        q = q->next;
    }
    while(head->next!=NULL&&p->next!=NULL)
    {
        head->next->data = p->next->data;
        head = head->next;
        p = p->next;
    }
}
void output( LinkList head )  
{   cout << "List:";  
    while ( head->next != NULL )  
    {   cout << head->next->data<< ",";  
        head = head->next;  
    }  
    cout << endl;  
}  
  
int main(int argc, char** argv)   
{  
    LinkList head;  
    head = createList( -1 );  
    output( head );  
    inverse( head );  
    output( head );  
    return 0;  
}  
