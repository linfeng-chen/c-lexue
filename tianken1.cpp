#include <iostream>
#include <stack>
#include "cstring"
#define N 1000001

using namespace std;

int main()
{
    
    long n,i,h;
    while((scanf("%ld",&n))!=EOF)
    {
        stack<long>soil;
        while(n--)
        {
            scanf("%ld",&h);
            if(soil.empty()) soil.push(h);
            else
            {
                if(abs(h-soil.top())%2==0) soil.pop();
                else soil.push(h);   
            }
        }
        if(soil.size()==0||soil.size()==1)
        cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

    }
    return 0;
}