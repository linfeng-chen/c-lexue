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
    //���ַ�ת��Ϊ����
    char s_temp[10]={0};
    int k=0,j;
    for(j=i; (str[j]<='9'&&str[j]>='0')||(j==i&&str[j]=='-') ;j++)
        s_temp[k++] = str[j];

    int number = atoi(s_temp);
    need.push(number);
    return j-1;
}

int opra(stack<int>&number, stack<char>&op, int a1,int a2,char now)//a1,a2,a3�ֱ��Ӧһ������
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
    if(op.top()=='('&&a1&&!a2)op.pop();//ɾ��"("
    if(error==1) return 1;
    return 0;
}
int error_true(char str[], int i)
{
    //����Ƿ��Ǵ�����ʽ
    char one,two,three;
    one = str[i-1], two = str[i], three = str[i+1];
    if(one==')'||three =='(') return 1;//�����ǰ�������ţ��Ǵ�������Ϸ�
    if(isdigit(one)!=0&&isdigit(three)!=0) return 1; //�����ǰ�������ֺϷ�
    if(isdigit(one)!=0&&three=='-'&& isdigit(str[i+2])!=0) return 1;//ͬ�ϣ�ֻ�Ǻ�һ�����Ǹ���
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
        int flag=0;//�Ը�����صĲ���
        int error = 0;//���ʽ
        int count=0,count1=0;//�����ż����Դ����ж����Ŵ���
        scanf("%s",&str);
        for(int i=0;i<strlen(str);i++)//��������
        {
            if(str[i]=='(' || str[i]==')') //���ŵ�������
            {
                if(str[i]=='(')
                op.push(str[i]),count++;//������ֱ��ѹջ
                else{//��������
                    count1++;
                    int temp = opra(number,op,1,0,0);
                    if(temp==1) break;
                }
                continue;
            }
            if(str[i]<='9' && '0'<=str[i])//���������
            {
                int x = str_num(number,str,i);
                i = x;
            }
            else //����������ص�
            {
                char one = str[i];//��ǰ�ַ�
                if(one=='-')//���ڼ��ŵ�������
                {
                    if((str[i-1]==')'&& i-1>=0)||(i-1>=0 && isdigit(str[i-1])!=0))//��ʱ���-�Ǽ���
                          flag=1; 
                    else //�������Ϊ����
                    {
                        int x = str_num(number,str,i); i = x;
                        continue;
                    }
                }//���Ŵ������

                //�ж�������Ƿ񲻺Ϸ���
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
                else//��ջ���㴦��
                {
                    //ջ�����ǣ� �ҵ�ǰ���ȼ�С��ջ���ͳ�ջ����,�ڶ�������
                    error = opra(number,op,1,1,now);
                    op.push(one);
                    if(error==1)break;
                }//��ջ�������
            }//���������

        }//һ������
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