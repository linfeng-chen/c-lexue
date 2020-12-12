# include "iostream"
using namespace std;
void AdjustHeap(int num[],int begin,int end)
{
    //逐步调整成为大根堆
    int temp = num[begin];
    for(int i = 2*begin; i<=end;i *=2)
    {
        if(num[i+1]>num[i]&&i<end)//在孩子中寻找较大者位置
            i++;
        if(temp>num[i])break;//当前值比孩子都大
        num[begin] = num[i];begin = i;
    }
    num[begin] = temp;
    return ;
}
void Sortheap(int num[],int n)
{
    for (int i = n/2; i>=1; --i) {
        AdjustHeap(num,i,n);
    }
    for(int i=1;i<=n;i++)printf("%d ",num[i]);
    printf("\n");
    for (int i = n; i >1 ; --i) {
        //交换第一个与最后一个的值
        int temp = num[i];
        num[i] = num[1], num[1] = temp;
        //重建大根堆
        AdjustHeap(num,1,i-1);
        if(n-i<2&&n-i>=0) {
            for (int j = 1; j <= i-1; j++)printf("%d ", num[j]);
            printf("\n");
        }
    }
}
int main(){
    int n=0,num[1000]={0};
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&num[i]);
    Sortheap(num,n);
    return 0;
}