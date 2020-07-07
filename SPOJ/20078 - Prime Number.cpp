#include<bits/stdc++.h>

using namespace std;

int main(){
    vector<int> primes;
    primes.push_back(2);
    int k,n=3;
    bool flag=1;
    scanf("%d",&k);
    while(primes.size()<k){
        flag=1;
        for(int i=0;i<primes.size() && primes[i]*primes[i]<=n;i++){
            if(n%primes[i]==0){
                flag=0;
                break;
            }
        }
        if(flag)
            primes.push_back(n);
        n++;
    }
    printf("%d\n",primes[k-1]);
    return 0;
}
