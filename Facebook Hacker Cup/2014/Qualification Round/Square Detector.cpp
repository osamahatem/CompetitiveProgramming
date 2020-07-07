#include<cstdio>

int main(){
    freopen("Square Detector.in","r",stdin);
    freopen("Square Detector.out","w",stdout);
    int t=0,T,n,i,j,stx,sty,edx,edy,cntb,cntw;
    char g[23][23];
    bool flag;
    scanf("%d",&T);
    while(t<T){
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%s",g[i]);

        flag=0,cntb=0,cntw=0;
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if(g[i][j]=='#'){
                    cntb++;
                    edx=i;
                    edy=j;
                    if(!flag){
                        stx=i;
                        sty=j;
                        flag=1;
                    }
                }
            }
        }

        for(i=stx;i<=edx;i++)
            for(j=sty;j<=edy;j++)
                if(g[i][j]=='#')
                    cntb--;
                else
                    cntw++;

        printf("Case %d: ",++t);
        if(cntb==0 && cntw==0 && edx-stx==edy-sty)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
