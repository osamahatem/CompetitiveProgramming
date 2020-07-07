#include<bits/stdc++.h>

using namespace std;

long long a,b;
map<long long,long long> dp;

long long solve(long long x){
    long long product=x,ret=1,temp=x;
    while(temp && product<=b){
        product*=temp%10;
        temp/=10;
    }
    if(product>b)
        return 0;
    if(product<a)
        ret=0;
    for(int i=1;i<10;i++)
        ret+=solve(x*10+i);
    return ret;
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        dp.clear();
        scanf("%lld%lld",&a,&b);
        printf("%lld\n",solve(0));
    }
    return 0;
}
