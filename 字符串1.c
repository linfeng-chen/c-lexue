#include "stdio.h"
#include "string.h"
#include <ctype.h>

#define N 1000
int main()
{   
    int i,j;
    char words[N][N]={0};
    char temp[100000]={0};
    while(1)
    {
        gets(temp);
        if(strlen(temp)==0)break;
        temp[0]=toupper(temp[0]);
        for(int k=1;k<strlen(temp);k++)
        {
            if(temp[k-2]=='.'||temp[k-2]=='?'||temp[k-2]=='!')
            temp[k]=toupper(temp[k]);
            else if('A'<=temp[k]&&temp[k]<='Z')
            temp[k]=tolower(temp[k]);
        }
        printf("%s\n",temp);
        memset(temp,0,sizeof(temp));
    }

  
    return 0;
}

