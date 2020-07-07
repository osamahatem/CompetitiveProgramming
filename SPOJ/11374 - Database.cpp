#include<cstdio>
#include<map>
#include<set>

using namespace std;

main()
{
    int t,j;
    scanf("%d",&t);
    for(j=1;j<=t;j++)
    {
        int n,r,i,c;
        bool flag=0;
        map<int,set<int> > db;
        scanf("%d%d",&n,&r);
        while(r--)
        {
            scanf("%d%d",&i,&c);
            if(db[i].count(c))
            {
                flag=1;
            }
            else
            {
                db[i].insert(c);
            }
        }
        if(flag)
        {
            printf("Scenario #%d: impossible\n",j);
        }
        else
        {
            printf("Scenario #%d: possible\n",j);
        }
        if(j!=t)
        {
            printf("\n");
        }
    }
    return 0;
}
