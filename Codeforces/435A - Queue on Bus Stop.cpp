#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,m,arr[105],ans=0,cur;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    int i=0;
    while(i<n){
        cur=0;
        while(i<n && m-cur>=arr[i])
            cur+=arr[i++];
        ans++;
    }
    printf("%d\n",ans);
    return 0;
}
