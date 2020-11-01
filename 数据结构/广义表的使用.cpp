# include "iostream"
// # include "string.h"
# include "string"
using namespace std;

typedef struct GNode{
    int tag;
    union
    {
        char atom;
        struct{
            struct GNode *hp,*tp;
        }ptr;
    };
    
}*GList;
void destory(GList &L)
{
    if(!L) return;
    if(L->tag==1)
    {
        destory(L->ptr.hp);
        destory(L->ptr.tp);
    }
    free(L);
    L = NULL;
}
int server(string &str,string &hstr)//从sub分离表头串；
{
    int n =str.length(),i=-1,k=0;//k记录尚未配对的左括号个数
    string ch;
    do
    {
        ++i;
        ch = str.substr(i,1);
        if(ch=="(") ++k;
        else if(ch==")") --k;
        
    } while (i<n&&(ch!=","||k!=0));
    if(i<n){
        hstr = str.substr(0,i);
        str = str.substr(i+1,n-i);
        //cout<<hstr<<endl<<str<<endl;
    }
    else {
        hstr = str.substr(0,str.length());
        str.clear();
    }
}
void createGlist(GList &L, string str)
{
    GList p,q;
    if(str.compare("()")==0)L=NULL;
    else
    {
        if(str.length()==1){
            L = (GList)malloc(sizeof(GNode));
            L->tag = 0; L->atom = str[0];
        }
        else{
            L = (GList)malloc(sizeof(GNode));
            L->tag = 1;
            p=L;
            string sub = str.substr(1,str.size()-2);//去除两边的括号
            do
            {
                string hsub;
                server(sub,hsub);
                //cout<<hsub<<" "<<sub<<endl;
                createGlist(p->ptr.hp,hsub);
                q = p;
                if(!sub.empty()){
                    p = (GList)malloc(sizeof(GNode));
                    p->tag = 1; q->ptr.tp = p;
                }
            }while(!sub.empty());
            q->ptr.tp = NULL;
        }
    }

}
int main()
{
    string s,s1;
    GList L;
    cin>>s;
    s1 =s;
    createGlist(L,s);
    printf("generic list: ");
    cout<<s<<endl;
    int x;
    
    while((scanf("%d",&x))!=EOF)
    {
        if(s[s.length()-1]==')'&&s[0]=='(')
        s = s.substr(1,s.size()-2);
        if(x==1)//取表头
        {
            string sub;
            server(s,sub);
            cout<<"destroy tail"<<endl<<"free list node"<<endl<<"generic list: "<<sub<<endl;
            s = sub;
        }
        if(x==2)//取表尾
        {
            string sub;
            server(s,sub);
            s.push_back(')');
            s.insert(0,"(");
            cout<<"free head node"<<endl<<"free list node"<<endl<<"generic list: ";
            cout<<s<<endl;
        }
    }

    return 0;
}
