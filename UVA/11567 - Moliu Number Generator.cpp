#include<cstdio>
#include<algorithm>

using namespace std;

long long calcmin(long long x){
    if(x==0)
        return 0;
    if(x==1)
        return 1;
    if(x%2==0)
        return (1+calcmin(x/2));
        return (1+min(calcmin(x+1),calcmin(x-1)));
}

int main(){
    long long s;
    while(scanf("%lld",&s)!=EOF){
        printf("%lld\n",calcmin(s));
    }
    return 0;
}
