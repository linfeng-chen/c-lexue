#include "iostream"

using namespace std;
long flag[100000]={0};
int main()
{
    long n,m,k,j;
    scanf("%ld,%ld,%ld",&n,&k,&m);
    if(k>n) printf("k should not bigger than n.\n");
    else if(n<1||m<1||k<1) printf("n,m,k must bigger than 0.\n");
    else
    {
        for(long i=1;i<=n;i++)
        {
            long a=0;
            for(j=k;j<=n;j++)
            {
                if(flag[j]==0) a++;
                if(j==n&&a!=m) j=0;
                if(a==m) 
                {
                    if(i%10!=0&&i!=n)
                    printf("%d ",j);
                    else printf("%d\n",j);
                    flag[j]=1;
                    break;
                }
            }
            if(j==n) k=1;
            else k=j;
        }
    }
    
    

    return 0;
}