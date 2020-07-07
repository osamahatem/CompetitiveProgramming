#include<stdio.h>

main()
{
    int n,a,b,capacity=0,passengers=0;
    scanf("%d",&n);
    for(n;n>=1;n--)
    {
        scanf("%d %d",&a,&b);
        passengers=passengers-a+b;
        if(passengers>capacity)
        {
            capacity=passengers;
        }
    }
    printf("%d\n",capacity);
}
