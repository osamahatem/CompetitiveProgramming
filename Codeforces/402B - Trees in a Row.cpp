#include<cstdio>
#include<algorithm>

using namespace std;

int main(){
    int n,k,arr[1005],mini=1<<30,mini_idx;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    for(int i=0;i<n;i++){
        if(arr[i]-i*k<=0)
            continue;
        int temp=0;
        for(int j=i-1;j>=0;j--)
            if(arr[j]!=arr[i]-(i-j)*k)
                temp++;
        for(int j=i+1;j<n;j++)
            if(arr[j]!=arr[i]+(j-i)*k)
                temp++;
        if(temp<mini){
            mini=temp;
            mini_idx=i;
        }
    }
    printf("%d\n",mini);
    for(int i=0;i<mini_idx;i++)
        if(arr[i]<arr[mini_idx]-(mini_idx-i)*k)
            printf("+ %d %d\n",i+1,arr[mini_idx]-(mini_idx-i)*k-arr[i]);
        else if(arr[i]>arr[mini_idx]-(mini_idx-i)*k)
            printf("- %d %d\n",i+1,arr[i]-(arr[mini_idx]-(mini_idx-i)*k));
    for(int i=mini_idx+1;i<n;i++)
        if(arr[i]<arr[mini_idx]+(i-mini_idx)*k)
            printf("+ %d %d\n",i+1,arr[mini_idx]+(i-mini_idx)*k-arr[i]);
        else if(arr[i]>arr[mini_idx]+(i-mini_idx)*k)
            printf("- %d %d\n",i+1,arr[i]-(arr[mini_idx]+(i-mini_idx)*k));
    return 0;
}
