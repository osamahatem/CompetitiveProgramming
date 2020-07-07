#include<stdio.h>

main()
{
    int n,i,l[12]={4,7,47,74,444,447,474,477,744,747,774,777};
    scanf("%d",&n);
    for(i=0;i<12;i++)
    {
        if(n%l[i]==0)
        {
            printf("YES\n");
            return 0;
        }
    }
    printf("NO\n");
    return 0;
}
