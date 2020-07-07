#include<cstdio>
#include<cstring>
#include<vector>

using namespace std;

int main(){
    vector<int> primes;
    bool prime[100001];
    long long i,j;
    memset(prime,1,sizeof prime);
    prime[0]=prime[1]=0;
    for(i=2;i<=100000;i++){
        if(prime[i]){
            for(j=i*i;j<=100000;j+=i)
                prime[j]=0;
            primes.push_back(i);
        }
    }
    int t;
    scanf("%d",&t);
    while(t--){
        int a,b;
        bool flag;
        scanf("%d%d",&a,&b);
        for(i=a;i<=b;i++){
            flag=1;
            if(i==1)
                flag=0;
            for(j=0;j<primes.size() && (long long)primes[j]*(long long)primes[j]<=i;j++){
                if(i%primes[j]==0){
                    flag=0;
                    break;
                }
            }
            if(flag)
                printf("%d\n",i);
        }
        if(t>0)
            printf("\n");
    }
    return 0;
}
