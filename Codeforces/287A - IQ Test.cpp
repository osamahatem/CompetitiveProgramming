#include<stdio.h>

main()
{
    int i,j;
    char x[5][5],trash;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(j==3)
            {
                scanf("%c%c",&x[i][j],&trash);
            }
            else
            {
                scanf("%c",&x[i][j]);
            }
        }
    }
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(x[i][j]==x[i][j+1] && (x[i][j]==x[i+1][j] || x[i][j]==x[i+1][j+1]))
            {
                printf("YES\n");
                return 0;
            }
            else if(x[i+1][j]==x[i+1][j+1] && (x[i+1][j]==x[i][j] || x[i+1][j]==x[i][j+1]))
            {
                printf("YES\n");
                return 0;
            }
        }
    }
    printf("NO\n");
    return 0;
}
