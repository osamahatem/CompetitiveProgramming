#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,v,x,maxi=1,sum=0;
    scanf("%d%d",&n,&v);
    for(int i=0;i<n;i++){
        scanf("%d",&x);
        sum+=x;
        maxi=max(maxi,x);
    }
    sum-=maxi;
    if(sum<=v)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}
