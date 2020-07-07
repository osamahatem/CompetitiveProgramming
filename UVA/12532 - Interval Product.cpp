#include<cstdio>

typedef struct node{
    int neg;
    bool zero;
}node;

node tree[400000];
int arr[100000];

void build(int n,int s,int e){
    if(s==e){
        tree[n].zero=0;
        tree[n].neg=0;
        if(arr[s]<0)
            tree[n].neg++;
        if(arr[s]==0)
            tree[n].zero=1;
        return;
    }
    int m=(s+e)/2;
    build(n*2,s,m);
    build(n*2+1,m+1,e);
    tree[n].neg=tree[n*2].neg+tree[n*2+1].neg;
    tree[n].zero=tree[n*2].zero|tree[n*2+1].zero;
    return;
}

void update(int n,int s,int e,int &idx,int &val){
    if(s>idx || e<idx)
        return;
    if(s==idx && e==idx){
        arr[s]=val;
        tree[n].zero=0;
        tree[n].neg=0;
        if(arr[s]<0)
            tree[n].neg++;
        if(arr[s]==0)
            tree[n].zero=1;
        return;
    }
    int m=(s+e)/2;
    update(n*2,s,m,idx,val);
    update(n*2+1,m+1,e,idx,val);
    tree[n].neg=tree[n*2].neg+tree[n*2+1].neg;
    tree[n].zero=tree[n*2].zero|tree[n*2+1].zero;
    return;
}

int query(int n,int s,int e,int &x,int &y){
    if(s>y || e<x)
        return 1;
    if(s>=x && e<=y){
        if(tree[n].zero)
            return 0;
        if(tree[n].neg%2)
            return -1;
        return 1;
    }
    int m=(s+e)/2;
    return query(n*2,s,m,x,y)*query(n*2+1,m+1,e,x,y);
}

int main(){
    int n,k,i,x,y,t;
    char q;
    while(scanf("%d%d",&n,&k)!=EOF){
        for(i=0;i<n;i++)
            scanf("%d ",&arr[i]);
        build(1,0,n-1);
        for(i=0;i<k;i++){
            scanf("%c%d%d\n",&q,&x,&y);
            if(q=='C')
                update(1,0,n-1,--x,y);
            else{
                t=query(1,0,n-1,--x,--y);
                if(t==0)
                    printf("0");
                else if(t<0)
                    printf("-");
                else
                    printf("+");
            }
        }
        printf("\n");
    }
	return 0;
}
