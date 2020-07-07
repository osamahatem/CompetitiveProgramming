#include<cstdio>
#include<algorithm>

using namespace std;

int main(){
    int m,n,i,j,q,mini=100000,arr[100005],ans=0;
    scanf("%d",&m);
    for(i=0;i<m;i++){
        scanf("%d",&q);
        mini=min(mini,q);
    }
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    sort(arr,arr+n);
    i=n-1;
    while(i>=0){
        j=0;
        while(j<mini && i>=0){
            ans+=arr[i--];
            j++;
        }
        i-=2;
    }
    printf("%d\n",ans);
    return 0;
}
