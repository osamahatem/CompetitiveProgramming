#include<cstdio>

#define mod 1000000009

long long po2(int x){
    if(x==0) return 1;
    if(x==1) return 2;
    long long ans=po2(x/2);
    ans%=mod;
    ans*=ans;
    ans%=mod;
    if(x%2)
        ans*=2;
    ans%=mod;
    return ans;
}

int main(){
    long long n,m,k;
    scanf("%I64d%I64d%I64d",&n,&m,&k);
    long long maxi=n/k*(k-1)+n%k,rep=m-maxi,ans;
    if(rep<0)
        rep=0;
    ans=po2(rep)-1;
    ans*=k*2;
    ans%=mod;
    long long rest=m-rep*k;
    if(rest<0)
        rest=0;
    ans+=rest;
    ans%=mod;
    printf("%I64d\n",ans);
	return 0;
}
