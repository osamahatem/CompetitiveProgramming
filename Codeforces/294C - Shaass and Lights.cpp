#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

#define mod 1000000007

long long logpow(int b,int p){
    if(p<=0)
        return 1;
    long long ans=logpow(b,p/2);
    ans*=ans;
    ans%=mod;
    if(p%2)
        ans*=b;
    ans%=mod;
    return ans;
}

long long fac(int x){
    long long ans=1;
    while(x>0){
        ans*=x;
        ans%=mod;
        x--;
    }
    return ans;
}

int main(){
    int n,m,x,i,last=0,sum=0,len;
    long long ans=1;
    vector<int> arr;
    scanf("%d%d",&n,&m);
    for(i=0;i<m;i++){
        scanf("%d",&x);
        arr.push_back(x);
    }
    sort(arr.begin(),arr.end());
    for(i=0;i<m;i++){
        x=arr[i];
        len=x-last-1;
        sum+=len;
        if(i>0)
            ans*=logpow(2,len-1);
        ans%=mod;
        ans*=logpow((int)fac(len),mod-2);
        ans%=mod;
        last=x;
    }
    len=n-last;
    sum+=len;
    ans*=logpow((int)fac(len),mod-2);
    ans%=mod;
    ans*=fac(sum);
    ans%=mod;
    printf("%I64d\n",ans);
    return 0;
}
