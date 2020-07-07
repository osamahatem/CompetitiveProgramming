#include<cstdio>
#include<algorithm>

using namespace std;

int main(){
    int i,idx,arr[100005],n,d;
    long long ans=0;
    scanf("%d%d",&n,&d);
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
        idx=lower_bound(arr,arr+i,arr[i]-d)-arr;
        if(i-idx<2)
            continue;
        ans+=(long long)(i-idx)*(long long)(i-idx-1)/2;
    }
    printf("%I64d\n",ans);
    return 0;
}
