#include "stdio.h" 
#include "string.h" 
# define N 1000000 
char number[N]={0}; 
char a='0'; 
 



int print(long l) 
{ 
    long temp = strlen(number)/l; 
    while(temp--) 
    { 
        if(a=='1')printf("%c",a); 
        for(long k=0;k<l;k++) 
        printf("%c",number[k]); 
    } 
    printf("\n"); 
} 
 
int compare(long l,long rate) 
{ 
    long i; 
    for(i=0;i<l;i++) 
    { 
        if(number[i]>number[i+rate*l]) 
        { 
           // printf("33\n"); 
            print(l); 
            break; 
        } 
        if(number[i]<number[i+rate*l]) 
        { 
            //number[l-1]=number[l-1]+1; 
           // printf("**\n"); 
            carry(l); 
            print(l); 
            break; 
        } 
    } 
    if(i==l) 
        compare(l,rate+1); 
 
} 
 
int carry(l) 
{ 
    a='1'; 
    char temp; 
    for(long i=l-1;i>=0;i--) 
    { 
        temp = a; 
        //printf("%c^\n",temp); 
        a = (number[i]-'0'+temp-'0')/10+48; 
        number[i] = (number[i]-'0'+temp-'0')%10+48; 
         
        //printf("%c %c^\n",a,number[i]); 
    } 
  /*  for(long k=0;k<l;k++) 
        printf("%c",number[k]); 
    printf("\n");*/ 
} 
int main() 
{ 
    long l,i=1,count; 
    scanf("%ld",&l); 
    scanf("%s",&number); 
    if(strlen(number)%l==0) 
    { 
        compare(l,1); 
    } 
    else 
    { 
        count = strlen(number)/l+1; 
        //printf("%ld\n",count); 
        for(i=1;i<=count;i++) 
        {    
             for(long j=1;j<=l;j++) 
            { 
                if(j%l==1)printf("1"); 
                else printf("0"); 
            } 
        } 
        printf("\n"); 
    } 
 
    return 0; 
} 