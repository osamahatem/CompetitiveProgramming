#include<cstdio>
#include<cmath>

int main(){
    int h,m;
    float angle;
    while(1){
        scanf("%d:%d",&h,&m);
        if(h==0 && m==0)
            break;
        h%=12;
        angle=fabs(h*30+m/2.0-m*6);
        if(angle>180)
            angle=360-angle;
        printf("%.3f\n",angle);
    }
    return 0;
}
