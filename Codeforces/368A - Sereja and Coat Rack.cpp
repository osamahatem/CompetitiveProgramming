#include<cstdio>
#include<algorithm>

using namespace std;

int main(){
    int n,d,i,m,arr[100],ans=0;
    scanf("%d%d",&n,&d);
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    sort(arr,arr+n);
    scanf("%d",&m);
    for(i=0;i<m && i<n;i++)
        ans+=arr[i];
    ans-=max(0,m-n)*d;
    printf("%d\n",ans);
    return 0;
}
