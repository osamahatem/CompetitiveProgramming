#include<cstdio>
#include<cstring>
#include<vector>

using namespace std;

bool tree[4000000],lazy[4000000];
int q[4000000];

void relax(int n,bool val){
    tree[n]|=val;
    lazy[n]|=val;
    return;
}

void up_int(int n,int x,int y,int& l,int& r,bool fromUp){
    relax(n,fromUp);
    if(r<x || l>y)
        return;
    if(x<=l && y>=r){
        relax(n,1);
        return;
    }
    int mid=(x+y)/2;
    up_int(n*2,x,mid,l,r,lazy[n]);
    up_int(n*2+1,mid+1,y,l,r,lazy[n]);
    lazy[n]=0;
    return;
}

void update(int n,int x,int y,int& t,bool val,bool fromUp){
    relax(n,fromUp);
    if(t<x || t>y)
        return;
    if(t==x && t==y){
        if(tree[n]==1 && val==1)
            q[n]=1;
        else
            q[n]=0;
        return;
    }
    int mid=(x+y)/2;
    update(n*2,x,mid,t,val,lazy[n]);
    update(n*2+1,mid+1,y,t,val,lazy[n]);
    lazy[n]=0;
    q[n]=q[n*2]+q[n*2+1];
    return;
}

int main(){
    memset(tree,0,sizeof tree);
    memset(lazy,0,sizeof lazy);
    memset(q,0,sizeof q);
    int n,m,i,x,l,r,j,Q[300000];
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++){
        scanf("%d%d",&l,&r);
        up_int(1,1,1000000,l,r,0);
    }
    for(i=0;i<m;i++){
        scanf("%d",&x);
        for(j=0;j<x;j++){
            scanf("%d",&Q[j]);
            update(1,1,1000000,Q[j],1,0);
        }
        printf("%d\n",q[1]);
        for(j=0;j<x;j++)
            update(1,1,1000000,Q[j],0,0);
    }
    return 0;
}
