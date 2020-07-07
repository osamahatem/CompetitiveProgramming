#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

bool prime[10000001];
vector<int> primes;

int main(){
    long long i,j;
    int a,b,st,ed;
    bool flag=0;

    memset(prime,1,sizeof prime);

    for(i=2;i<=10000000;i++)
        if(prime[i]){
            primes.push_back(i);
            for(j=i*i;j<=10000000;j+=i)
                prime[j]=0;
        }

    while(scanf("%d%d",&a,&b)!=EOF){
        st=(int)(lower_bound(primes.begin(),primes.end(),a)-primes.begin());
        ed=(int)(upper_bound(primes.begin(),primes.end(),b)-primes.begin());
        if(flag)
            printf("\n");
        printf("%d\n",ed-st);
        flag=1;
    }
    return 0;
}
