#include<cstdio>
#include<algorithm>

using namespace std;

main()
{
    int n,i,last,c=0;
    bool flag=0;
    scanf("%d",&n);
    int id[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&id[i]);
    }
    sort(id,id+n);
    for(i=1;i<n;i++)
    {
        last=id[i-1];
        if(id[i]==last && !flag && last!=0)
        {
            flag=1;
            c++;
        }
        else if(id[i]==last && flag && last!=0)
        {
            printf("-1\n");
            return 0;
        }
        else
        {
            flag=0;
        }
    }
    printf("%d\n",c);
    return 0;
}
