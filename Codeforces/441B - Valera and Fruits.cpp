#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,v,a,b,days[3005],left[3005],ans=0;
    memset(days,0,sizeof days);
    memset(left,0,sizeof left);
    scanf("%d%d",&n,&v);
    for(int i=0;i<n;i++){
        scanf("%d%d",&a,&b);
        days[a]+=b;
    }
    for(int i=0;i<3001;i++){
        ans+=min(v,left[i]+days[i]);
        if(days[i]+left[i]>v)
            left[i+1]=min(days[i]+left[i]-v,days[i]);
    }
    printf("%d\n",ans);
    return 0;
}

