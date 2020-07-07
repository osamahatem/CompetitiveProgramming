#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

typedef struct log{
    int time;
    bool type;
}log;

bool cmp(const log &a,const log &b){
    return a.time<b.time;
}

int tree[800],lazy[800];

void relax(int n,int val){
    lazy[n]+=val;
    tree[n]+=val;
    return;
}

void update(int n,int s,int e,int &l, int &r,int val,int fromUp){
    relax(n,fromUp);
    if(s>r || e<l)
        return;
    if(s>=l && e<=r){
        relax(n,val);
        return;
    }
    int m=(s+e)/2;
    update(n*2,s,m,l,r,val,lazy[n]);
    update(n*2+1,m+1,e,l,r,val,lazy[n]);
    lazy[n]=0;
    tree[n]=max(tree[n*2],tree[n*2+1]);
    return;
}

int main(){
    int t,n,i,x,y;
    log in[205];
    scanf("%d",&t);
    while(t--){
        memset(tree,0,sizeof tree);
        memset(lazy,0,sizeof lazy);
        scanf("%d",&n);
        n*=2;
        for(i=0;i<n;i++){
            scanf("%d",&in[i].time);
            in[i].type=i%2;
        }
        sort(in,in+n,cmp);
        n--;
        for(i=0;i<=n;i++)
            in[i].time=i;
        for(i=0;i<=n;i++){
            if(in[i].type)
                update(1,0,n,in[i].time,n,-1,0);
            else
                update(1,0,n,in[i].time,n,1,0);
        }
        printf("%d\n",tree[1]);
    }
	return 0;
}
