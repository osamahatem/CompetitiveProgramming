#include<cstdio>

int main(){
    int n,out;
    scanf("%d",&n);
    if(n>=0) out=n;
    else if(n%10<n%100/10) out=n/10;
    else out=n/100*10+n%10;
    printf("%d\n",out);
    return 0;
}
