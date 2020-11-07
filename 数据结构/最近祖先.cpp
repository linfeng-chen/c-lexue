# include "iostream"
using namespace std;

int main()
{
    int n,num[100]={0},i,j;
    scanf("%d",&n);
    for(int k=1;k<=n;k++)
    scanf("%d",&num[k]);
    scanf("%d %d",&i,&j);
    if(num[i]==0)
    {
        printf("ERROR: T[%d] is NULL\n",i);
        return 0;}
    if(num[j]==0)
    {
        printf("ERROR: T[%d] is NULL\n",j);
        return 0;
    }
    while(i!=j)
    {
        if(i>j)i=i/2;
        if(j>i)j=j/2;
    }
    printf("%d %d\n",i,num[i]);
    
    return 0;
}