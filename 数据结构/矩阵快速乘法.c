# include "stdio.h"
#include "stdlib.h"
# include "string.h"


typedef struct 
{
    int i,j;
    int e;
}Triple;
typedef struct{
    Triple data[101];
    int nu,mu,tu;
    int rpos[101];
}TSMatrix;


TSMatrix M,N,Q;

int FastTransposeSMatrix()
{
    int num[101]={0};
    if(M.tu)
    {
        for(int t=1;t<=M.tu;t++) ++num[M.data[t].i];//求每一行的非零元个数
        M.rpos[0] =1;
        for(int col=1;col<=M.mu;col++) 
        {
            M.rpos[col] =M.rpos[col-1] + num[col-1];
        }
    } 
    memset(num,0,sizeof(int)*101);
    if(N.tu)
    {
        for(int t=1;t<=N.tu;t++) ++num[N.data[t].i];//求每一行的非零元个数
        N.rpos[0] =1;
        for(int col=1;col<=N.mu;col++) 
        {
            N.rpos[col] =N.rpos[col-1] + num[col-1];
        }
    }  


}


int MultMatrix()
{
    if(M.nu!=N.mu)return 0;
    int ctep[201]={0};
    Q.mu = M.mu, Q.nu = N.nu, Q.tu=0;//初始化
    int tp,t;
    if(M.tu*N.tu!=0)
    {
        for(int arow=1;arow<=M.mu;++arow)
        {
            // ctep[arow]=0;
            memset(ctep,0,sizeof(ctep));
            Q.rpos[arow] = Q.tu+1;
            if(arow<M.mu) tp = M.rpos[arow+1];
            else tp = M.tu+1;
            for(int p = M.rpos[arow];p<tp;++p)//对当前行的每一个非零元素
            {
                int brow = M.data[p].j;//找到对应元在N的行号
                if(brow< N.mu) t = N.rpos[brow+1];
                else t = N.tu+1;

                for(int q = N.rpos[brow];q<t;++q)
                {
                    int ccol = N.data[q].j;//乘积元素在Q的列号
                    ctep[ccol] += M.data[p].e * N.data[q].e;
                }

            }
            for(int ccol = 1;ccol <= Q.nu;++ccol)
            if(ctep[ccol]!=0)
            {
                //if(++Q.tu > 1000) return 0;
                Q.data[++Q.tu].i = arow,Q.data[Q.tu].j = ccol,Q.data[Q.tu].e = ctep[ccol];
            }
        }
    }
}
int main()
{

    int m,n,number;
    
    scanf("%d%d%d",&m,&n,&number);
    M.mu = m,M.nu=n,M.tu = number;
    for(int k=1;k<=number;k++)
    {
        int i,j,e;
        scanf("%d %d %d",&i,&j,&e);
        M.data[k].i = i, M.data[k].j = j, M.data[k].e = e;
    }
    scanf("%d%d%d",&m,&n,&number);
    N.mu = m,N.nu=n,N.tu = number;
    for(int k=1;k<=number;k++)
    {
        int i,j,e;
        scanf("%d %d %d",&i,&j,&e);
        N.data[k].i = i, N.data[k].j = j, N.data[k].e = e;
    }
    FastTransposeSMatrix();
    MultMatrix();

    printf("%d\n%d\n%d\n",Q.mu,Q.nu,Q.tu);
    for(int i=1;i<=Q.tu;i++)
    printf("%d,%d,%d\n",Q.data[i].i,Q.data[i].j,Q.data[i].e);
    

    return 0;
}