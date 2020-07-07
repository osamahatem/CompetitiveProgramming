#include<stdio.h>

main()
{
    int p[4],a,b,i,j,temp,c=0;
    scanf("%d %d %d %d %d %d",&p[0],&p[1],&p[2],&p[3],&a,&b);
    for(i=0;i<3;i++)
    {
        for(j=0;j<3-i;j++)
        {
            if(p[j]>p[j+1])
            {
                temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
        }
    }
    if(a<p[0] && b<p[0])
    {
        c=b-a+1;
    }
    else if(a<p[0])
    {
        c=p[0]-a;
    }
    printf("%d\n",c);
}
