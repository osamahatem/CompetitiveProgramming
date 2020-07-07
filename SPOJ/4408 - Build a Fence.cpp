#include<cstdio>

#define pi 3.14159265359

int main(){
    double l;
    while(1){
        scanf("%lf",&l);
        if(l==0)
            break;
        l/=2*pi;
        printf("%.2f\n",l);
    }
}
