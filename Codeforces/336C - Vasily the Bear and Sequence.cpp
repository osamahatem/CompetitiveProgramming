#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,arr[100005],ans=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    int temp=arr[n-1];
    while(temp){
        ans++;
        temp>>=1;
    }
    ans--;
    int start=upper_bound(arr,arr+n,(1<<ans)-1)-arr;
    printf("%d\n",n-start);
    for(int i=start;i<n;i++){
        if(i!=start)
            printf(" ");
        printf("%d",arr[i]);
    }
    printf("\n");
    return 0;
}
