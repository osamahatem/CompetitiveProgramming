#include<cstdio>

main()
{
    int i,j;
    char x[5][5];
    for(i=0;i<3;i++)
    {
        gets(x[i]);
    }
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(x[i][j]!=x[2-i][2-j])
            {
                printf("NO\n");
                return 0;
            }
        }
    }
    printf("YES\n");
    return 0;
}
