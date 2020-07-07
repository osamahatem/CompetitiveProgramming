#include<cstdio>

int main(){
    int i,k;
    long long fib[50],sum=0;
    fib[0]=fib[1]=1;
    scanf("%d",&k);
    for(i=2;i<k;i++)
        fib[i]=fib[i-1]+fib[i-2];
    for(i=0;i<k;i++)
        sum+=fib[i];
    printf("%lld\n",sum);
    return 0;
}
