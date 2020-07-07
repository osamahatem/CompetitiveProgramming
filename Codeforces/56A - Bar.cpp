#include<stdio.h>
#include<string.h>
#include<math.h>

main()
{
    int n,i,j,k,c=0,age;
    char in[105];
    scanf("%d\n",&n);
    for(i=0;i<n;i++)
    {
       gets(in);
       if(in[0]<='9')
       {
           j=strlen(in)-1;
           k=0;
           age=0;
           while(j>=0)
           {
               age+=pow(10,j)*(in[k]-48);
               j--;
               k++;
           }
           if(age<18)
           {
               c++;
           }
       }
       else
       {
           if(!strcmp(in,"ABSINTH") || !strcmp(in,"BEER") || !strcmp(in,"BRANDY") || !strcmp(in,"CHAMPAGNE") || !strcmp(in,"GIN") || !strcmp(in,"RUM") || !strcmp(in,"SAKE") || !strcmp(in,"TEQUILA") || !strcmp(in,"VODKA") || !strcmp(in,"WHISKEY") || !strcmp(in,"WINE"))
           {
               c++;
           }
       }
    }
    printf("%d\n",c);
}
