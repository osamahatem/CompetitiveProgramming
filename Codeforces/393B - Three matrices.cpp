#include<cstdio>

int main(){
    int n,W[175][175],i,j;
    double A[175][175],B[175][175];
    scanf("%d",&n);
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&W[i][j]);
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            A[i][j]=(W[i][j]+W[j][i])/2.0;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            B[i][j]=W[i][j]-A[i][j];
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(j>0)
                printf(" ");
            printf("%lf",A[i][j]);
        }
        printf("\n");
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(j>0)
                printf(" ");
            printf("%lf",B[i][j]);
        }
        printf("\n");
    }
    return 0;
}
