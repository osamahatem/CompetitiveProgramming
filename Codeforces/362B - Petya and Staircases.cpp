#include<cstdio>
#include<algorithm>

using namespace std;

int main(){
    int n,m,i,arr[3010],cnt=0;
    scanf("%d%d",&n,&m);
    for(i=0;i<m;i++)
        scanf("%d",&arr[i]);
    sort(arr,arr+m);
    if(arr[0]==1 || arr[m-1]==n){
        printf("NO\n");
        return 0;
    }
    for(i=1;i<m;i++){
        if(arr[i]-arr[i-1]==1)
            cnt++;
        else
            cnt=0;
        if(cnt==2
           ){
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
    return 0;
}
