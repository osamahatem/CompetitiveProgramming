#include<cstdio>

int main(){
    long long n,p[38],i,temp=1;
    bool canuse[38];
    for(i=0;i<38;i++)
        canuse[i]=1;
    for(i=0;i<38;i++){
        p[i]=temp;
        temp*=3;
    }
    scanf("%I64d",&n);
    for(i=0;i<38;i++)
        if(n%p[i]==0){
            canuse[i]=0;
        }
    i=0;
    while(!canuse[i++]);
    printf("%I64d\n",n/p[i-1]+1);
    return 0;
}
