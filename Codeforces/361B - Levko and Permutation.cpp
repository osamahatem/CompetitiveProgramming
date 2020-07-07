#include<cstdio>
#include<vector>

using namespace std;

int main(){
    int n,k,i,cur_k;
    vector<int> arr;
    scanf("%d%d",&n,&k);

    if(k==n){
        printf("-1\n");
        return 0;
    }

    for(i=1;i<=n;i++)
        arr.push_back(i);
    cur_k=n-1;

    i=1;
    while(cur_k>k+1){
        swap(arr[i],arr[i+1]);
        cur_k-=2;
        i+=2;
    }
    if(cur_k==k+1)
        swap(arr[0],arr[n-1]);

    for(i=0;i<n;i++){
        if(i>0)
            printf(" ");
        printf("%d",arr[i]);
    }
    printf("\n");

    return 0;
}
