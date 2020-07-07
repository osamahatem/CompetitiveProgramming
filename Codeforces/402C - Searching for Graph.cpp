#include<cstdio>

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,p,edges=0;
        scanf("%d%d",&n,&p);
        for(int i=1;i<=n;i++){
            for(int j=1;j<i && edges<2*i+p;j++){
                printf("%d %d\n",i,j);
                edges++;
            }
        }
    }
    return 0;
}
