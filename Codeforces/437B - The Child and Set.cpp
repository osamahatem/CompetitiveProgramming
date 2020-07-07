#include<bits/stdc++.h>

using namespace std;

int lowbit(int x){
    for(int i=0;;i++)
        if(x&(1<<i))
            return 1<<i;
}

int main(){
    int sum,lim;
    set< pair<int,int> > all;
    vector<int> ans;
    scanf("%d%d",&sum,&lim);
    for(int i=1;i<=lim;i++)
        all.insert(make_pair(lowbit(i),i));
    while(sum && all.size()){
        if(all.rbegin()->first<=sum)
            sum-=all.rbegin()->first,ans.push_back(all.rbegin()->second);
        all.erase(make_pair(all.rbegin()->first,all.rbegin()->second));
    }
    if(sum){
        printf("-1\n");
        return 0;
    }
    printf("%d\n",ans.size());
    for(int i=0;i<ans.size();i++){
        if(i)
            printf(" ");
        printf("%d",ans[i]);
    }
    printf("\n");
    return 0;
}

