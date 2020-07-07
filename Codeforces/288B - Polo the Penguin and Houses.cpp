#include<bits/stdc++.h>

using namespace std;

const long long MOD=1e9+7;

long long fastPower(long long base,int p){
    long long ans=1;
    for(;p;p>>=1){
        if(p&1)
            ans=ans*base%MOD;
        base=base*base%MOD;
    }
    return ans;
}

int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    printf("%I64d\n",fastPower(n-k,n-k)*fastPower(k,k-1)%MOD);
    return 0;
}
