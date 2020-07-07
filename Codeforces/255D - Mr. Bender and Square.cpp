#include<cstdio>
#include<algorithm>

using namespace std;

long long trim(long long x,long long y,long long n,long long t){
    long long ans=0,d;
    if(t>=x){
        d=t-x+1;
        ans+=d*(d+1)/2+d*(d-1)/2;
    }
    if(t>=y){
        d=t-y+1;
        ans+=d*(d+1)/2+d*(d-1)/2;
    }
    if(x+t>n){
        d=x+t-n;
        ans+=d*(d+1)/2+d*(d-1)/2;
    }
    if(y+t>n){
        d=y+t-n;
        ans+=d*(d+1)/2+d*(d-1)/2;
    }
    if(t>=x+y){
        d=t-x-y+1;
        ans-=d*(d+1)/2;
    }
    if(t>=y+n-x+1){
        d=t-y-n+x;
        ans-=d*(d+1)/2;
    }
    if(t>=x+n-y+1){
        d=t-x-n+y;
        ans-=d*(d+1)/2;
    }
    if(t>=2*n-x-y+2){
        d=t-2*n+x+y-1;
        ans-=d*(d+1)/2;
    }
    return ans;
}

int main(){
    long long n,x,y,ans,lo,hi,mid,c,temp;
    scanf("%I64d%I64d%I64d%I64d",&n,&x,&y,&c);
    lo=0,hi=2*n;
    while(lo<=hi){
        mid=(lo+hi)/2;
        temp=1;
        temp+=2*mid*(mid+1);
        temp-=trim(x,y,n,mid);
        if(temp>=c){
            hi=mid-1;
            ans=mid;
        }else
            lo=mid+1;
    }
    printf("%I64d\n",ans);
    return 0;
}
