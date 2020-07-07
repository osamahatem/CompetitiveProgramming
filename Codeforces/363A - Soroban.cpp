#include<cstdio>

int main(){
    int n,t;
    scanf("%d",&n);

    if(n==0){
        printf("O-|-OOOO\n");
        return 0;
    }

    while(n>0){
        int t=n%10;
        if(t<5)
            printf("O-|");
        else
            printf("-O|");

        t%=5;
        for(int i=0;i<5;i++){
            if(t==0)
                printf("-");
            else
                printf("O");
            t--;
        }
        n/=10;
        printf("\n");
    }
    return 0;
}
