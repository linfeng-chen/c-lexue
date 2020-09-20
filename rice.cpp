#include <iostream>
#include <queue>
#include <string>
#include "cstring"
//#include "string.h"
#define N 1000001
using namespace std;

queue<string>q;

int main()
{
    
    long long n,x;
    
    scanf("%lld",&n);
    while(n--)
    {
        char str1[50]={0};
        char name[20]={0};
        scanf("%s",&str1);
        if(strcmp(str1,"Arrive")==0)
        {
            scanf("%s",&name);
            q.push(name);
            //cout<<q.front()<<endl;
        }
        if(strcmp(str1,"Leave")==0)
        {
            if(q.empty()!=true)
            q.pop(); 
        }
        
        if(strcmp(str1,"QueueHead")==0)
        {
            if(q.empty()!=true)cout<<q.front()<<endl;
            else cout<<"Empty queue"<<endl;
        }
        if(strcmp(str1,"QueueTail")==0)
        {
            if(q.empty())cout<<"Empty queue"<<endl;
            else cout<<q.back()<<endl;
        }
        memset(str1,0,50);
        memset(name,0,20);
        
        
    }
    return 0;
}