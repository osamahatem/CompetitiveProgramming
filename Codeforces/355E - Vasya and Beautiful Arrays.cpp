#include<cstdio>
#include<algorithm>

using namespace std;

int main(){
    int n,k,i,arr[300000],mini=1000000,lo,hi,mid,ans;
    bool flag;
    scanf("%d%d",&n,&k);
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
        mini=min(mini,arr[i]);
    }
    lo=1,hi=mini;
    while(lo<=hi){
        mid=(lo+hi)/2;
        printf("**%d %d %d\n",lo,hi,mid);
        flag=1;
        for(i=0;i<n;i++){
            if((arr[i]-arr[i]/mid*mid)>k){
                flag=0;
                break;
            }
        }
        if(flag){
            ans=mid;
            lo=mid+1;
        }else
            hi=mid-1;
    }
    printf("%d\n",ans);
	return 0;
}
