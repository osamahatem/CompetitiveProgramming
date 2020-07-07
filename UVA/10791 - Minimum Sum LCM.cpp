#include<cstdio>
#include<cmath>
#include<algorithm>

using namespace std;

long long gcd(long long x,long long y){
    if(y==0) return x;
    return gcd(y,x%y);
}

long long minsum(long long n){
    long long x,mini=n+1;
    x=floor(sqrt(n)+0.5);
    while(x>0){
        if(n%x==0 && gcd(x,n/x)==1){
            if(x==1)
                return n;
            else{
                return (minsum(x)+minsum(n/x));
            }
        }
        x--;
    }
}

int main(){
    long long n,x,i=1,mini;
    while(1){
        scanf("%lld",&n);
        if(n==0)
            break;
        x=floor(sqrt(n)+0.5);
        mini=n+1;
        while(x>0){
            if(n%x==0 && gcd(x,n/x)==1){
                mini=minsum(x)+minsum(n/x);
                break;
            }
            x--;
        }
        printf("Case %lld: %lld\n",i,mini);
        i++;
    }
    return 0;
}
