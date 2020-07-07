#include<cstdio>

int main(){
    int k,d;
    scanf("%d%d",&k,&d);
    int cnt=d/k,mod=d%k;
    if(d==0 && k!=1){
        printf("No solution\n");
        return 0;
    }
    while(k--){
        if(d){
            printf("%d",cnt+mod);
            d-=cnt+mod;
            mod=0;
        }else
            printf("%d",0);
    }
    printf("\n");
	return 0;
}
