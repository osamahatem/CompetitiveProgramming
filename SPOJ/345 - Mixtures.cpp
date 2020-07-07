#include<bits/stdc++.h>

using namespace std;

int arr[101],cum[101],memo[101][101];

int solve(int s,int e){
    if(s==e)
        return 0;
    int &ret=memo[s][e];
    if(ret!=-1)
        return ret;
    ret=1<<30;
    for(int i=s;i<e;i++){
        int temp=solve(s,i)+solve(i+1,e);
        temp+=((cum[i]-cum[s-1])%100)*((cum[e]-cum[i])%100);
        ret=min(ret,temp);
    }
    return ret;
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
	#endif

    int n;
    while(scanf("%d",&n)!=EOF){
        for(int i=1;i<=n;i++){
            scanf("%d",&arr[i]);
            cum[i]=cum[i-1]+arr[i];
        }
        memset(memo,-1,sizeof memo);
        printf("%d\n",solve(1,n));
    }
	return 0;
}
