#include<cstdio>
#include<cstring>

main()
{
    int t,sx,sy,ex,ey,l,i;
    scanf("%d%d%d%d%d\n",&t,&sx,&sy,&ex,&ey);
    char w[t+5];
    gets(w);
    i=0;
    while(sx!=ex || sy!=ey)
    {
        if(i==t)
        {
            break;
        }
        if(ex>sx && w[i]=='E')
        {
            sx++;
            l=i+1;
        }
        else if(ex<sx && w[i]=='W')
        {
            sx--;
            l=i+1;
        }
        if(ey>sy && w[i]=='N')
        {
            sy++;
            l=i+1;
        }
        else if(ey<sy && w[i]=='S')
        {
            sy--;
            l=i+1;
        }
        i++;
    }
    if(sx==ex && sy==ey)
    {
        printf("%d\n",l);
    }
    else
    {
        printf("-1\n");
    }
    return 0;
}
