#include "stdio.h"
#include "string.h"
char *week[]={"monday","tuesday","wednesday","thursday","friday","saturday","sunday"};

int find(char s[])
{
    char *p;
    int i,j;
    for (i = 0; i < 7; i++)
    {
        if(strcmp(week[i],s)==0)
         return i+1;
    
    }
    return(-1);
}
int main()
{
    char s[20]= {0};
    int x;
    scanf("%s",&s);
    puts(s);
    x = find(s);
    printf("%d",x);
    return 0;
}