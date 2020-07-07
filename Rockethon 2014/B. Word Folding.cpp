#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
    vector<int> letters[26];
    char in[1005];
    scanf("%s",in);
    int len=strlen(in),i,j,a,ans=1,dp[1005];
    for(i=0;i<len;i++)
        letters[in[i]-'A'].push_back(i);
    for(a=0;a<26;a++){
        dp[0]=1;
        for(i=(int)letters[a].size()-1;i>=0;i--){
            dp[i]=1;
            for(j=i;j<letters[a].size();j++){
                if((letters[a][j]-letters[a][i])%2==1)
                    dp[i]=max(dp[i],1+dp[j]);
            }
        }
        ans=max(ans,dp[0]);
    }
    printf("%d\n",ans);
    return 0;
}
