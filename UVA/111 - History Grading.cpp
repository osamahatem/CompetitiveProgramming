#include<cstdio>
#include<algorithm>

using namespace std;

int main(){
    int n,i,j,x,rnk[25],arr[25],maxi,lis[25];
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&rnk[i]);
    while(scanf("%d",&x)!=EOF){
        arr[--x]=rnk[0];
        for(i=1;i<n;i++){
            scanf("%d",&x);
            arr[--x]=rnk[i];
        }
        maxi=1;
        for(i=0;i<n;i++)
            lis[i]=1;
        for(i=0;i<n;i++){
            for(j=0;j<i;j++){
                if(arr[j]<arr[i]){
                    lis[i]=max(lis[i],lis[j]+1);
                    maxi=max(maxi,lis[i]);
                }
            }
        }
        printf("%d\n",maxi);
    }
	return 0;
}
