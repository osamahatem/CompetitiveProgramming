#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,m,mat[105][105];
    scanf("%d%d",&n,&m);
    int ans=n;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            scanf("%d",&mat[i][j]);
    while(ans%2==0){
        bool flag=0;
        int mid=ans/2;
        for(int i=0;i<mid;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]!=mat[ans-1-i][j]){
                    flag=1;
                    break;
                }
            }
            if(flag)
                break;
        }
        if(flag)
            break;
        ans/=2;
    }
    printf("%d\n",ans);
    return 0;
}
