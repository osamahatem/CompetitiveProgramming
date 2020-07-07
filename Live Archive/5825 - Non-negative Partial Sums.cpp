#include<cstdio>
#include<algorithm>

using namespace std;

int arr[1000000],cumulative[1000000],mini_back[1000000],mini_front[1000000],n,i,sum,temp,ans;

int main(){
    while(scanf("%d",&n),n!=0){
        sum=0,temp=1000000000,ans=0;
        for(i=0;i<n;i++){
            scanf("%d",&arr[i]);
            sum+=arr[i];
            cumulative[i]=sum;
            temp=min(temp,cumulative[i]);
            mini_front[i]=temp;
        }
        temp=1000000000;
        for(i=n-1;i>=0;i--){
            temp=min(temp,cumulative[i]);
            mini_back[i]=temp;
        }
        for(i=0;i<n;i++){
            if(i==0){
                if(cumulative[n-1]>=0 && mini_front[n-1]>=0)
                    ans++;
            }else{
                if(cumulative[n-1]-cumulative[i-1]>=0 && (mini_back[i]>=0 || cumulative[n-1]-cumulative[i-1]>=mini_back[i]) && cumulative[i-1]>=0 && (mini_front[i-1]>=0 || cumulative[n-1]-cumulative[i-1]>=mini_front[i-1]))
                    ans++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
