# include "iostream"
#include "stack"
#include "ctype.h"
#include "string.h"
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
        case '^':
            return 3;
    }
}

int main()
{
    int n;
    cin>>n;
    getchar();
    while(n--)
    {
        stack<char>np;
        stack<char>num;
        stack<char>fianl;
        np.push('#');
        int flag=0;
        while(true)
        {
            char c ;
            scanf("%c",&c);
            if(c=='#') 
            {
                while(np.top()!='#'){
                    char x = np.top();
                    np.pop();num.push(x);
                }
                while(num.size()!=0){
                    fianl.push(num.top());num.pop();  
                }  
                 while(fianl.size()!=0){
                    cout<<fianl.top();
                    fianl.pop();
                }  
            }
            if(c=='\n'){
                printf("\n"); break;
            }
            if(isalpha(c)!=0){
               flag = 1; num.push(c);//将变量直接压栈
                continue ;
            }
            if(c=='(' || c==')') //括号单独处理
            {
                if(c=='(')
                np.push(c),flag = 2;//左括号直接压栈
                else{
                    while(np.top()!='(')
                    {
                        char x = np.top();
                        np.pop();num.push(x);
                    }
                    np.pop();
                }
            }
            else{
              /*  if((c=='-'&& flag==0)||(c=='-'&&flag==2))//负数处理{
                    num.push(c);
                    continue ;
                }*/
                int now = compare(c);
                //if(np.top()=='('||(now>=compare(np.top())&&np.top()!='(')||np.top()=='#')//如果栈顶是(，或者当前优先级较高就压栈
                  if(np.top()=='('||np.top()=='#'||now==3)  
                    np.push(c),flag=2;
                    else if(np.top()=='('||np.top()=='#'||(now>compare(np.top())&&np.top()!='('))
                        np.push(c),flag=2;
                else
                {
                    //栈顶不是（ 且当前优先级小于栈顶就出栈到（
                    while(np.top()!='('&& compare(np.top()) >=now && np.top()!='#')
                    {
                        char x = np.top(); 
                        np.pop(); num.push(x);
                    }
                    np.push(c);
                    flag =2 ;
                }
            }   
        } 
    }   
    return 0;
}