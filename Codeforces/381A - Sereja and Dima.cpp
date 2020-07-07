#include<cstdio>

int main(){
    int i,j,n,arr[1000],ans[2],flag=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    i=0;
    j=n-1;
    ans[0]=ans[1]=0;
    while(i<=j){
        if(arr[i]>arr[j]){
            ans[flag]+=arr[i];
            i++;
        }else{
            ans[flag]+=arr[j];
            j--;
        }
        flag++;
        flag%=2;
    }
    printf("%d %d\n",ans[0],ans[1]);
    return 0;
}
