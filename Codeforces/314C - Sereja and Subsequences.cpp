#include<bits/stdc++.h>

using namespace std;

#define MOD 1000000007

long long fastPower(long long b,int p){
    long long ret=1;
    for(;p;p>>=1){
        if(p&1)
            ret=ret*b%MOD;
        b=b*b%MOD;
    }
    return ret;
}

int main(){
    int n,x;
    long long ans=1;
    map<int,int> cnt;
    scanf("%d",&n);
    while(n--){
        scanf("%d",&x);
        cnt[x]++;
    }
    for(map<int,int>::iterator i=cnt.begin();i!=cnt.end();i++)
        if(i->first==1)
            ans=i->second+1;
        else{
            ans=ans*(fastPower(i->first,i->second+1)-1+MOD)%MOD;
            ans=ans*fastPower(i->first-1,MOD-2)%MOD;
        }
    printf("%I64d\n",--ans);
    return 0;
}
