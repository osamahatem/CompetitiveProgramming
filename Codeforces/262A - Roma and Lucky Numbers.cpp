#include<stdio.h>
#include<string.h>

main()
{
    int n,k,i,j,c1=0,c2=0;
    char c;
    scanf("%d %d\n",&n,&k);
    for(i=0;i<n;i++)
    {
        c1=0;
        while(1)
        {
            scanf("%c",&c);
            if(c==' ' || c=='\n')
            {
                break;
            }
            else if(c=='4' || c=='7')
            {
                c1++;
            }
        }
        if(c1<=k)
        {
            c2++;
        }
    }
    printf("%d\n",c2);
}
