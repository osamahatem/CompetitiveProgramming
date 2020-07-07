#include<cstdio>
#include<algorithm>

using namespace std;

int main(){
    int n,k,i,j,c,arr[55];
    scanf("%d%d",&n,&k);
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    sort(arr,arr+n);
    i=n;
    j=n-1;
    while(k--){
        printf("%d",n-i+1);
        for(c=n-1;c>=i;c--)
            printf(" %d",arr[c]);
        printf(" %d",arr[j]);
        printf("\n");
        j--;
        if(j<0){
            i--;
            j=i-1;
        }
    }
    return 0;
}
