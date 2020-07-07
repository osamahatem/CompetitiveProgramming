#include<cstdio>
#include<algorithm>

using namespace std;

int elem[2000000];
long long sums[2000000];

bool cmp(int a,int b){
    return a>b;
}

int main(){
    int n,i;
    long long sum=0;
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d",&elem[i]);
    sort(elem,elem+n,cmp);
    for(i=0;i<n;i++){
        sum+=elem[i];
        sums[i]=sum;
    }
    sum=0;
    for(i=1;i<=n;i*=4) sum+=sums[i-1];
    printf("%I64d\n",sum);
    return 0;
}
