#include<stdio.h>

main()
{
    char c;
    int i;
    for(i=0;i<100;i++)
    {
        scanf("%c",&c);
        if(c=='\n')
        {
            break;
        }
        else if(c<97)
        {
            c+=32;
        }
        if(c=='a' || c=='o' || c=='e' || c=='i' || c=='u' || c=='y')
        {
            continue;
        }
        else
        {
            printf(".%c",c);
        }
    }
    printf("\n");
}
