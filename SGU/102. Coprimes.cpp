#include<cstdio>

int gcd(int a,int b){
    if(b==0)
        return a;
    return gcd(b,a%b);
}

int main(){
    int n,i,ans=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        if(gcd(i,n)==1)
            ans++;
    printf("%d\n",ans);
    return 0;
}
