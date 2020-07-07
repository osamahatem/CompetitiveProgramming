#include<bits/stdc++.h>

using namespace std;

int main(){
    long long l,r,ans=0;
    bool smaller=0;
    scanf("%I64d%I64d",&l,&r);
    for(int i=60;i>=0;i--){
        bool a=l&(1ll<<i),b=r&(1ll<<i);
        if(a!=b || smaller)
            ans+=1ll<<i;
        smaller=(smaller || (a!=b));
    }
    printf("%I64d\n",ans);
    return 0;
}
