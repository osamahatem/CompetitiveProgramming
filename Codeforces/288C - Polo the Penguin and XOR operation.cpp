#include<bits/stdc++.h>

using namespace std;

int len(int x){
    int ans=0;
    for(;x;x>>=1)
        ans++;
    return ans;
}

int ans[1000005];

int main(){
    memset(ans,-1,sizeof ans);
    int n;
    long long sum=0;
    scanf("%d",&n);
    ans[n+1]=n+1;
    for(int i=1<<(len(n)-1);i;i>>=1){
        for(int j=i;ans[j]==-1;j++){
            int complement=i-(j-i)-1;
            ans[complement]=j;
            ans[j]=complement;
            sum+=2*(j^complement);
        }
    }
    if(ans[0]==-1)
        ans[0]=0;
    printf("%I64d\n%d",sum,ans[0]);
    for(int i=1;i<=n;i++)
        printf(" %d",ans[i]);
    printf("\n");
    return 0;
}
