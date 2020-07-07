#include<stdio.h>

main()
{
    int x1=0,y1=0,x,y,c=0,s=1;
    scanf("%d %d",&x,&y);
    while(x1!=x && y1!=y)
    {
        if(c%2==0)
        {
            if(s%2!=0)
            {
                x+=s;
            }
            else
            {
                x-=s;
            }
        }
        else
        {
            if(s%2!=0)
            {
                y+=s;
            }
            else
            {
                y-=s;
            }
        }
        s++;
        c++;
    }
    printf("%d\n",c);
}
