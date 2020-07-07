#include<cstdio>

using namespace std;

#define mod 1000000007


long long fac(int x){
    long long ans=1;
    while(x>0){
        ans*=x;
        ans%=mod;
        x--;
    }
    return ans;
}

long long modpow(long long b,int p){
    if(p==0)
        return 1;
    if(p==1)
        return b;
    long long ans=modpow(b,p/2);
    ans%=mod;
    ans*=ans;
    ans%=mod;
    if(p%2)
        ans*=b;
    ans%=mod;
    return ans;
}

long long choose(int x,long long y){
    long long ans;
    ans=fac(y);
    ans*=fac(x-y);
    ans%=mod;
    ans=modpow(ans,mod-2);
    ans*=fac(x);
    ans%=mod;
    return ans;
}

int main(){
    int n,m;
    long long k,ans;
    scanf("%d%d%lld",&n,&m,&k);
    if(k>m || k>n)
        ans=0;
    else{
        ans=choose(n,k);
        ans*=choose(m,k);
        ans%=mod;
        ans*=fac(k);
        ans%=mod;
    }
    printf("%lld\n",ans);
	return 0;
}
