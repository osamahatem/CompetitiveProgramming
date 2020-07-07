#include<cstdio>

using namespace std;

bool isuni(long long x){
    bool d[10]={0,0,0,0,0,0,0,0,0,0};
    while(x>0){
        if(d[x%10]==1)
            return false;
        d[x%10]=1;
        x/=10;
    }
    return true;
}

int main(){
    int t;
    long long n;
    scanf("%d",&t);
    while(t--){
        scanf("%lld",&n);
        for(long long i=1;n*i<=9876543210;i++){
            if(isuni(i) && isuni(n*i))
                printf("%lld / %lld = %lld\n",n*i,i,n);
        }
        if(t)
            printf("\n");
    }
    return 0;
}
