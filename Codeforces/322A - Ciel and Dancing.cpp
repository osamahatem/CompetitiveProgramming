#include<cstdio>

int main(){
    int n,m,i;
    scanf("%d%d",&n,&m);
    printf("%d\n",m+n-1);
    for(i=1;i<=m;i++)
        printf("%d %d\n",1,i);
    for(i=2;i<=n;i++)
        printf("%d %d\n",i,m);
    return 0;
}
