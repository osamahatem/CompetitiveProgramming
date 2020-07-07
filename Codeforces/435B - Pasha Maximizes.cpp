#include<bits/stdc++.h>

using namespace std;

int main(){
    char arr[20];
    int k;
    scanf("%s%d",arr,&k);
    int len=strlen(arr);
    for(int i=0;i<len && k;i++){
        int maxi=arr[i],maxi_idx=i;
        for(int j=i+1;j<len && j-i<=k;j++){
            if(arr[j]>maxi){
                maxi=arr[j];
                maxi_idx=j;
            }
        }
        k-=maxi_idx-i;
        for(int j=maxi_idx;j>i;j--)
            swap(arr[j-1],arr[j]);
    }
    printf("%s\n",arr);
    return 0;
}
