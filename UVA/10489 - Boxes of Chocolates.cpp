#include<cstdio>

int main(){
    int t,n,b,k,a,sum,temp;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&b);
        sum=0;
        while(b--){
            scanf("%d",&k);
            temp=1;
            while(k--){
                scanf("%d",&a);
                temp*=a;
                temp%=n;
            }
            sum+=temp;
        }
        printf("%d\n",sum%n);
    }
    return 0;
}
