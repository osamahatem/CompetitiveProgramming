#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

#define mod 1000000007

long long powlog(long long n,long long p){
    if(!p)
        return 1;
    long long ret=powlog(n,p/2);
    ret*=ret;
    ret%=mod;
    if(p%2)
        ret*=n;
    return ret%mod;
}

int main(){
    long long ans=0,temp,i,j,arr[100005],n,smaller[100005],last=0;
    vector<int> factors[100005];
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    sort(arr,arr+n);
    for(i=1;i<=arr[n-1];i++)
        for(j=i;j<=arr[n-1];j+=i)
            factors[j].push_back(i);
    memset(smaller,0,sizeof smaller);
    j=0;
    for(i=1;i<=100001;i++){
        while(j<n && arr[j]<i){
            smaller[i]++;
            j++;
        }
        smaller[i]+=smaller[i-1];
    }
    for(i=1;i<=arr[n-1];i++){
        temp=1;
        for(j=1;j<factors[i].size();j++){
            temp*=powlog(j,smaller[factors[i][j]]-smaller[factors[i][j-1]]);
            temp%=mod;
        }
        temp*=(powlog(j,smaller[100001]-smaller[factors[i][j-1]])-powlog(j-1,smaller[100001]-smaller[factors[i][j-1]])+mod)%mod;
        temp%=mod;
        ans+=temp;
        ans%=mod;
    }
    printf("%I64d\n",ans);
    return 0;
}
