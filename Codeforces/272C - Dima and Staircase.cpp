#include<cstdio>
#include<algorithm>

using namespace std;

#define MAXN 100001

long long tree[4*MAXN],lazy[4*MAXN],arr[MAXN];

void initialize(int n,int l,int r){
    if(l==r){
        tree[n]=lazy[n]=arr[l];
        return;
    }
    int mid=(l+r)/2;
    initialize(n*2,l,mid);
    initialize(n*2+1,mid+1,r);
    tree[n]=max(tree[n*2],tree[n*2+1]);
    lazy[n]=0;
    return;
}

void relax(int n,long long val){
    if(val==0)
        return;
    tree[n]=val;
    lazy[n]=val;
    return;
}

long long query(int n,int l,int r,int s,int e,long long fromUp){
    relax(n,fromUp);
    if(l>e || r<s)
        return 0;
    if(l>=s && r<=e)
        return tree[n];
    int mid=(l+r)/2;
    long long ret=max(query(n*2,l,mid,s,e,lazy[n]),query(n*2+1,mid+1,r,s,e,lazy[n]));
    lazy[n]=0;
    tree[n]=max(tree[n*2],tree[n*2+1]);
    return ret;
}

void update(int n,int l,int r,int s,int e,long long fromUp,long long &val){
    relax(n,fromUp);
    if(l>e || r<s)
        return;
    if(l>=s && r<=e){
        tree[n]=val;
        lazy[n]=val;
        return;
    }
    int mid=(l+r)/2;
    update(n*2,l,mid,s,e,lazy[n],val);
    update(n*2+1,mid+1,r,s,e,lazy[n],val);
    lazy[n]=0;
    tree[n]=max(tree[n*2],tree[n*2+1]);
    return;
}

int main(){
    int n,m,r,h;
    long long temp;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%I64d",&arr[i]);
    initialize(1,1,n);
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        scanf("%d%d",&r,&h);
        temp=query(1,1,n,1,r,0);
        printf("%I64d\n",temp);
        temp+=h;
        update(1,1,n,1,r,0,temp);
    }
    return 0;
}
