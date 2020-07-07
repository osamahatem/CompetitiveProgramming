#include<cstdio>

int main(){
    int a,k,ans,ex;
    while(scanf("%d%d",&a,&k)!=EOF){
        ans=ex=0;
        while(a){
            ans+=a;
            ex+=a%k;
            a/=k;
            a+=ex/k;
            ex%=k;
        }
        printf("%d\n",ans);
    }
    return 0;
}
