#include<bits/stdc++.h>

using namespace std;

int n,memo[1001][3][3][2],arr[3][1001];

int solve(int idx,int r,int dir,bool canAdd){
    if(idx==n || r<0 || r==3)
        return 0;
    int &ret=memo[idx][r][dir][canAdd];
    if(ret!=-1)
        return ret;
    ret=solve(idx+1,r,2,1);
    if(canAdd && idx+1<n)
        ret=max(ret,solve(idx+1,r,2,0)+arr[r][idx]*arr[r][idx+1]);
    if(dir!=0){
        ret=max(ret,solve(idx,r+1,1,1));
        if(canAdd && r+1<3)
            ret=max(ret,solve(idx,r+1,1,0)+arr[r][idx]*arr[r+1][idx]);
    }
    if(dir!=1){
        ret=max(ret,solve(idx,r-1,0,1));
        if(canAdd && r-1>=0)
            ret=max(ret,solve(idx,r-1,0,0)+arr[r][idx]*arr[r-1][idx]);
    }
    return ret;
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
	#endif

    int tc=0;
    while(scanf("%d",&n),n){
        memset(memo,-1,sizeof memo);
        for(int i=0;i<3;i++)
            for(int j=0;j<n;j++)
                scanf("%d",&arr[i][j]);
        int ans=0;
        for(int i=0;i<n;i++)
            ans=max(ans,max(solve(i,0,2,1),solve(i,2,2,1)));
        printf("Case %d: %d\n",++tc,ans);
    }
	return 0;
}
