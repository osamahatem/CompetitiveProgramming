#include<bits/stdc++.h>

int main(){
    int n,k,i=1,j;
    scanf("%d%d",&n,&k);
    if(n/k<3)
        printf("-1\n");
    else{
        for(j=2;j<=k;j++){
            printf("%d ",j);
            i++;
        }
        printf("1");
        while(i<n){
            for(j=1;j<=k && i<n;j++){
                printf(" %d",j);
                i++;
            }
        }
        printf("\n");
    }
    return 0;
}
