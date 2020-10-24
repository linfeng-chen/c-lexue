# include "iostream"
# include "stack"
# include "string.h"
#include "math.h"
using namespace std;

int compare(char c)
{
    switch (c)
    {
        case '+':
            return 1;
        case '-':
            return 1;
        case '*':
            return 2;
        case '/':
            return 2;
        case '%':
            return 2;
        case '^':
            return 3;
    }
}

int ope(int a,int b,char c)
{
    if (c=='*') return a*b;
    if (c=='%') return a%b;
    if (c=='+') return a+b;
    if (c=='-') return a-b;
    if (c=='/') return a/b;
    if (c=='^') return pow(a,b);
}

int str_num(stack<int>&need,char str[],int i)
{
    //将字符转化为数字
    char s_temp[10]={0};
    int k=0,j;
    for(j=i; (str[j]<='9'&&str[j]>='0')||(j==i&&str[j]=='-') ;j++)
        s_temp[k++] = str[j];

    int number = atoi(s_temp);
    need.push(number);
    return j-1;
}

int opra(stack<int>&number, stack<char>&op, int a1,int a2,char now)//a1,a2,a3分别对应一种运算
{
    int error = 0;
    while((a1==1?op.top()!='(':1)&&op.top()!='#'&&(a2==1?now<=compare(op.top()):1))
    {
        if(number.size()<2){
            printf("error.\n");error = 1;
            break;
        }
        int y = number.top(); number.pop();
        int x = number.top(); number.pop();
        char c = op.top(); op.pop();
        if(c=='/'&&y==0){
            printf("Divide 0.\n");error=1;
            break;
        }
        if(c=='^'&&y<0){
           printf("error.\n");error=1;
            break;
        }
       // printf("%d %c %d %d\n",x,c,y,ope(x,y,c));
        number.push(ope(x,y,c));
    }
    if(op.top()=='('&&a1&&!a2)op.pop();//删除"("
    if(error==1) return 1;
    return 0;
}
int error_true(char str[], int i)
{
    //检测是否是错误表达式
    char one,two,three;
    one = str[i-1], two = str[i], three = str[i+1];
    if(one==')'||three =='(') return 1;//运算符前后是括号，那此运算符合法
    if(isdigit(one)!=0&&isdigit(three)!=0) return 1; //运算符前后是数字合法
    if(isdigit(one)!=0&&three=='-'&& isdigit(str[i+2])!=0) return 1;//同上，只是后一个数是负数
    return 0;
}

int main()
{
    int n,num;
    cin>>n;
    while(n--)
    {
        char str[1000]={0};
        stack<char> op;
        stack<int> number;
        op.push('#');
        int flag=0;//对负数相关的操作
        int error = 0;//表达式
        int count=0,count1=0;//对括号计数以此来判断括号错误
        scanf("%s",&str);
        for(int i=0;i<strlen(str);i++)//处理数据
        {
            if(str[i]=='(' || str[i]==')') //括号单独处理
            {
                if(str[i]=='(')
                op.push(str[i]),count++;//左括号直接压栈
                else{//进行运算
                    count1++;
                    int temp = opra(number,op,1,0,0);
                    if(temp==1) break;
                }
                continue;
            }
            if(str[i]<='9' && '0'<=str[i])//如果是数字
            {
                int x = str_num(number,str,i);
                i = x;
            }
            else //运算符处理，重点
            {
                char one = str[i];//当前字符
                if(one=='-')//对于减号单独处理
                {
                    if((str[i-1]==')'&& i-1>=0)||(i-1>=0 && isdigit(str[i-1])!=0))//此时这个-是减号
                          flag=1; 
                    else //其他情况为负号
                    {
                        int x = str_num(number,str,i); i = x;
                        continue;
                    }
                }//减号处理完毕

                //判断运算符是否不合法；
                int error_one = error_true(str, i);
                if(error_one ==0 ){
                    printf("error.\n",one);error=1;
                    break;
                }
                int now = compare(one);
                if(op.top()=='('||op.top()=='#'||now==3)  
                    op.push(one);
                else if(op.top()=='('||op.top()=='#'||(now>compare(op.top())&&op.top()!='('))
                    op.push(one);
                else//出栈运算处理
                {
                    //栈顶不是（ 且当前优先级小于栈顶就出栈到（,第二种运算
                    error = opra(number,op,1,1,now);
                    op.push(one);
                    if(error==1)break;
                }//出栈处理完毕
            }//运算符处理

        }//一行走完
        if(error==1) continue;
        if(count1!=count) {
           printf("error.\n"); continue;
        }
        error = opra(number,op,0,0,0);
        if(error==1)continue;
        if(number.size()>1||op.size()!=1)
        {printf("error.\n");continue;
        }
        // printf("%d %d %d %c\n",op.size(),number.size(),number.top(),op.top());
        if(error==0)
            printf("%d\n",number.top());
    }
}