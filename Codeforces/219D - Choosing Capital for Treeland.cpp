#include<cstdio>
#include<vector>

using namespace std;

typedef struct node{
    vector<int> ed;
}node;

int main(){
    int n,i,x,y;
    node g[200000];
    scanf("%d",&n);
    for(i=0;i<n-1;i++){
        scanf("%d%d",&x,&y);
        x--;
        y--;
        g[x].ed.push_back(y);
    }
	return 0;
}
