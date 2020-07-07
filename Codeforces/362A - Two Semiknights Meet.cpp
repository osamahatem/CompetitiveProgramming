#include<stdio.h>
#include<string.h>

using namespace std;

int x[]={-2,-2,2,2},y[]={-2,2,-2,2},flag=0,vis[10][10][10][10];
char grid[10][10];

bool valid(int r1,int r2,int c1,int c2)
{
    if(r1<0 || r2<0 || c1<0 || c2<0)
        return 0;
    if(r1>=8 || c1>=8 || c2>=8 || r2>=8)
        return 0;
    return 1;
}
void check(int r1,int c1,int r2,int c2)
{

    //printf("%d %d %d %d\n",r1,c1,r2,c2);
    if(vis[r1][r2][c1][c2])
        return ;
     if(r1==r2 && c1==c2)
        {
           if(grid[r1][c1]!='#')
            flag++;
            return ;
        }
    vis[r1][r2][c1][c2]=1;
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            if(valid(r1+x[i],c1+y[i],r2+x[j],c2+y[j]))
               check(r1+x[i],c1+y[i],r2+x[j],c2+y[j]);
        return ;
}

int main()
{
    int n,r,c,i,j,r2,c2,k,m;
    scanf("%d",&n);
    while(n--)
    {
        flag=0;
        for(i=0;i<8;i++)
            scanf("%s",grid[i]);

        for(i=0;i<8;i++)
            for(j=0;j<8;j++)
                {
                    if(grid[i][j]=='K' && !flag)
                        {r=i,c=j,flag=1;}
                    else if(grid[i][j]=='K')
                        r2=i,c2=j;
                }
        //printf("%d %d %d %d\n",r,c,r2,c2);
        for(i=0;i<8;i++)
            for(j=0;j<8;j++)
                for(k=0;k<8;k++)
                    for(m=0;m<8;m++)
                    vis[i][j][k][m]=0;
        flag=0;
        check(r,c,r2,c2);
        if(flag)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
