#include<cstdio>
#include<algorithm>

using namespace std;

int main(){
    int n,iq[100000],mini[100000],t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d",&iq[i]);
        int temp=1000000;
        for(int i=n-1;i>=0;i--){
            temp=min(iq[i],temp);
            mini[i]=temp;
        }
        temp=-1000000;
        for(int i=0;i<n-1;i++)
            temp=max(temp,iq[i]-mini[i+1]);
        printf("%d\n",temp);
    }
    return 0;
}
