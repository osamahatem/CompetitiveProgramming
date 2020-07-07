#include<cstdio>
#include<cstring>
#include<vector>

using namespace std;

int main(){
    int i,j;
    vector<int> primes;
    bool prime[10005];
    memset(prime,1,sizeof prime);
    for(i=2;i<10001;i++){
        if(prime[i]){
            primes.push_back(i);
            for(j=i*i;j<10001;j+=i)
                prime[j]=0;
        }
    }

    int n,m,k,fact[1250],temp_fact[1250],ans=0,x;
    memset(fact,0,sizeof fact);
    scanf("%d%d%d",&n,&m,&k);

    i=0;
    while(k>1){
        while(k%primes[i]==0){
            k/=primes[i];
            fact[i]++;
        }
        i++;
    }

    while(n--){
        memset(temp_fact,0,sizeof temp_fact);
        scanf("%d",&x);

        i=0;
        while(x>1){
            while(x%primes[i]==0){
                x/=primes[i];
                temp_fact[i]++;
            }
            i++;
        }

        for(i=0;i<primes.size();i++)
            if(temp_fact[i]*m<fact[i])
                break;

        if(i==primes.size())
            ans++;
    }

    printf("%d\n",ans);

    return 0;
}
