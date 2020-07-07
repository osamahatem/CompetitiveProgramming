#include<bits/stdc++.h>

using namespace std;

bool isPrime[100005];
vector<int> primes;

struct num{int val,pos;};

bool cmp(const num &a,const num &b){
    return a.val<b.val;
}

void getPrimes(int n){
    memset(isPrime,1,sizeof isPrime);
    for(long long i=2;i<n;i++){
        if(isPrime[i]){
            primes.push_back(i);
            for(long long j=i*i;j<n;j+=i)
                isPrime[j]=0;
        }
    }
    return;
}

int main(){
    int n,unsorted[100005];
    num arr[100005];
    scanf("%d",&n);
    getPrimes(n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i].val);
        arr[i].pos=i;
        unsorted[i]=arr[i].val;
    }
    sort(arr,arr+n,cmp);
    vector< pair<int,int> > ans;
    for(int i=0;i<n;i++){
        int d=arr[i].pos-i,x;
        while(d){
            x=upper_bound(primes.begin(),primes.end(),d+1)-primes.begin();
            x--;
            d-=primes[x]-1;
            ans.push_back(make_pair(arr[i].pos,arr[i].pos-primes[x]+1));
        }
    }
    return 0;
}
