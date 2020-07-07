#include<cstdio>

int main(){
    int n,ans=0,i,j;
    scanf("%d",&n);
    ans+=n*n/2;
    if(n%2==1)
        ans++;
    printf("%d\n",ans);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if((i+j)%2==0)
                printf("C");
            else
                printf(".");
        }
        printf("\n");
    }
    return 0;
}
