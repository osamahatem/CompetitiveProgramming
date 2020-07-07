#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

vector<int> factors[100005];
bool prime[100005];
int n,arr[100005];

void get_primes(){
    for(int i=2;i<=arr[n-1];i++){
        if(prime[i]){
            for(int j=i;j<=arr[n-1];j+=i){
                prime[i]=0;
                factors[j].push_back(i);
            }
        }
    }
    return;
}

int main(){
    int i,j,dp[100005],ans=1,temp;
    memset(prime,1,sizeof prime);
    memset(dp,0,sizeof dp);
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    get_primes();
    for(i=0;i<n;i++){
        temp=0;
        for(j=0;j<factors[arr[i]].size();j++)
            temp=max(temp,dp[factors[arr[i]][j]]+1);
        ans=max(temp,ans);
        for(j=0;j<factors[arr[i]].size();j++)
            dp[factors[arr[i]][j]]=max(temp,dp[factors[arr[i]][j]]);
    }
    printf("%d\n",ans);
    return 0;
}
