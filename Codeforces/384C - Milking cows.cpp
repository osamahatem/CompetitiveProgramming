#include<cstdio>
#include<algorithm>

using namespace std;

struct node{int sz,sum;};
struct ord{int idx,dist,seen;};

node tree[800000];
ord order[200005];
int arr[200005],cumu[200005],n;

bool cmp(const ord &a,const ord &b){
    if(a.seen!=b.seen)
        return a.seen<b.seen;
    return a.dist<b.dist;
}

void build(int n,int s,int e){
    if(s==e){
        tree[n].sz=1;
        tree[n].sum=arr[s];
        return;
    }
    int m=(s+e)/2;
    build(n*2,s,m);
    build(n*2+1,m+1,e);
    tree[n].sz=tree[n*2].sz+tree[n*2+1].sz;
    tree[n].sum=tree[n*2].sum+tree[n*2+1].sum;
    return;
}

void update(int n,int s,int e,int t){
    if(s>t)
        return;
    if(e<t)
        return;
    if(s==e){
        tree[n].sz=0;
        tree[n].sum=0;
        return;
    }
    int m=(s+e)/2;
    update(n*2,s,m,t);
    update(n*2+1,m+1,e,t);
    return;
}

int main(){
    int i,x;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&arr[i]);
        cumu[i]=cumu[i-1]+arr[i];
    }
    for(i=1;i<=n;i++){
        order[i-1].idx=1;
        order[i-1].seen=cumu[i-1]+n-i-(cumu[n]-cumu[i]);
        if(arr[i]==0)
            order[i-1].dist=n-i;
        else
            order[i-1].dist=i-1;
    }
    sort(order,order+n,cmp);
    build(1,1,n);
    for(i=0;i<n;i++){
        ans+=query(1,1,n,)
    }
    return 0;
}
