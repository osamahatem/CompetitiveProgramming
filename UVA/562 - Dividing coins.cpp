#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int arr[100],n,sum,memo[100][50001];

int min_dif(int idx,int sum_so_far){
    if(idx==n)
        return abs(sum-2*sum_so_far);
    int &ret=memo[idx][sum_so_far];
    if(ret!=-1)
        return ret;
    return ret=min(min_dif(idx+1,sum_so_far),min_dif(idx+1,sum_so_far+arr[idx]));
}

int main(){
    int t,i;
    scanf("%d",&t);
    while(t--){
        sum=0;
        memset(memo,-1,100*50001*4);
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%d",&arr[i]);
            sum+=arr[i];
        }
        printf("%d\n",min_dif(0,0));
    }
	return 0;
}
