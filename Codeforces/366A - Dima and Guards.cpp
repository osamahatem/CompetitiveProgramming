#include<cstdio>

int main(){
    int n,i,a,b,c,d;
    scanf("%d",&n);
    for(i=1;i<=4;i++){
        scanf("%d%d%d%d",&a,&b,&c,&d);
        if(a+c<=n){
            printf("%d %d %d\n",i,a,n-a);
            return 0;
        }
        if(a+d<=n){
            printf("%d %d %d\n",i,a,n-a);
            return 0;
        }
        if(b+c<=n){
            printf("%d %d %d\n",i,b,n-b);
            return 0;
        }
        if(b+d<=n){
            printf("%d %d %d\n",i,b,n-b);
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}
