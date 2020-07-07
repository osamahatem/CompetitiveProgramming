#include<cstdio>
#include<algorithm>

using namespace std;

int main(){
    int t,T,n,maxi,temp;
    scanf("%d",&T);
    for(t=1;t<=T;t++){
        scanf("%d",&n);
        maxi=0;
        while(n--){
            scanf("%d",&temp);
            maxi=max(maxi,temp);
        }
        printf("Case %d: %d\n",t,maxi);
    }
    return 0;
}
