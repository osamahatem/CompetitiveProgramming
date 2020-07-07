#include<cstdio>

long long choose[55][55];

long long nCr(int n,int r){
    if(r==0)
        return 1;
    if(r>n || r<0)
        return 0;
    return choose[n][r];
}

int main(){
    int i,j,needed=0;
    long long n,t,ans=0;
    for(i=1;i<=50;i++){
        for(j=1;j<=i;j++){
            if(j==1 || j==i)
                choose[i][j]=1;
            else
                choose[i][j]=choose[i-1][j]+choose[i-1][j-1];
        }
    }
    scanf("%I64d%I64d",&n,&t);
    n+=2;
    for(i=0;i<=50;i++){
        if((1LL<<i)==t){
            needed=i+1;
            break;
        }
    }
    if(!needed){
        printf("0\n");
        return 0;
    }
    if(t==1)
        ans--;
    for(i=50;i>=0 && needed>0;i--){
        if(n&(1LL<<i)){
            for(j=i;j>=needed;j--){
                ans+=nCr(j,needed);
                //printf("nCr(%d,%d)=%I64d\n",j,needed,nCr(j,needed));
            }
            needed--;
        }
    }
    if(!needed && i>=0)
        ans++;
    printf("%I64d\n",ans);
    return 0;
}
