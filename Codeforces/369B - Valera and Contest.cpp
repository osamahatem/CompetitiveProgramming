#include<cstdio>
#include<algorithm>

using namespace std;

int main(){
    int n,k,l,r,sa,sk,arr[1005],i;
    scanf("%d%d%d%d%d%d",&n,&k,&l,&r,&sa,&sk);
    for(i=0;i<n;i++)
        arr[i]=0;
    for(i=0;i<k;i++)
        arr[i]=sk/k;
    int temp=sk%k;i=0;
    while(temp--)
        arr[i++]++;
    sa-=sk;
    for(i=k;i<n;i++)
        arr[i]+=sa/(n-k);
    if(n-k>0){
        temp=sa%(n-k);i=k;
        while(temp--)
            arr[i++]++;
    }
    for(i=0;i<n;i++){
        if(i>0)
            printf(" ");
        printf("%d",arr[i]);
    }
    printf("\n");
    return 0;
}
