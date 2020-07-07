#include<bits/stdc++.h>

using namespace std;

int n,arr[205];

int getMax(){
    int maxi=-(1<<20);
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum+=arr[j];
            maxi=max(sum,maxi);
        }
    }
    return maxi;
}

int solve(int k){
    int ret=getMax();
    if(!k)
        return ret;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            swap(arr[i],arr[j]);
            ret=max(ret,solve(k-1));
            swap(arr[i],arr[j]);
        }
    }
    return ret;
}

int main(){
    int k;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    printf("%d\n",solve(k));
    return 0;
}
