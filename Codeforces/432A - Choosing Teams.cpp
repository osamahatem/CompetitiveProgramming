#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,k,x,ans=0;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++){
        scanf("%d",&x);
        if(5-x>=k)
            ans++;
    }
    printf("%d\n",ans/3);
    return 0;
}
