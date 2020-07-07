#include<bits/stdc++.h>

using namespace std;

int main(){
    int k;
    while(scanf("%d",&k)!=EOF){
        vector< pair<int,int> > ans;
        for(int y=k+1;y<=2*k;y++){
            if((y*k)%(y-k)==0)
                ans.push_back(make_pair(y*k/(y-k),y));
        }
        printf("%d\n",ans.size());
        for(int i=0;i<ans.size();i++)
            printf("1/%d = 1/%d + 1/%d\n",k,ans[i].first,ans[i].second);
    }
    return 0;
}
