#include<cstdio>
#include<algorithm>
#include<map>

using namespace std;

map<int,long long> memo;

long long getmax(int n){
    if(n==0)
        return 0;
    if(memo.count(n))
        return memo[n];
    return memo[n]=max((long long)n,getmax(n/2)+getmax(n/3)+getmax(n/4));
}

int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        memo.clear();
        printf("%lld\n",getmax(n));
    }
	return 0;
}
