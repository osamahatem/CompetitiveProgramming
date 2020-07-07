/*
ID: 19semse1
PROG: beads
LANG: C++
*/

#include<cstdio>
#include<vector>
#include<string>

using namespace std;

main()
{
    freopen("beads.in","r",stdin);
    freopen("beads.out","w",stdout);
    int n,i,j,c=0,maxi=0;
    bool flag=0;
    char buffer[355],last;
    string beads;
    scanf("%d\n",&n);
    scanf("%s",buffer);
    beads=string(buffer);
    beads+=beads;
    for(i=0;i<n;i++)
    {
        if(beads[i]=='w')
        {
            continue;
        }
        last=beads[i];
        break;
    }
    if(i==n)
    {
        printf("%d\n",n);
        return 0;
    }
    for(i=0;i<n*2;i++)
    {
        for(j=i;j<n*2;j++)
        {
            if(beads[j]=='w')
            {
                continue;
            }
            last=beads[j];
            break;
        }
        j=i;
        c=0;
        while(j<n*2)
        {
            if(beads[j]=='w')
            {
                c++;
            }
            else if(beads[j]==last)
            {
                c++;
            }
            else if(beads[j]!=last && !flag)
            {
                last=beads[j];
                flag=1;
                c++;
            }
            else
            {
                last=beads[j];
                flag=0;
                break;
            }
            j++;
            if(maxi<c)
            {
                maxi=c;
            }
        }
    }
    if(maxi>n)
    {
        maxi=n;
    }
    printf("%d\n",maxi);
    return 0;
}
