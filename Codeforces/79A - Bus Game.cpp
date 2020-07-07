#include<stdio.h>

main()
{
    long x,y,i=1;
    scanf("%ld %ld",&x,&y);
    while(x>=0 && y>=0)
    {
        if(i%2==1)
        {
            if(x>=2 && y>=2)
            {
                x-=2;
                y-=2;
            }
            else if(x==1 && y>=12)
            {
                x-=1;
                y-=12;
            }
            else if(x==0 && y>=22)
            {
                y-=22;
            }
            else
            {
                printf("Hanako\n");
                return 0;
            }
        }
        else
        {
            if(y>=22)
            {
                y-=22;
            }
            else if(y>=12 && x>=1)
            {
                x-=1;
                y-=12;
            }
            else if(y>=2 && x>=2)
            {
                x-=2;
                y-=2;
            }
            else
            {
                printf("Ciel\n");
                return 0;
            }
        }
        i++;
    }
}
