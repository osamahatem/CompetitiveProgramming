#include<cstdio>
#include<cmath>

int main(){
    long long n,i,k,len,temp;
    scanf("%lld",&n);
    while(n--){
        scanf("%lld",&k);
        temp=k+1;
        len=0;
        while(temp/2!=0){
            len++;
            temp/=2;
        }
        temp=1;
        for(i=0;i<len;i++){
            temp*=2;
        }
        k-=temp-1;
        temp/=2;
        while(len--){
            if(k>=temp){
                printf("6");
                k-=temp;
            }
            else printf("5");
            temp/=2;
        }
        printf("\n");
    }
    return 0;
}
