#include<stdio.h>

main()
{
    int n,t,i;
    scanf("%d %d\n",&n,&t);
    char c[n+1],temp;
    gets(c);
    for(t;t>0;t--)
    {
        for(i=0;i<n-1;i++)
        {
            if(c[i]=='B')
            {
                if(c[i+1]=='G')
                {
                    temp=c[i];
                    c[i]=c[i+1];
                    c[i+1]=temp;
                    i++;
                }
            }
        }
    }
    for(i=0;i<n;i++)
    {
        printf("%c",c[i]);
    }
    printf("\n");
}
