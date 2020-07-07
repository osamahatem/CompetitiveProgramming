#include<bits/stdc++.h>

using namespace std;

int n,m;
char levels[1005][15][15];

void scan(int i){
    for(int r=0;r<n;r++)
        scanf("%s",levels[i][r]);
    return;
}

int dif(int a,int b){
    int ret=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            ret+=(levels[a][i][j]!=levels[b][i][j]);
    return ret;
}

int main(){
    int k,w,ans[1005],globalMin=0;
    scanf("%d%d%d%d",&n,&m,&k,&w);
    for(int i=0;i<k;i++){
        scan(i);
        ans[i]=-1;
        int mini=n*m;
        for(int j=0;j<i;j++){
            int temp=w*dif(i,j);
            if(temp<mini){
                mini=temp;
                ans[i]=j;
            }
        }
        globalMin+=mini;
    }
    printf("%d\n",globalMin);
    for(int i=0;i<k;i++)
        printf("%d %d\n",i+1,ans[i]+1);
    return 0;
}
