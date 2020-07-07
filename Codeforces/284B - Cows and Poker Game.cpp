#include<stdio.h>

main()
{
    int n,i,status[3]={0,0,0};
    char c;
    scanf("%d\n",&n);
    for(i=0;i<n;i++)
    {
        scanf("%c",&c);
        if(c=='A')
        {
            status[0]++;
        }
        else if(c=='F')
        {
            status[1]++;
        }
        else
        {
            status[2]++;
        }
    }
    if(status[2]==0)
    {
        printf("%d\n",status[0]);
    }
    else if(status[2]==1)
    {
        printf("1\n");
    }
    else
    {
        printf("0\n");
    }
    return 0;
}
