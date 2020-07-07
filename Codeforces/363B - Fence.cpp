#include<cstdio>
#include<algorithm>

using namespace std;

int main(){
    int n,k,i,sum[200000],h,mini=1e9,min_idx;
    sum[0]=0;

    scanf("%d%d",&n,&k);
    for(i=1;i<=n;i++){
        scanf("%d",&h);
        sum[i]=sum[i-1]+h;
    }

    for(i=k;i<=n;i++){
        if(sum[i]-sum[i-k]<mini){
            mini=sum[i]-sum[i-k];
            min_idx=i-k+1;
        }
    }

    printf("%d\n",min_idx);

    return 0;
}
