#include<cstdio>
#include<algorithm>

using namespace std;

long long len(long long a){
    int ret=0;
    while(a>0){
        ret++;
        a/=10;
    }
    return ret;
}

int main(){
    long long w,m,k,K,temp,p,ret=0;
    scanf("%I64d%I64d%I64d",&w,&m,&k);
    K=k;
    while(w>=K){
        temp=len(m);
        K=k*temp;
        p=1;
        while(temp--)
            p*=10;
        if(w/K<(p-m)){
            ret+=w/K;
            w-=w/K*K;
        }else{
            ret+=p-m;
            w-=(p-m)*K;
        }
        m=p;
    }
    printf("%I64d\n",ret);
    return 0;
}
