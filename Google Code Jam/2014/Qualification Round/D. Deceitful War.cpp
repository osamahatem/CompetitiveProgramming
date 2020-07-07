#include<bits/stdc++.h>

using namespace std;

int main(){
    freopen("D. Deceitful War.in","r",stdin);
    freopen("D. Deceitful War.out","w",stdout);
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        printf("Case #%d: ",t);
        int n,x=0,y=0;
        double first[1005],second[1005];
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%lf",&first[i]);
        for(int i=0;i<n;i++)
            scanf("%lf",&second[i]);
        sort(first,first+n);
        sort(second,second+n);
        int j=0;
        for(int i=0;i<n;i++){
            if(first[i]>second[j]){
                x++;
                j++;
            }
        }
        j=n-1;
        for(int i=n-1;i>=0;i--){
            while(first[j]>second[i] && j>=0){
                y++;
                j--;
            }
            j--;
        }
        printf("%d %d\n",x,y);
    }
    return 0;
}
