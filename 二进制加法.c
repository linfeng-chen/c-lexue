#include "stdio.h"
#include "string.h"
#include "math.h"
# define N 100002
int main()
{
    long T,maxlen,temp,len1,len2,temp_result,maxlen1,i;
    char string1[N]={0},string2[N]={0},result[N]={0};
    scanf("%ld",&T);
    while (T--)
    {
        memset(result,0,sizeof(result));

        scanf("%s %s",&string1,&string2);
        maxlen = strlen(string1)>strlen(string2)?strlen(string1):strlen(string2);
        maxlen1 = maxlen;
        len1 = strlen(string1)-1;len2 = strlen(string2)-1;
        temp = 0;
        while(len2>=0&&len1>=0)
        {
             temp_result = string2[len2]-48+string1[len1]-48+temp;
            // printf("%d %d %d \n",temp_result);
             if (temp_result==2||temp_result==3)
             {
                 result[maxlen] = temp_result+46;
                 temp = 1;
             }
             else
             {
                 result[maxlen] = string1[len1]-48+string2[len2]+temp;
                 temp = 0;
             }
             maxlen--,len2--,len1--;
             
        }

       /*for(i=0;i<=maxlen1;i++)
           printf("%c",result[i]);*/

   // printf("temp = %d\n",temp);


     while(len1>=0)
        {
            temp_result= string1[len1]-48+temp; 
            if(temp_result==2)
            {
                result[maxlen] = '0';
                temp = 1;
            }
            else result[maxlen] = string1[len1]+temp,temp=0;
            maxlen--,len1--;
        }
        while(len2>=0)
        {
            temp_result= string2[len2]-48+temp; 
            if(temp_result==2)
            {
                result[maxlen] = '0';
                temp = 1;
            }
            else result[maxlen] = string2[len2]+temp,temp=0;
            maxlen--,len2--;
        }





        //printf("%d,%d\n",temp,maxlen);
        if(temp==1) result[maxlen]='1';
        //输出数据
        maxlen1 = result[0]?maxlen1+3:maxlen1+2;
        //printf("%d\n",maxlen1);
        temp=maxlen1-strlen(string1);
        while(temp--)printf(" ");
        printf("%s\n",string1);
        temp = maxlen1-strlen(string2)-1;
        printf("+");
        while(temp--) printf(" ");
        printf("%s\n",string2);
        temp = maxlen1;
        while(temp--) printf("-");
        printf("\n");

        for (int i =1;i<=2;i++)
            printf(" ");
        for(int i =0;i<=maxlen1;i++)
        if (result[i])
        printf("%c",result[i]);
        printf("\n");
    }
    
    return 0;
}