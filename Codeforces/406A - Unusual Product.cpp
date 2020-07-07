#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,q,ans=0,x;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&x);
            if(i==j)
                ans=(ans+x)%2;
        }
    }
    scanf("%d",&q);
    for(int i=0;i<q;i++){
        scanf("%d",&x);
        if(x==3)
            printf("%d",ans);
        else{
            scanf("%*d");
            ans=(++ans)%2;
        }
    }
    return 0;
}
