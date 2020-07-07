#include<bits/stdc++.h>

using namespace std;

long long memo[1000005];

long long lcm(long a,long b){
    return (long long)a*b/__gcd(a,b);
}

long long solve(int n){
    long long &ret=memo[n];
    if(ret!=-1)
        return ret;
    ret=1;
    int x=n;
    for(int i=2;i*i<=x;i++){
        int temp=1;
        while(x%i==0){
            temp*=i;
            x/=i;
        }
        if(temp>1)
            ret=lcm(ret,solve(temp));
    }
    if(x==n)
        ret=n-1;
    else if(x>1)
        ret=lcm(ret,solve(x));
    return ret;
}

int main(){
    memset(memo,-1,sizeof memo);
    memo[1]=1;
    memo[2]=3;
    memo[3]=8;
    memo[4]=6;
    memo[5]=20;
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        int n;
        scanf("%*d%d",&n);
        printf("%d %lld\n",t,solve(n));
    }
    return 0;
}
