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
        long max=0,flag=0;
        while(n--)
        {
            scanf("%ld",&h);
            if(soil.empty()) soil.push(h);
            else
            {
                if(h==soil.top()) soil.pop(),max = h>max?h:max;
                else 
                {
                    if(h>soil.top()) flag=1;
                    soil.push(h);   
                }
            }
        }
        if(flag==1||soil.size()!=0&&soil.size()!=1)
            cout<<"NO"<<endl; 
        else
        {
            if(soil.size()==0||(soil.size()==1&&max<=soil.top()))cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
             
    }
    return 0;
}