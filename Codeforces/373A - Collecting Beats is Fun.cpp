#include<cstdio>
#include<cstring>

int main(){
    int c[10],k,i,j;
    char g[5][5];
    memset(c,0,sizeof c);
    scanf("%d",&k);
    k*=2;
    for(i=0;i<4;i++)
        scanf("%s",g[i]);
    for(i=0;i<4;i++)
        for(j=0;j<4;j++)
            if(g[i][j]!='.')
                c[g[i][j]-'0']++;
    for(i=0;i<10;i++){
        if(c[i]>k){
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
    return 0;
}
