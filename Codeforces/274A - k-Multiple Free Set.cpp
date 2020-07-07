#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,k,arr[100001],ans=0,temp,len;
    bool vis[100001];
    memset(vis,0,sizeof vis);
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    sort(arr,arr+n);
    for(int i=n-1;i>=0;i--){
       if(vis[i])
            continue;
       int cur=i;
       len=1;
       while(arr[cur]%k==0){
            temp=lower_bound(arr,arr+n,arr[cur]/k)-arr;
            if(arr[temp]!=arr[cur]/k || temp==cur)
                break;
            vis[temp]=1;
            cur=temp;
            len++;
       }
       ans+=(len+1)/2;
    }
    printf("%d\n",ans);
    return 0;
}
