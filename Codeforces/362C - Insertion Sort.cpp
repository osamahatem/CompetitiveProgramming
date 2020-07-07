#include<cstdio>
#include<algorithm>

using namespace std;

int main(){
    int n,i,j,arr[5000],mini,def=0,cnt=0,temp;

    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
        def+=max(0,i-arr[i]);
    }

    mini=def;
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            temp=def-max(0,i-arr[i])-max(0,j-arr[j]);
            temp+=max(0,i-arr[j])+max(0,j-arr[i]);
            if(temp<mini){
                mini=temp;
                cnt=1;
            }else if(temp==mini)
                cnt++;
        }
    }

    printf("%d %d\n",mini,cnt);

    return 0;
}
