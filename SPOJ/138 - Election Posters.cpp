#include<cstdio>
#include<cstring>
#include<map>
#include<set>
#include<utility>
#include<vector>

using namespace std;

bool tree[320000];

bool query(int n,int s,int e,int &l,int &r){
    if(s>r || e<l)
        return 0;
    if(s>=l && e<=r)
        return tree[n];
    int m=(s+e)/2;
    tree[n*2]=tree[n] & tree[n*2];
    tree[n*2+1]=tree[n] & tree[n*2+1];
    return query(n*2,s,m,l,r) | query(n*2+1,m+1,e,l,r);
}

void update(int n,int s,int e,int &l,int &r){
    if(s>r || e<l)
        return;
    if(s>=l && e<=r){
        tree[n]=0;
        return;
    }
    int m=(s+e)/2;
    tree[n*2]=tree[n] & tree[n*2];
    tree[n*2+1]=tree[n] & tree[n*2+1];
    update(n*2,s,m,l,r);
    update(n*2+1,m+1,e,l,r);
    tree[n]=tree[n*2] | tree[n*2+1];
    return;
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        memset(tree,1,sizeof tree);
        int n,i,x,y,temp,r=0,ans=0;
        set<int> pos;
        set<int>::iterator it;
        map<int,int> rnk;
        vector<pair<int,int> > posters;
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%d%d",&x,&y);
            posters.push_back(make_pair(x,y));
            pos.insert(x);
            pos.insert(y);
        }
        for(it=pos.begin();it!=pos.end();it++)
            rnk[*it]=++r;
        for(i=posters.size()-1;i>=0;i--){
            posters[i].first=rnk[posters[i].first];
            posters[i].second=rnk[posters[i].second];
            ans+=query(1,1,r,posters[i].first,posters[i].second);
            update(1,1,r,posters[i].first,posters[i].second);
        }
        printf("%d\n",ans);
    }
	return 0;
}
