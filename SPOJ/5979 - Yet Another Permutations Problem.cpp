#include<cstdio>

#define mod 1000000007

long long powmod(long long p){
    if(p==0)
        return 1;
    if(p==1)
        return 2;
    long long r=powmod(p/2);
    r=(r*r)%mod;
    if(p%2)
        r*=2;
    return r%mod;
}

int main(){
    long long t,n;
    scanf("%lld",&t);
    while(t--){
        scanf("%lld",&n);
        printf("%lld\n",powmod(n-1));
    }
    return 0;
}
