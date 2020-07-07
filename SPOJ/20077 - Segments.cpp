#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,x1,x2;
    vector< pair<int,int> > all;
    scanf("%d",&n);
    while(n--){
        scanf("%d%d",&x1,&x2);
        all.push_back(make_pair(min(x1,x2),max(x1,x2)));
    }
    sort(all.begin(),all.end());
    int curStart=all[0].first,curEnd=all[0].second,ans=0;
    for(int i=1;i<all.size();i++){
        if(all[i].first<=curEnd)
            curEnd=max(curEnd,all[i].second);
        else{
            ans+=curEnd-curStart;
            curStart=all[i].first;
            curEnd=all[i].second;
        }
    }
    ans+=curEnd-curStart;
    printf("%d\n",ans);
    return 0;
}
