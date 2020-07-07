#include<stdio.h>

main()
{
    double k,l;
    int i=0;
    scanf("%lf\n%lf",&k,&l);
    while(1)
    {
        if(l==k)
        {
            printf("YES\n%d\n",i);
            return 0;
        }
        else if(l<k)
        {
            printf("NO\n");
            return 0;
        }
        else
        {
            l=l/k;
            i++;
        }
    }
}
