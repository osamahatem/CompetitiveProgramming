#include<cstdio>
#include<cstring>

int arr[100001],tree[400000][21],lazy[400000];

void build(int n,int s,int e){
    int i;
    if(s==e){
        for(i=0;i<=20;i++){
            if(arr[s] & 1<<i)
                tree[n][i]=1;
            else
                tree[n][i]=0;
        }
        lazy[n]=0;
        return;
    }
    int m=(s+e)/2;
    build(n*2,s,m);
    build(n*2+1,m+1,e);
    for(i=0;i<=20;i++)
        tree[n][i]=tree[n*2][i]+tree[n*2+1][i];
    return;
}

void relax(int n,int len,int x){
    int i;
    for(i=0;i<=20;i++)
        if(x & 1<<i)
            tree[n][i]=len-tree[n][i];
    lazy[n]^=x;
    return;
}

long long query(int n,int s,int e,int &l,int &r,int up){
    relax(n,e-s+1,up);
    if(s>r || e<l)
        return 0;
    if(s>=l && e<=r){
        int i;
        long long ans=0;
        for(i=0;i<=20;i++)
            ans+=tree[n][i]*(long long)(1<<i);
        return ans;
    }
    int m=(s+e)/2,i;
    long long ans=query(n*2,s,m,l,r,lazy[n])+query(n*2+1,m+1,e,l,r,lazy[n]);
    for(i=0;i<=20;i++)
        tree[n][i]=tree[n*2][i]+tree[n*2+1][i];
    lazy[n]=0;
    return ans;
}

void update(int n,int s,int e,int &l,int &r,int &x,int up){
    relax(n,e-s+1,up);
    if(s>r || e<l)
        return;
    if(s>=l && e<=r){
        lazy[n]^=x;
        int i;
        for(i=0;i<=20;i++)
            if(x & 1<<i)
                tree[n][i]=(e-s+1)-tree[n][i];
        return;
    }
    int m=(s+e)/2,i;
    update(n*2,s,m,l,r,x,lazy[n]);
    update(n*2+1,m+1,e,l,r,x,lazy[n]);
    for(i=0;i<=20;i++)
        tree[n][i]=tree[n*2][i]+tree[n*2+1][i];
    lazy[n]=0;
    return;
}

int main(){
    int n,i,m,q,l,r,x;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    build(1,0,n-1);
    scanf("%d",&m);
    for(i=0;i<m;i++){
        scanf("%d%d%d",&q,&l,&r);
        if(q==2){
            scanf("%d",&x);
            update(1,0,n-1,--l,--r,x,0);
        }else
            printf("%I64d\n",query(1,0,n-1,--l,--r,0));
    }
	return 0;
}
