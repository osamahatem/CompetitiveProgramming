#include<bits/stdc++.h>

using namespace std;

char ans[2010][1005];

int main(){
    int n,a,c=0,r=1000,ends[2010];
    memset(ans,' ',sizeof ans);
    memset(ends,-1,sizeof ends);
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a);
        char x='/';
        int inc=-1;
        if(i%2){
            x='\\';
            inc=1;
        }
        for(int j=0;j<a;j++){
            if(j>0)
                r+=inc;
            ans[r][c]=x;
            ends[r]=++c;
        }
    }
    for(int i=0;i<2005;i++){
        if(ends[i]==-1)
            continue;
        for(int j=0;j<c;j++)
            printf("%c",ans[i][j]);
        printf("\n");
    }
    return 0;
}
