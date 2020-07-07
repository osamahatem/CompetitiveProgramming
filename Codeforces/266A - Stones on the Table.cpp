#include<stdio.h>

main()
{
    int n,i,c=0;
    scanf("%d\n",&n);
    char x[n+3];
    gets(x);
    for(i=0;i<n-1;i++)
    {
        if(x[i]==x[i+1])
        {
            c++;
        }
    }
    printf("%d\n",c);
    return 0;
}
