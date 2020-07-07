#include<cstdio>

int main(){
    int n,arr[100005],i;
    long long sum=0;
    char ans[100005];
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    for(i=n-1;i>=0;i--){
        if(sum>0){
            sum-=arr[i];
            ans[i]='-';
        }else{
            sum+=arr[i];
            ans[i]='+';
        }
    }
    if(sum<0){
        sum*=-1;
        for(i=0;i<n;i++){
            if(ans[i]=='-')
                ans[i]='+';
            else
                ans[i]='-';
        }
    }
    for(i=0;i<n;i++)
        printf("%c",ans[i]);
    printf("\n");
    return 0;
}
