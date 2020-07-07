#include<stdio.h>

main()
{
    int al,ar,bl,br,flag=1;
    scanf("%d %d %d %d",&al,&ar,&bl,&br);
    if(al>br && al-br<2)
    {
        flag=0;
    }
    else if(br>=al && (br-2)/al<=2)
    {
        flag=0;
    }
    if(ar>bl && ar-bl<2)
    {
        flag=0;
    }
    else if(bl>=ar && (bl-2)/ar<=2)
    {
        flag=0;
    }
    if(flag==0)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
    return 0;
}
