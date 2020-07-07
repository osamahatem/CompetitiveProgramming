#include<cstdio>
#include<algorithm>

using namespace std;

typedef struct node{
    long long height,area,len;
}node;

int arr[100000];
node tree[400000];

void build(int n,int s,int e){
    if(s==e){
        tree[n].len=1;
        tree[n].height=arr[s];
        tree[n].area=arr[s];
        return;
    }
    int m=(s+e)/2;
    build(n*2,s,m);
    build(n*2+1,m+1,e);
    tree[n].len=tree[n*2].len+tree[n*2+1].len;
    tree[n].height=min(tree[n*2].height,tree[n*2+1].height);
    tree[n].area=max(max(tree[n*2].area,tree[n*2+1].area),tree[n].len*tree[n].height);
    return;
}

int main(){
    int n,i;
    while(scanf("%d",&n),n!=0){
        for(i=0;i<n;i++)
            scanf("%d",&arr[i]);
        build(1,0,n-1);
        printf("%lld\n",tree[1].area);
    }
	return 0;
}
