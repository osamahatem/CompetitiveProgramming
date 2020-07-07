#include<cstdio>
#include<cmath>

main()
{
    int x,y,i,j;
    while(scanf("%d",&x)!=EOF)
    {
        y=1;
        for(i=0;i<x/2;i++)
        {
            y*=10;
        }
        for(i=0;i<y;i++)
        {
            for(j=0;j<y;j++)
            {
                if((i+j)*(i+j)==(i*y+j))
                {
                    if(x==2)
                    {
                        printf("%02d\n",i*y+j);
                    }
                    else if(x==4)
                    {
                        printf("%04d\n",i*y+j);
                    }
                    else if(x==6)
                    {
                        printf("%06d\n",i*y+j);
                    }
                    else if(x==8)
                    {
                        printf("%08d\n",i*y+j);
                    }
                }
            }
        }
    }
    return 0;
}
