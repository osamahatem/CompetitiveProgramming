#include<cstdio>
#include<cstring>

int tree[400000];
bool lazy[400000];

void relax(int n,bool val,int len){
    if(!val)
        return;
    lazy[n]=!lazy[n];
    tree[n]=len-tree[n];
    return;
}

int query(int n,int s,int e,int &l,int &r,bool fromUp){
    relax(n,fromUp,e-s+1);
    if(s>r || e<l)
        return 0;
    if(s>=l && e<=r)
        return tree[n];
    int m=(s+e)/2;
    int ans=query(n*2,s,m,l,r,lazy[n])+query(n*2+1,m+1,e,l,r,lazy[n]);
    tree[n]=tree[n*2]+tree[n*2+1];
    lazy[n]=0;
    return ans;
}

void update(int n,int s,int e,int &l,int &r,bool fromUp){
    relax(n,fromUp,e-s+1);
    if(s>r || e<l)
        return;
    if(s>=l && e<=r){
        relax(n,1,e-s+1);
        return;
    }
    int m=(s+e)/2;
    update(n*2,s,m,l,r,lazy[n]);
    update(n*2+1,m+1,e,l,r,lazy[n]);
    tree[n]=tree[n*2]+tree[n*2+1];
    lazy[n]=0;
    return;
}

int main(){
    memset(tree,0,sizeof tree);
    memset(lazy,0,sizeof lazy);
    int n,m,t,l,r;
    scanf("%d%d",&n,&m);
    while(m--){
        scanf("%d%d%d",&t,&l,&r);
        l--;
        r--;
        if(t)
            printf("%d\n",query(1,0,n-1,l,r,0));
        else
            update(1,0,n-1,l,r,0);
    }
	return 0;
}
