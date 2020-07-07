#include<cstdio>
#include<cmath>

int main(){
    unsigned long long n;
    while(1){
        scanf("%llu",&n);
        if(n==0)
            break;
        n=n*10/9;
        if(n%10==0)
            printf("%llu %llu\n",n-1,n);
        else
            printf("%llu\n",n);
    }
    return 0;
}
