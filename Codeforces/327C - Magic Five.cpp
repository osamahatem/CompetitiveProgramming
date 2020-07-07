#include<bits/stdc++.h>

using namespace std;

#define MOD 1000000007

long long fastPower(long long b,int p){
    long long ans=1;
    for(;p;p>>=1){
        if(p&1)
            ans=ans*b%MOD;
        b=b*b%MOD;
    }
    return ans;
}

int main(){
    int k;
    long long ans=0;
    char in[100005];
    scanf("%s%d",in,&k);
    int len=strlen(in);
    for(int i=0;i<len;i++)
        if(in[i]=='5' || in[i]=='0')
            ans=(ans+fastPower(2,i))%MOD;
    ans=ans*(fastPower(fastPower(2,len),k)-1+MOD)%MOD;
    ans=ans*fastPower(fastPower(2,len)-1,MOD-2)%MOD;
    printf("%I64d\n",ans);
    return 0;
}
