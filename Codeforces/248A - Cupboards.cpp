#include<cstdio>
#include<algorithm>

using namespace std;

main()
{
    int n,i,l,r,cl=0,cr=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d%d",&l,&r);
        if(l==1)
        {
            cl++;
        }
        if(r==1)
        {
            cr++;
        }
    }
    n=min(cl,n-cl)+min(cr,n-cr);
    printf("%d\n",n);
    return 0;
}
