#include<cstdio>

int main(){
    int n;
    scanf("%d",&n);
    int s=1,e=n*n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n/2;j++)
            printf("%d ",s++);
        for(int j=n/2;j>0;j--){
            printf("%d",e-j+1);
            if(j>1)
                printf(" ");
        }
        printf("\n");
        e-=n/2;
    }
    return 0;
}
