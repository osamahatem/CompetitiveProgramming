#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,k,score[1005];
    memset(score,0,sizeof score);
    scanf("%d%d",&n,&k);
    if(k>(n-1)/2){
        printf("-1\n");
        return 0;
    }
    printf("%d\n",n*k);
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(score[i]==k && score[j]==k)
                continue;
            if(score[i]<k){
                score[i]++;
                printf("%d %d\n",i,j);
            }else{
                score[j]++;
                printf("%d %d\n",j,i);
            }
        }
    }
    return 0;
}
