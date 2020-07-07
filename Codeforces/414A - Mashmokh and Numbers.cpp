#include<bits/stdc++.h>

using namespace std;

int main(){
    long long n,k;
    scanf("%I64d%I64d",&n,&k);
    if(n==1 && k==0){
        printf("1\n");
        return 0;
    }
    if(k<n/2 || (k>0 && n==1)){
        printf("-1\n");
        return 0;
    }
    long long ans[100005],base=k/(n/2)+1;
    for(long long i=0;i<n;i++){
        ans[i]=base*(i+1);
    }
    long long dif=base*(n/2)-k;
    for(long long i=0;i<dif;i++){
        ans[i*2]/=base;
        ans[i*2]*=base-1;
        ans[i*2+1]/=base;
        ans[i*2+1]*=base-1;
    }
    for(long long i=0;i<n;i++){
        if(i>0)
            printf(" ");
        printf("%I64d",ans[i]);
    }
    printf("\n");
    return 0;
}
