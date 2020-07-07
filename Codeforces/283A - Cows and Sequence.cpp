#include<bits/stdc++.h>

using namespace std;

long long tree[1<<19],lazy[1<<19],val;
int size=1,qs,qe;

void relax(int n,int val,int len){
    tree[n]+=val*len;
    lazy[n]+=val;
    return;
}

void update(int n,int s,int e,long long fromUp,bool t){
    relax(n,fromUp,e-s+1);
    if(s>qe || e<qs)
        return;
    if(s>=qs && e<=qe){
        if(t){
            tree[n]=val;
            return;
        }
        relax(n,val,e-s+1);
        return;
    }
    int mid=s+((e-s)>>1);
    int left=(n<<1)+1,right=left+1;
    update(left,s,mid,lazy[n],t);
    update(right,mid+1,e,lazy[n],t);
    lazy[n]=0;
    tree[n]=tree[left]+tree[right];
    return;
}

long long query(int n,int s,int e,long long fromUp){
    relax(n,fromUp,e-s+1);
    if(s>qe || e<qs)
        return 0;
    if(s>=qs && e<=qe)
        return tree[n];
    int mid=s+((e-s)>>1);
    int left=(n<<1)+1,right=left+1;
    long long ret=query(left,s,mid,lazy[n])+query(right,mid+1,e,lazy[n]);
    lazy[n]=0;
    tree[n]=tree[left]+tree[right];
    return ret;
}

int main(){
    int n,t,a,x;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&t);
        if(t==1){
            scanf("%d%d",&a,&x);
            qs=1;
            qe=a;
            val=x;
            update(0,1,n+5,0,0);
        }else if(t==2){
            scanf("%d",&x);
            size++;
            qe=qs=size;
            val=x;
            update(0,1,n+5,0,1);
        }else{
            qe=qs=size;
            val=0;
            update(0,1,n+5,0,1);
            size--;
        }
        qs=1;
        qe=size;
        printf("%f\n",(double)query(0,1,n+5,0)/size);
    }
    return 0;
}
