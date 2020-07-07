#include<cstdio>
#include<algorithm>

using namespace std;

int main(){
    int T,t,n,m,coins[20000],i,p,maxi,mini;
    scanf("%d",&T);

    for(t=1;t<=T;t++){
        scanf("%d%d",&n,&m);
        for(i=0;i<m;i++)
            scanf("%d",&coins[i]);

        sort(coins,coins+m);

        p=coins[0],maxi=0,mini=0;
        for(i=0;i<m;i++){
            maxi=max(maxi,coins[i]-p);
            mini=min(mini,coins[i]-p);
            p+=n/m;
        }

        printf("Case #%d: %d\n",t,(maxi-mini+1)/2);
    }
    return 0;
}
