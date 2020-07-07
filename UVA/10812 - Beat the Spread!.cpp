#include<cstdio>

int main(){
    int n,s,d,x;
    scanf("%d",&n);
    while(n--){
        scanf("%d%d",&s,&d);
        if(d>s || (s+d)%2==1){
            printf("impossible\n");
        }else{
            x=s+d;
            x/=2;
            printf("%d %d\n",x,s-x);
        }
    }
    return 0;
}
