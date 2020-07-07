#include<bits/stdc++.h>

using namespace std;

#define MAXN 10005
#define BIG 1000001

int tree[4*MAXN],lazy[4*MAXN],arr[MAXN];
bool prime[BIG];

void sieve(){
    for(long long i=2;i<BIG;i++)
        if(prime[i])
            for(long long j=i*i;j<BIG;j+=i)
                prime[j]=0;
    return;
}

void initialize(int n,int s,int e){
    lazy[n]=0;
    if(s==e){
        tree[n]=prime[arr[s]];
        return;
    }
    int mid=(s+e)/2;
    initialize(n*2,s,mid);
    initialize(n*2+1,mid+1,e);
    tree[n]=tree[n*2]+tree[n*2+1];
    return;
}

void relax(int n,int len,int val){
    if(!val)
        return;
    tree[n]=len*(int)prime[val];
    lazy[n]=val;
    return;
}

int query(int n,int s,int e,int &l,int &r,int fromUp){
    relax(n,e-s+1,fromUp);
    if(s>r || e<l)
        return 0;
    if(s>=l && e<=r)
        return tree[n];
    int mid=(s+e)/2;
    int ret=query(n*2,s,mid,l,r,lazy[n])+query(n*2+1,mid+1,e,l,r,lazy[n]);
    tree[n]=tree[n*2]+tree[n*2+1];
    lazy[n]=0;
    return ret;
}

void update(int n,int s,int e,int &l,int &r,int fromUp,int &val){
    relax(n,e-s+1,fromUp);
    if(s>r || e<l)
        return;
    if(s>=l && e<=r){
        relax(n,e-s+1,val);
        return;
    }
    int mid=(s+e)/2;
    update(n*2,s,mid,l,r,lazy[n],val);
    update(n*2+1,mid+1,e,l,r,lazy[n],val);
    tree[n]=tree[n*2]+tree[n*2+1];
    lazy[n]=0;
    return;

}

int main(){
    memset(prime,1,sizeof prime);
    prime[0]=prime[1]=0;
    sieve();
    int T,n,q,k,l,r,v;
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        printf("Case %d:\n",t);
        scanf("%d%d",&n,&q);
        for(int i=1;i<=n;i++)
            scanf("%d",&arr[i]);
        initialize(1,1,n);
        for(int i=0;i<q;i++){
            scanf("%d%d%d",&k,&l,&r);
            if(k)
                printf("%d\n",query(1,1,n,l,r,0));
            else{
                scanf("%d",&v);
                update(1,1,n,l,r,0,v);
            }
        }
    }
    return 0;
}
