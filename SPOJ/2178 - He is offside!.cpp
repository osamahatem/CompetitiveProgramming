#include<stdio.h>

main()
{
    int a,d,i,j,temp;
    scanf("%d %d",&a,&d);
    while(a!=0 && d!=0)
    {
        int na[a],nd[d];
        for(i=0;i<a;i++)
        {
            scanf("%d",&na[i]);
        }
        for(i=0;i<d;i++)
        {
            scanf("%d",&nd[i]);
        }
        for(i=0;i<a-1;i++)
        {
            for(j=0;j<a-1-i;j++)
            {
                if(na[j]>na[j+1])
                {
                    temp=na[j+1];
                    na[j+1]=na[j];
                    na[j]=temp;
                }
            }
        }
        for(i=0;i<d-1;i++)
        {
            for(j=0;j<d-1-i;j++)
            {
                if(nd[j]>nd[j+1])
                {
                    temp=nd[j+1];
                    nd[j+1]=nd[j];
                    nd[j]=temp;
                }
            }
        }
        if(na[0]<nd[1])
        {
            printf("Y\n");
        }
        else
        {
            printf("N\n");
        }
        scanf("%d %d",&a,&d);
    }
}
