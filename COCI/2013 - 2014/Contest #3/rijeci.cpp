#include<cstdio>

int main(){
    int k,a=1,b=0,tempa,tempb,i;
    scanf("%d",&k);
    for(i=0;i<k;i++){
        tempa=a,tempb=b;
        a=b=0;
        a=tempb;
        b=tempb+tempa;
    }
    printf("%d %d\n",a,b);
    return 0;
}
