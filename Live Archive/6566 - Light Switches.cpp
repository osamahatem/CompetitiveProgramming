#include<bits/stdc++.h>

using namespace std;

void factorize(long long x,vector< pair<long long,int> >& factors){
    for(long long i=2;i*i<=x;i++){
        int c=0;
        while(x%i==0){
            c++;
            x/=i;
        }
        if(c)
            factors.push_back(make_pair(i,c));
    }
    if(x>1)
        factors.push_back(make_pair(x,1));
    return;
}

int solve(int idx,vector< pair<long long,int> >& factors,long long& maxi,long long cur){
    if(cur>maxi)
        return 0;
    if(idx==factors.size())
        return 1;
    long long temp=1;
    int ret=solve(idx+1,factors,maxi,cur);
    for(int i=0;i<factors[idx].second;i++){
        temp*=factors[idx].first;
        if(temp*cur>maxi)
            break;
        ret+=solve(idx+1,factors,maxi,cur*temp);
    }
    return ret;
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
	#endif
    long long n,t,b;
    int id=0;
    while(scanf("%lld%lld%lld",&n,&t,&b)!=EOF){
        vector< pair<long long,int> > factors;
        t%=n;
        factorize(b,factors);
        printf("Case %d: %s\n",++id,solve(0,factors,t,1)%2 ? "On" : "Off");
    }
	return 0;
}
