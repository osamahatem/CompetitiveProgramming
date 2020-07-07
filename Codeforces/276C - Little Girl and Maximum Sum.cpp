#include<cstdio>
#include<cstring>
#include<algorithm>
#include<functional>

using namespace std;

#define MAXN 200001

int tree[4*MAXN],lazy[4*MAXN],arr[MAXN],frequency[MAXN];

void relax(int n,int val){
    lazy[n]+=val;
    tree[n]+=val;
    return;
}

void update(int n,int l,int r,int &s,int &e,int fromUp){
    relax(n,fromUp);
    if(r<s || l>e)
        return;
    if(l>=s && r<=e){
        tree[n]++;
        lazy[n]++;
        return;
    }
    int mid=(l+r)/2;
    update(n*2,l,mid,s,e,lazy[n]);
    update(n*2+1,mid+1,r,s,e,lazy[n]);
    lazy[n]=0;
    tree[n]=max(tree[n*2],tree[n*2+1]);
    return;
}

int query(int n,int l,int r,int &t,int fromUp){
    relax(n,fromUp);
    if(l>t || r<t)
        return 0;
    if(l==r && t==r)
        return tree[n];
    int mid=(l+r)/2;
    int ret=query(n*2,l,mid,t,lazy[n])+query(n*2+1,mid+1,r,t,lazy[n]);
    lazy[n]=0;
    return ret;
}

int main(){
    int n,m,l,r;
    scanf("%d%d",&n,&m);
    memset(tree,0,sizeof tree);
    memset(lazy,0,sizeof lazy);
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    sort(arr,arr+n,greater<int>());
    for(int i=0;i<m;i++){
        scanf("%d%d",&l,&r);
        update(1,1,n,l,r,0);
    }
    for(int i=1;i<=n;i++)
        frequency[i-1]=query(1,1,n,i,0);
    sort(frequency,frequency+n,greater<int>());
    long long ans=0;
    for(int i=0;i<n;i++)
        ans+=1ll*arr[i]*frequency[i];
    printf("%I64d\n",ans);
    return 0;
}
