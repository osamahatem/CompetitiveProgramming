#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

long long sum[10000005];
bool prime[10000005];

int main(){
    memset(prime,1,sizeof prime);
    prime[0]=prime[1]=1;
    memset(sum,0,sizeof sum);
    vector<int> primes;
    long long i,j;
    for(i=2;i<=10000000;i++){
        if(prime[i]){
            primes.push_back(i);
            for(j=i*i;j<=10000000;j+=i)
                prime[j]=0;
        }
    }

    int n,x,m,l,r,arr[1000005],c,flag;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    sort(arr,arr+n);
    for(i=0;i<n;i++){
        x=arr[i];
        c=0;
        j=i;
        while(arr[j++]==x)
            c++;
        if(prime[x]){
            sum[x]++;
            continue;
        }
        for(j=0;j<primes.size();j++){
            if(primes[j]>x)
                break;
            flag=0;
            while(x%primes[j]==0){
                x/=primes[j];
                flag=1;
            }
            sum[primes[j]]+=c*flag;
        }
        if(x>1)
            sum[x]++;
        i+=c-1;
    }
    for(i=3;i<=10000000;i++)
        sum[i]+=sum[i-1];
    scanf("%d",&m);
    for(i=0;i<m;i++){
        scanf("%d%d",&l,&r);
        r=min(r,10000000);
        l=min(l,10000000);
        printf("%I64d\n",sum[r]-sum[l-1]);
    }
    return 0;
}
