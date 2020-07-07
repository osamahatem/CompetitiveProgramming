#include<cstdio>

int main(){
    int t,n;
    double ans;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        ans=0;
        double temp=0.45;
        for(int i=0;i<12;i++){
            ans+=temp*n;
            n--;
            temp/=10;
            if(n==0)
                break;
        }
        printf("%.12f\n",ans);
    }
    return 0;
}
