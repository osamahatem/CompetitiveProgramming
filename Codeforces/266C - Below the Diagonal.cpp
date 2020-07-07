#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

struct op{int t,a,b;};

int main(){
    int n,i,x,y,last[1005];
    vector<op> ans;
    op temp;
    memset(last,1005,sizeof last);
    scanf("%d",&n);
    for(i=1;i<n;i++){
        scanf("%d%d",&x,&y);
        last[y]=min(last[y],x);
    }
    return 0;
}
