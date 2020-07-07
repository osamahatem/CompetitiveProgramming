#include<cstdio>
#include<cstring>

typedef struct node{
    int sum,flag,lc,rc;
}node;

node tree[400000];

void build(int n,int s,int e){
    if(s==e){
        tree[n].sum=0;
        tree[n].flag=0;
        tree[n].lc=0;
        tree[n].rc=0;
        return;
    }
    int m=(s+e)/2;
    build(n*2,s,m);
    build(n*2+1,m+1,e);
    tree[n].flag=0;
    tree[n].sum=0;
    tree[n].lc=2*n;
    tree[n].rc=2*n+1;
    return;
}

void push_flag(int n,int s,int e){
    int len=e-s+1;
    int m=(s+e)/2;
    tree[tree[n].lc].flag+=tree[n].flag;
    tree[tree[n].rc].flag+=tree[n].flag;
    tree[n].sum+=tree[n].flag*len;
    tree[n].flag=0;
    return;
}

int query(int n,int s,int e,int &x){
    if(x<s || x>e)
        return 0;
    if(s==e){
        if(tree[n].flag>0)
            push_flag(n,s,e);
        int ret=tree[n].sum;
        tree[n].sum=0;
        return ret;
    }
    if(tree[n].flag>0)
        push_flag(n,s,e);
    int m=(s+e)/2;
    return query(n*2,s,m,x)+query(n*2+1,m+1,e,x);
}

void update(int n,int s,int e,int &l,int &r){
    if(e<l || s>r){
        push_flag(n,s,e);
        return;
    }
    if(s>=l && e<=r){
        tree[n].flag++;
        push_flag(n,s,e);
        return;
    }
    push_flag(n,s,e);
    int m=(s+e)/2;
    update(n*2,s,m,l,r);
    update(n*2+1,m+1,e,l,r);
    tree[n].sum=tree[n*2].sum+tree[2*n+1].sum;
    return;
}

int main(){
    int n,r,l,i;
    scanf("%d",&n);
    build(1,0,100000);
    for(i=0;i<n;i++){
        scanf("%d%d",&l,&r);
        printf("%d\n",query(1,0,100000,l)+query(1,0,100000,r));
        if(r-l>1)
            update(1,0,100000,++l,--r);
    }
	return 0;
}
