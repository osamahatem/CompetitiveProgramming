#include<stdio.h>

main()
{
    int n,m,i,j,c=0;
    scanf("%d %d\n",&n,&m);
    char marks[n+1][m+1],trash;
    int best[n],maximum;
    for(i=0;i<n;i++)
    {
        best[i]=0;
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            scanf("%c",&marks[i][j]);
        }
        scanf("%c",&trash);
    }
    for(i=0;i<m;i++)
    {
        maximum=0;
        for(j=0;j<n;j++)
        {
            if(marks[j][i]>maximum)
            {
                maximum=marks[j][i];
            }
        }
        for(j=0;j<n;j++)
        {
            if(marks[j][i]==maximum)
            {
                best[j]++;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        if(best[i]>0)
        {
            c++;
        }
    }
    printf("%d\n",c);
}
