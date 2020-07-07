#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,x,arr[100005];
    long long ans=0;
    scanf("%d%d",&n,&x);
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    sort(arr,arr+n);
    for(int i=0;i<n;i++){
        ans+=(long long)x*arr[i];
        x--;
        x+=(x==0);
    }
    printf("%I64d\n",ans);
    return 0;
}
