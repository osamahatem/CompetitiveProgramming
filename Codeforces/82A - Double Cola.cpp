#include<stdio.h>
#include<math.h>

main()
{
    long n;
    int x;
    scanf("%ld",&n);
    x=n/5;
    printf("%d\n",x);
    x=log(x)/log(2);
    printf("%d\n",x);
    x=n-x;
    printf("%d\n",x);
    switch(x)
    {
        case 1:
            printf("Sheldon\n");
            break;
        case 2:
            printf("Leonard\n");
            break;
        case 3:
            printf("Penny\n");
            break;
        case 4:
            printf("Rajesh\n");
            break;
        case 5:
            printf("Howard\n");
            break;
    }
    return 0;
}
