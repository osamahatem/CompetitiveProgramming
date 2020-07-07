#include<cstdio>

int tree[400000][3],lazy[400000];

void mrg(int par,int left,int right){
    tree[par][0]=tree[left][0]+tree[right][0];
    tree[par][1]=tree[left][1]+tree[right][1];
    tree[par][2]=tree[left][2]+tree[right][2];
    return;
}

void relax(int n,int val){
    lazy[n]+=val;
    lazy[n]%=3;
    int temp;
    while(val--){
        temp=tree[n][2];
        tree[n][2]=tree[n][1];
        tree[n][1]=tree[n][0];
        tree[n][0]=temp;
    }
    return;
}

void build(int n,int s,int e){
    if(s==e){
        tree[n][0]=1;
        tree[n][1]=tree[n][2]=lazy[n]=0;
        return;
    }
    lazy[n]=0;
    int m=(s+e)/2;
    build(n*2,s,m);
    build(n*2+1,m+1,e);
    mrg(n,n*2,n*2+1);
    return;
}

int query(int n,int s,int e,int &l,int &r){
    if(s>=l && e<=r)
        return tree[n][0];
    int m=(s+e)/2;
    relax(n*2,lazy[n]);
    relax(n*2+1,lazy[n]);
    lazy[n]=0;
    int ans=0;
    if(m>=l)
        ans+=query(n*2,s,m,l,r);
    if(m+1<=r)
        ans+=query(n*2+1,m+1,e,l,r);
    return ans;
}

void update(int n,int s,int e,int &l,int &r){
    if(s>=l && e<=r){
        relax(n,1);
        return;
    }
    int m=(s+e)/2;
    relax(n*2,lazy[n]);
    relax(n*2+1,lazy[n]);
    lazy[n]=0;
    if(m>=l)
        update(n*2,s,m,l,r);
    if(m+1<=r)
        update(n*2+1,m+1,e,l,r);
    mrg(n,n*2,n*2+1);
    return;
}

int main(){
    int n,q,t,l,r;
    scanf("%d%d",&n,&q);
    build(1,0,n-1);
    while(q--){
        scanf("%d%d%d",&t,&l,&r);
        if(t)
            printf("%d\n",query(1,0,n-1,l,r));
        else
            update(1,0,n-1,l,r);
    }
	return 0;
}
