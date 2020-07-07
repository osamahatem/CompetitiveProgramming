#include<cstdio>
#include<cstring>
#include<vector>

using namespace std;

vector<int> h,dp;

int ans(int idx){
    if(ind==h.size())
        return 0;
    int &ret=dp[idx];
    if(ret!=-1)
        return ret;
    ret=ans(idx+1);
    if()
}

int main(){
    int x,t=1;
    while(scanf("%d",&x),x!=-1){
        h.clear();
        dp.clear();
        h.push_back(x);
        dp.push_back(-1);
        while(scanf("%d",&x),x!=-1){
            h.push_back(x);
            dp.push_back(-1);
        }
        if(t>1)
            printf("\n");
        printf("Test #%d:\n  maximum possible interceptions: %d\n",t++,ans(0));
    }
	return 0;
}
