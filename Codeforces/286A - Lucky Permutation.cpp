#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,arr[100005];
    scanf("%d",&n);
    if(n%4==0 || n%4==1){
        if(n%2==1)
            arr[n/2]=n/2+1;
        int inc=n-2,cur=1,flag=1;
        for(int i=n/2+n%2;i<n;i++){
            arr[i]=cur;
            arr[n-i-1]=n+1-cur;
            cur+=inc*flag;
            inc-=2;
            flag*=-1;
        }
        for(int i=0;i<n;i++){
            if(i>0)
                printf(" ");
            printf("%d",arr[i]);
        }
    }else
        printf("-1");
    printf("\n");
    return 0;
}
