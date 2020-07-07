#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,h,a,home[100005],away[100005];
    vector< pair<int,int> >all;
    memset(home,0,sizeof home);
    memset(away,0,sizeof away);
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d%d",&h,&a);
        home[h]++;
        away[a]++;
        all.push_back(make_pair(h,a));
    }
    for(int i=0;i<n;i++){
        a=all[i].second;
        printf("%d %d\n",n-1+home[a],n-1-home[a]);
    }
    return 0;
}
