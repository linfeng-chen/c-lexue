//
// Created by 19254 on 2020/12/9.
//
//
// Created by 19254 on 2020/12/2.
//
# include "algorithm"
# include "iostream"
# include "cstring"
# include "stack"
# include "vector"
# include "deque"

using namespace std;
//allworld存放表达式中按顺序出现的字符
vector<int>final;//真值表
vector<int>zhuxiqu,zhuhequ;//主析取，主合取范式
vector<int>accord;//记录真值表对应的大小
char began='z';

typedef struct node{
    char data;
    int flag;//存放运算符时，加入一个标识符，遇到！运算时，可以单独处理一下
}Node;
int op(int a,char c,int b)
{
    //!非与加减中的负号类似
    switch (c) {
        case '|':return a||b;
        case '&':return a&&b;
        case '!':return !a;
        case '-':return a==1&&b==0?0:1;
        case '+':return a==b?1:0;
    }
}
int counter(char str[])
{
    //记录有变量的数量
    int flag[300]={0},count=0,i;
    for (i = 0; i < strlen(str); ++i) {
        if (flag[str[i]]==0&&isalpha(str[i]))count++,flag[str[i]]=1;
        if(str[i]<began&&isalpha(str[i]))began = str[i];
    }
    return count;
}
void print(vector<int>final,int count,int jie)
{
    printf("**%d\n",jie-1);
    for (int i = 0; i < final.size() ; ++i) {
        printf("%d ",final[i]);
        if ((i+1)%count==0)
            printf("\n");
    }
}//打印函数，检验错误
void push(int real[],int count)
{
    //将每次建立的真值表存下来,连着存就好;
    int sum=0;
    for (int i = 1; i <= count ; ++i) {
        final.push_back(real[i]);
        if (real[i]==1)
            sum += 1<<(count-i);
    }
    accord.push_back(sum);
}
void dfs_real(int real[],int count,int big,int cen)
{
    if (cen>count) return;
    for (int i = 0; i <=1 ; ++i) {
        real[cen] = i;
        big -= i;
        if (big>=0)dfs_real(real,count,big,cen+1);
        if (big==0&&cen==count) push(real,count);
        big +=i;
    }
}
void transfor(int need[],vector<int>final,int num,int count)
{
    char c = began;
    for (int i = (num-1)*count; i < num*count ; ++i) {
        need[c++] = final[i];
    }
}//need为字母，final为对应的真值,num为第几个
void operate(stack<Node>&ops,stack<int>&number,int x,int xu)
{
    Node front ;
    while (ops.size()&&(x==1?1:ops.top().data!='(')){
        //单独判断一下！运算即可
        Node c = ops.top();ops.pop();
        if(ops.size()>0)front = ops.top();
        int x,y;
        if(c.data=='!'&&c.flag==1)//这个符号是!
        {
            x = number.top(); number.pop();
            int result = op(x,c.data,0);
            number.push(result);
//            printf("result:%d\n",result);
        }
        else{
            x = number.top(), number.pop();
            y = number.top(), number.pop();
            if(front.data=='!'&&ops.size()>0) y = !y,ops.pop();
            int result = op(y,c.data,x);
            number.push(result);
//            printf("%d %c %d result:%d\n",y,c,x,result);
        }
    }
    if(x==0) ops.pop();//删掉剩余的左括号
    if(x==1)
    {
        if(number.top()==1)zhuxiqu.push_back(accord[xu-1]);
        else zhuhequ.push_back(accord[xu-1]);
    }
}
int built_real_solve(int count,char str[]) {
    //建立真值表
    int real[20]={0};
    int world[200] = {0};
    for (int i = 0; i <=count; ++i) {
        memset(real,0,sizeof(real));
        final.clear();accord.clear();
        dfs_real(real,count,i,1);
        for (int j = 1; j <=final.size()/count; ++j) {
            memset(world,0,sizeof(world));
            transfor(world,final,j,count);
            stack<Node>operators;stack<int>number;
            //开始处理字符串
            for (int k = 0; k < strlen(str); ++k) {
                if (str[k]>='a'&&str[k]<='z')//变量
                    number.push(world[str[k]]);
                else if (str[k]=='('||str[k]==')'){
                    if (str[k]=='('){
                        Node one;
                        one.flag=0,one.data='(';operators.push(one);
                    }
                    else  operate(operators,number,0,j);//运算
                }
                else{
                    char c = str[k]; Node one;
                    if (c=='!'){
                        one.flag=1,one.data=c;operators.push(one);
                    }
                    else{
                        one.flag = 0;one.data = c;operators.push(one);
                    }
                }//遇到运算符
            }
            operate(operators,number,1,j);
        }
    }
    return 0;
}
int main(){
    char str[100]={0};
    int world[200] = {0},*flag=NULL;
    scanf("%s",&str);
    int count = counter(str);
    built_real_solve(count,str);
    sort(zhuxiqu.begin(),zhuxiqu.end());sort(zhuhequ.begin(),zhuhequ.end());

    if(zhuxiqu.size()!=0&&zhuhequ.size()!=0) {
        printf("YES\n");
    }
    else{
        if(zhuxiqu.size()==1<<count)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}

