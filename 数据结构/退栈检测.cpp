# include "iostream"
# include "stack"

using namespace std;

int main()
{
    int n,m,a=0;
    while(1)
    {
        scanf("%d %d",&n,&m);
        a++;
        if(a!=1&&n!=0)printf("\n");
        while(m--)
        {
            int x = n,flag[1000]={0},final=1;
            stack<int> one;
            while(x--)
            {
                int temp;
                scanf("%d",&temp);
                if(one.size()==0||(temp>one.top()&&one.size()!=0))
                {
                    for(int i=1;i<=temp;i++)
                    {
                        if(flag[i]==0)
                        {flag[i]=1;
                        one.push(i);}
                    }
                    one.pop();
                }
                else if(temp==one.top()&&one.size()!=0)
                    one.pop();
   
                else if(temp<one.top())
                    final=0; 
            }
            if(final==0) printf("No\n");
            else printf("Yes\n");  
        }
        if(n==0)break; 
    }
}