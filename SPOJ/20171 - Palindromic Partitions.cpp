#include<bits/stdc++.h>

using namespace std;

long long memo[1005];

long long solve(int x){
    if(x<2)
        return 1;
    long long &ans=memo[x];
    if(ans!=-1)
        return ans;
    ans=0;
    for(int t=x;t>=0;t-=2)
        ans+=solve((x-t)/2);
    return ans;
}

int main(){
    memset(memo,-1,sizeof memo);
    int n,x;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&x);
        printf("%d %lld\n",i+1,solve(x));
    }
    return 0;
}
