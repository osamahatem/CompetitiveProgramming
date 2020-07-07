#include<bits/stdc++.h>

using namespace std;

void solve(int n,long long moves,char from,char to,char spare){
    long long before=(1ll<<(n-1))-1;
    if(moves<=before){
        solve(n-1,moves,from,spare,to);
        return;
    }
    moves-=before;
    if(moves==1){
        printf("%d %c %c\n",n,from,to);
        return;
    }
    moves--;
    solve(n-1,moves,spare,to,from);
    return;
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
	#endif

    int n,id=0;
    long long k;
    while(scanf("%lld%d",&k,&n),n){
        printf("Case %d: ",++id);
        solve(n,k,'A','C','B');
    }
	return 0;
}
