#include<cstdio>

int main(){
    int n,i;
    scanf("%d",&n);
    for(i=n;i<2*n;i++){
        printf("%d",i);
        if(i<2*n-1)
            printf(" ");
    }
    printf("\n");
    return 0;
}
