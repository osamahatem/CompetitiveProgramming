#include<stdio.h>

main()
{
    int n,k,l,c,d,p,nl,np,mini;
    scanf("%d%d%d%d%d%d%d%d",&n,&k,&l,&c,&d,&p,&nl,&np);
    mini=k*l/nl;
    if(c*d<mini)
    {
        mini=c*d;
    }
    if(p/np<mini)
    {
        mini=p/np;
    }
    printf("%d\n",mini/n);
}
