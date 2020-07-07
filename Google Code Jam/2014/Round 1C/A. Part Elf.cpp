#include<bits/stdc++.h>

using namespace std;

int main(){
    freopen("A. Part Elf.in","r",stdin);
    freopen("A. Part Elf.out","w",stdout);
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        int p,q,ans=0,g;
        scanf("%d%*c%d",&p,&q);
        g=__gcd(p,q);
        p/=g;
        q/=g;
        while(q>=p && q%2==0){
            ans++;
            q/=2;
        }
        printf("Case #%d: ",t);

        (ans==0 || ans>40) ? (printf("Impossible\n")) : (printf("%d\n",ans));
    }
    return 0;
}
