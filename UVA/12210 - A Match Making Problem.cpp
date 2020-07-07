#include<cstdio>
#include<algorithm>

using namespace std;

int main(){
    int n,m,t=1,mini,i,x;
    while(scanf("%d%d",&n,&m),n!=0){
        mini=60;
        for(i=0;i<n;i++){
            scanf("%d",&x);
            mini=min(mini,x);
        }
        for(i=0;i<m;i++)
            scanf("%d",&x);
        printf("Case %d: ",t++);
        if(n>m)
            printf("%d %d\n",n-m,mini);
        else
            printf("0\n");
    }
	return 0;
}
