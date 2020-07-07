#include<cstdio>
#include<cstring>

int main(){
    int n,k,po[100000],ans[100000],mini=1<<30,mini_idx,i;
    memset(ans,0,sizeof ans);
    scanf("%d%d",&n,&k);
    for(i=0;i<n;i++)
        scanf("%d",&po[i]);
    for(i=0;i<n;i++)
        ans[i%k]+=po[i];
    for(i=0;i<k;i++)
        if(ans[i]<mini){
            mini=ans[i];
            mini_idx=i+1;
        }
    printf("%d\n",mini_idx);
    return 0;
}
