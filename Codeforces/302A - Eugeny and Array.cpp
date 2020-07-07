#include<cstdio>
#include<cstdlib>

main()
{
    int n,m,i,x,l,r,cn=0,cp=0;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)
    {
        scanf("%d",&x);
        if(x==1)
        {
            cp++;
        }
        else
        {
            cn++;
        }
    }
    for(i=0;i<m;i++)
    {
        scanf("%d%d",&l,&r);
        if((abs(l-r)-1)%2!=0)
        {
            printf("0\n");
        }
        else if(cp>=(abs(l-r)+1)/2 && cn>=(abs(l-r)+1)/2)
        {
            printf("1\n");
        }
        else
        {
            printf("0\n");
        }
    }
    return 0;
}
