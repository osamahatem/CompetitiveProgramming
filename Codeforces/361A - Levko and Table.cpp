#include<cstdio>

int main(){
    int n,k,i,j;
    scanf("%d%d",&n,&k);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(j>0)
                printf(" ");
            if(i==j)
                printf("%d",k/n+k%n);
            else
                printf("%d",k/n);
        }
        printf("\n");
    }
    return 0;
}
