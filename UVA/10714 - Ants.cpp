#include<cstdio>
#include<algorithm>

using namespace std;

int main(){
    int t,len,n,x,near,far;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&len,&n);
        near=0;
        far=0;
        while(n--){
            scanf("%d",&x);
            far=max(far,max(x,len-x));
            near=max(near,min(x,len-x));
        }
        printf("%d %d\n",near,far);
    }
    return 0;
}
