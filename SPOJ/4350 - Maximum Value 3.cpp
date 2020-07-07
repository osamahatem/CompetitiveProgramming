#include<cstdio>
#include<algorithm>

using namespace std;

typedef struct node{
    int h,idx;
}node;

node tree[400000];

void build(int n,int s,int e){
    if(s==e){
        tree[n].h=0;
        tree[n].idx=0;
        return;
    }
    int m=(s+e)/s;
    build(n*2,s,m);
    build(n*2,m+1,e);
}

int main(){
    int n;
    scanf("%d\n",&n);
    build(1,0,n-1);
	return 0;
}
