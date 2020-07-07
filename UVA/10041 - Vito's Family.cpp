#include<cstdio>
#include<vector>
#include<cstdlib>
#include<algorithm>

using namespace std;

main()
{
    int t,r,s,i,sum;
    vector<int> streets;
    scanf("%d",&t);
    while(t--)
    {
        streets.clear();
        sum=0;
        scanf("%d",&r);
        for(i=0;i<r;i++)
        {
            scanf("%d",&s);
            streets.push_back(s);
        }
        sort(streets.begin(),streets.end());
        for(i=0;i<r;i++)
        {
            sum+=abs(streets[i]-streets[(r-1)/2]);
        }
        printf("%d\n",sum);
    }
    return 0;
}
