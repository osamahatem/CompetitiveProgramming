#include<cstdio>

int main(){
    int n,m,k,t,ans=0;
    scanf("%d%d%d",&n,&m,&k);
    while(n--){
        scanf("%d",&t);
        if(t==1){
            if(m==0)
                ans++;
            else
                m--;
        }else{
            if(m==0 && k==0)
                ans++;
            else if(k>0)
                k--;
            else
                m--;
        }
    }
    printf("%d\n",ans);
    return 0;
}
