#include<cstdio>

long long m;

long long powmod(long long b,long long p){
    if(p==0)
        return 1;
    if(p==1)
        return b;
    long long r;
    r=powmod(b,p/2);
    r%=m;
    r=(r*r)%m;
    if(p%2)
        r*=b;
    return r%m;
}

int main(){
    long long b,p;
    while(scanf("%lld%lld%lld",&b,&p,&m)!=EOF){
        printf("%lld\n",powmod(b,p));
    }
    return 0;
}
