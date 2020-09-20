# include "stdio.h"
# include "stdlib.h"
#define N 400000
long number[N]={0};
long num1[N]={0};
long long count=0;
long  maopao(int num[],int n)//冒泡排序，弱鸡 
{
	long long i,j,tmp=0,end=0;
	for(i=1;i<n&!end;i++){
        end =1;
		for(j=0;j<n-i;j++){
			if(num[j]>num[j+1]){
				num[j]=num[j]^num[j+1],num[j+1]=num[j]^num[j+1],num[j]=num[j]^num[j+1];
                end = 0;tmp++;   
			}
		}	
    }
    printf("%lld\n",tmp);
} 
//归并排序
void insort(long num[],long first,long final)
{
	long  i,j,k,l;
	if(first==final) return;
	k=(first+final)/2;
	insort(num,first,k);
	insort(num,k+1,final);
	i=first;j=k+1;l=first;
	while(i<=k&&j<=final){
		if(num[i]<=num[j])num1[l++]=num[i++];
		else{ 
        num1[l++]=num[j++];
        count +=k+1-i;
        //printf("%ld %ld\n",k+1-i,k);
        }
	}
	while(i<=k)num1[l++]=num[i++];
	while(j<=final) num1[l++]=num[j++];
	for(i=first;i<=final;i++)
	num[i]=num1[i];
}
int main()
{
    
    long n;
    scanf("%ld",&n);
    for (long i = 0; i < n; i++)
    {
        scanf("%ld",&number[i]);
    }
    //maopao(number,n);
    insort(number,0,n-1);
  /*  for (long i = 0; i < n; i++)
    {
        printf("%ld ",number[i]);
    }*/
    printf("%ld\n",count);
    

    return 0;
}