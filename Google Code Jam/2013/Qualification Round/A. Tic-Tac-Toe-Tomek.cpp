#include<cstdio>

using namespace std;

main()
{
    freopen("A. Tic-Tac-Toe-Tomek.in","r",stdin);
    freopen("A. Tic-Tac-Toe-Tomek.out","w",stdout);
    int t,i,j,c,cx,co,ct,cb,flag;
    char x[4][5];
    scanf("%d\n",&t);
    for(c=1;c<=t;c++)
    {
        flag=0;
        cb=0;
        for(i=0;i<4;i++)
        {
            gets(x[i]);
        }
        for(i=0;i<4;i++)
        {
            cx=0;
            co=0;
            ct=0;
            for(j=0;j<4;j++)
            {
                if(x[i][j]=='X')
                {
                    cx++;
                }
                else if(x[i][j]=='O')
                {
                    co++;
                }
                else if(x[i][j]=='T')
                {
                    ct++;
                }
                else if(x[i][j]=='.')
                {
                    cb++;
                }
            }
            if(cx+ct==4)
            {
                printf("Case #%d: X won",c);
                flag=1;
            }
            else if(co+ct==4)
            {
                printf("Case #%d: O won",c);
                flag=1;
            }
        }
        for(i=0;i<4;i++)
        {
            cx=0;
            co=0;
            ct=0;
            for(j=0;j<4;j++)
            {
                if(x[j][i]=='X')
                {
                    cx++;
                }
                else if(x[j][i]=='O')
                {
                    co++;
                }
                else if(x[j][i]=='T')
                {
                    ct++;
                }
                else if(x[j][i]=='.')
                {
                    cb++;
                }
            }
            if(cx+ct==4 && !flag)
            {
                printf("Case #%d: X won",c);
                flag=1;
            }
            else if(co+ct==4 && !flag)
            {
                printf("Case #%d: O won",c);
                flag=1;
            }
        }
        cx=0;
        co=0;
        ct=0;
        for(i=0;i<4;i++)
        {
            if(x[i][i]=='X')
            {
                cx++;
            }
            else if(x[i][i]=='O')
            {
                co++;
            }
            else if(x[i][i]=='T')
            {
                ct++;
            }
            else if(x[i][i]=='.')
            {
                cb++;
            }
        }
        if(cx+ct==4 && !flag)
        {
            printf("Case #%d: X won",c);
            flag=1;
        }
        else if(co+ct==4 && !flag)
        {
            printf("Case #%d: O won",c);
            flag=1;
        }
        cx=0;
        co=0;
        ct=0;
        for(i=0;i<4;i++)
        {
            if(x[i][3-i]=='X')
            {
                cx++;
            }
            else if(x[i][3-i]=='O')
            {
                co++;
            }
            else if(x[i][3-i]=='T')
            {
                ct++;
            }
            else if(x[i][3-i]=='.')
            {
                cb++;
            }
        }
        if(cx+ct==4 && !flag)
        {
            printf("Case #%d: X won",c);
            flag=1;
        }
        else if(co+ct==4 && !flag)
        {
            printf("Case #%d: O won",c);
            flag=1;
        }
        if(cb!=0 && !flag)
        {
            printf("Case #%d: Game has not completed",c);
            flag=1;
        }
        else if(!flag)
        {
            printf("Case #%d: Draw",c);
            flag=1;
        }
        if(c!=t)
        {
            printf("\n");
        }
        scanf("\n");
    }
    return 0;
}
