#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#include<set>
#include<vector>

using namespace std;

set < int > badPrimes;
bool isPrime[100005];
map< int,vector < int > > factors;

int beauty(int x){
    if(x==1)
        return 0;
    int p=factors[x][0];
    if(badPrimes.count(p))
        return beauty(x/p)+1;
    return beauty(x/p)-1;
}

int main(){
    int n,m,arr[5005],maxi=0,temp;
    memset(isPrime,1,sizeof isPrime);
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
        maxi=max(maxi,arr[i]);
    }
    for(int i=0;i<m;i++){
        scanf("%d",&temp);
        badPrimes.insert(temp);
    }
    for(int i=2;i*i<=maxi;i++){
        if(isPrime[i]){
            for(int j=i;j<=maxi;j+=i){
                isPrime[j]=0;
                factors[j].push_back(i);
            }
        }
    }
    return 0;
}
