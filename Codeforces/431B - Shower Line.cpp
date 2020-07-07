#include<bits/stdc++.h>

using namespace std;

int main(){
    int g[5][5];
    for(int i=0;i<5;i++)
        for(int j=0;j<5;j++)
            scanf("%d",&g[i][j]);
    int arr[]={0,1,2,3,4},ans=0;
    do{
        int temp=0;
        for(int i=0;i<5;i++)
            for(int j=i+1;j<5;j+=2)
                temp+=g[arr[j]][arr[j-1]]+g[arr[j-1]][arr[j]];
        ans=max(temp,ans);
    }while(next_permutation(arr,arr+5));
    printf("%d\n",ans);
    return 0;
}
