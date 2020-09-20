#include <iostream>
#include <stack>
#include "cstring"
#define N 1000001
using namespace std;


long color[N]={0};
long high[N]={0};
long need[N]={0};
long exist[N]={0};
int main()
{
    long i,j,n,t,h;
    scanf("%ld",&t);
    while (t--)
    {
        stack<long>house;
        scanf("%ld",&n);
        for(i=1;i<=n;i++)
            scanf("%ld",&color[i]);
        long num_color=0;
        for(i=1;i<=n;i++)
        {
            scanf("%ld",&high[i]);
            if(house.empty())
            {
                house.push(i);
                need[i]=1,num_color=1,exist[color[i]]++;
                //cout<<"现在可见房子数与颜色数；"<<house.size()<<" "<<need[i]<<endl;
            } 
            else
            {
                if(high[i]<high[house.top()]) 
                {
                    house.push(i);
                    if(exist[color[i]]==0) num_color++;
                    exist[color[i]]++;
                    need[i] = num_color;
                    //cout<<"现在可见房子数与颜色数；"<<house.size()<<" "<<need[i]<<endl;
                }
                else 
                {
                    while(!house.empty()&&high[i]>=high[house.top()])
                    {
                        if(exist[color[house.top()]]==1) num_color--;
                        exist[color[house.top()]]--;
                        house.pop();
                    }
                    if(exist[color[i]]==0) num_color++;
                    exist[color[i]]++;   
                    need[i]=num_color;     
                    house.push(i);
                  // cout<<"现在可见房子数与颜色数；"<<house.size()<<" "<<need[i]<<endl;
                }
            }    
        }
        
        for(i=1;i<n;i++)
            printf("%d ",need[i]);
        printf("%ld\n",need[i]);
        memset(exist,0,1000000);
    }
    
	return 0;
}