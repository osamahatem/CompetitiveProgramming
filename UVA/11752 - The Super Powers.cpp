#include<cstdio>
#include<cmath>
#include<climits>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;

set<unsigned long long> visited;

int primes[18]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61};

bool isprime(int p){
    int i;
    for(i=0;i<18;i++)
        if(p==primes[i])
            return true;
    return false;
}

int main(){
    unsigned long long i,p,maxp,temp;
    vector<unsigned long long> super;
    super.push_back(1);
    for(i=2;i<=65536;i++){
        maxp=ceil((log(ULLONG_MAX)/log(i))-1);
        temp=i;
        for(p=2;p<=maxp;p++){
            temp*=i;
            if(isprime(p))
                continue;
            if(!visited.count(temp)){
                super.push_back(temp);
                visited.insert(temp);
            }
        }
    }
    sort(super.begin(),super.end());
    for(i=0;i<super.size();i++){
        printf("%llu\n",super[i]);
    }
    return 0;
}
