#include<bits/stdc++.h>

using namespace std;

long long memo[1001];

long long solve(int n){
    if(n==0)
        return 0;
    long long &ret=memo[n];
    if(ret!=-1)
        return ret;
    ret=(1ll<<62);
    for(int i=0;i<n;i++){
        long long temp=2*solve(i);
        if((n-i)>62 || (1ll<<(n-i))>LONG_LONG_MAX-temp)
            continue;
        ret=min(ret,temp+(1ll<<(n-i))-1);
    }
    return ret;
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
	#endif

    int n,t=0;
    memset(memo,-1,sizeof memo);
    while(scanf("%d",&n)!=EOF){
        printf("Case %d: %lld\n",++t,solve(n));
    }
	return 0;
}
