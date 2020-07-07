#include<cstdio>

int main(){
    int n,o,ans;
    scanf("%d%d",&n,&o);
    ans=o+o/(n-1);
    if((ans%n==0))
        printf("%d %d\n",ans-1,ans);
    else
        printf("%d %d\n",ans,ans);
    return 0;
}
