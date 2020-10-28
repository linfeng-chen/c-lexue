# include "iostream"
# include "string.h"

using namespace std;
 int num[1000]={0}, cpot[1000]={0};

typedef struct 
{
    int i,j;
    int e;
}Triple;
typedef struct{
    Triple data[10000];
    int nu,mu,tu;
}TSMatrix;

int FastTransposeSMatrix(TSMatrix M, TSMatrix &T)
{
    T.mu = M.nu,T.nu = M.mu,T.tu = M.tu;
    int col,t,p;
    if(T.tu)
    {
       // for(col=1;col<=M.nu;++col)num[col] = 0;
        for(t=1;t<=M.tu;t++) ++num[M.data[t].j];//求每一列的非零元个数
        cpot[1] =1;
        
        for(col=2;col<=M.nu;col++) cpot[col] = cpot[col-1] + num[col-1];

        printf("num:");
        for(int i=1;i<=M.nu;i++)
        printf("%d,",num[i]);
        printf("\ncpot:");
        for(int i= 1;i<=M.nu;i++)
        printf("%d,",cpot[i]);
        for(p=1;p<=M.tu;++p)
        {
            col = M.data[p].j;
            int q = cpot[col];
            T.data[q].i = M.data[p].j, T.data[q].j = M.data[p].i, T.data[q].e = M.data[p].e;
            ++cpot[col];
        }
    }
}
int main()
{

    int m,n,number;
    TSMatrix M,T;
    scanf("%d %d %d",&m,&n,&number);
    M.mu = m, M.nu=n, M.tu=number;
    for(int k=1;k<=number;k++)
    {
        int i,j,e;
        scanf("%d %d %d",&i,&j,&e);
        M.data[k].i = i,M.data[k].j=j,M.data[k].e = e;
        
    }
    FastTransposeSMatrix(M,T);

    
    printf("\n");
    for(int i =1;i<=number;i++)
    printf("%d,%d,%d\n",T.data[i].i,T.data[i].j,T.data[i].e);

    return 0;
}