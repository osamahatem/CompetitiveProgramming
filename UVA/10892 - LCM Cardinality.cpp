#include<bits/stdc++.h>

using namespace std;

vector< pair<int,int> > primeFactors;
vector<int> factors;

void getFactors(int idx,int cur){
    if(idx==primeFactors.size()){
        factors.push_back(cur);
        return;
    }
    getFactors(idx+1,cur);
    int temp=cur;
    for(int i=0;i<primeFactors[idx].second;i++){
        temp*=primeFactors[idx].first;
        getFactors(idx+1,temp);
    }
    return;
}

long long lcm(long long a,long long b){
    return a*b/__gcd(a,b);
}

int main(){
    int n;
    while(scanf("%d",&n),n){
        primeFactors.clear();
        factors.clear();
        int x=n,ans=0;
        for(long long i=2;i*i<=x;i++){
            int c=0;
            while(x%i==0){
                c++;
                x/=i;
            }
            if(c)
                primeFactors.push_back(make_pair(i,c));
        }
        if(x>1)
            primeFactors.push_back(make_pair(x,1));
        getFactors(0,1);
        for(int i=0;i<factors.size();i++)
            for(int j=i;j<factors.size();j++)
                if(lcm(factors[i],factors[j])==n)
                    ans++;
        printf("%d %d\n",n,ans);
    }
    return 0;
}
