#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,arr[15],ans=0;
        scanf("%d",&n);
        for(int i=0;i<15;i++)
            scanf("%d",&arr[i]);
        for(int i=1;i<15;i++){
            int mini=arr[i];
            for(int j=i+1;j<15;j++){
                if(mini>arr[i-1] && mini>arr[j])
                    ans++;
                mini=min(mini,arr[j]);
            }
        }
        printf("%d %d\n",n,ans);
    }
    return 0;
}
