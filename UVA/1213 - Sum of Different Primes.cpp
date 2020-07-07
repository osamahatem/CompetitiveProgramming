#include<cstdio>
#include<cstring>
#include<vector>

using namespace std;

vector<int> primes;
int memo[200][15][1121];

int ans(int idx,int k,int left){
    if(left==0 && k==0)
        return 1;
    if(idx==primes.size() || left<0 || k<0)
        return 0;
    int &ret=memo[idx][k][left];
    if(ret!=-1)
        return ret;
    ret=ans(idx+1,k-1,left-primes[idx])+ans(idx+1,k,left);
    return ret;
}

int main(){
    bool prime[1121];
    memset(prime,1,sizeof prime);
    for(int i=2;i<1121;i++){
        if(prime[i]){
            primes.push_back(i);
            for(int j=i*i;j<1121;j+=i)
                prime[j]=0;
        }
    }
    memset(memo,-1,200*15*1121*4);
    int n,k;
    while(scanf("%d%d",&n,&k),n!=0)
        printf("%d\n",ans(0,k,n));
	return 0;
}
