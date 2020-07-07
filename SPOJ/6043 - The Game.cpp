#include<cstdio>
#include<vector>

using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,i,x,ans=0;
        scanf("%d",&n);
        for(i=1;i<=n;i++){
            scanf("%d",&x);
            if(x%2)
                ans^=i;
        }
        if(ans)
            printf("Tom Wins\n");
        else
            printf("Hanks Wins\n");
    }
	return 0;
}
