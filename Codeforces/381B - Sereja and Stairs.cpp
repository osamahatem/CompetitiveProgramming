#include<cstdio>
#include<cstring>
#include<algorithm>
#include<deque>

using namespace std;

int main(){
    int i,n,arr[100005],vis[5005];
    deque<int> Q;
    memset(vis,0,sizeof vis);
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    sort(arr,arr+n);
    int maxi=arr[n-1];
    for(i=n-1;i>=0;i--){
        if(vis[arr[i]]==0){
            vis[arr[i]]++;
            Q.push_back(arr[i]);
        }else if(vis[arr[i]]==1 && arr[i]!=maxi){
            vis[arr[i]]++;
            Q.push_front(arr[i]);
        }
    }
    printf("%d\n",Q.size());
    for(i=0;i<Q.size();i++){
        if(i>0)
            printf(" ");
        printf("%d",Q[i]);
    }
    printf("\n");
    return 0;
}
