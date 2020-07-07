#include<bits/stdc++.h>

using namespace std;

int arr[24],n,dp[8400000];
vector< pair<int,int> > possible[24];

int solve(int mask){
    int last=0;
    for(int i=n-1;i>=0;i--)
        if(mask&(1<<i)){
            last=i;
            break;
        }
    if(last==n-1)
        return 1;
    int &ret=dp[mask];
    if(ret!=-1)
        return ret;
    ret=1<<20;
    last++;
    mask|=1<<last;
    bool flag=0;
    for(int i=0;i<possible[last].size();i++){
        if(mask&possible[last][i].first && mask&possible[last][i].second){
            flag=1;
            break;
        }
    }
    if(flag){
        ret=min(ret,1+solve(mask));
        for(int i=0;i<last;i++){
            if(!(mask&(1<<i)))
                continue;
            ret=min(ret,solve(mask^(1<<i)));
        }
    }
    return ret;
}

int main(){
    memset(dp,-1,sizeof dp);
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    for(int i=0;i<n;i++)
        for(int j=0;j<i;j++)
            for(int k=j;k<i;k++)
                if(arr[j]+arr[k]==arr[i])
                    possible[i].push_back(make_pair(1<<j,1<<k));
    int ret=solve(1);
    if(ret>n)
        ret=-1;
    printf("%d\n",ret);
    return 0;
}
