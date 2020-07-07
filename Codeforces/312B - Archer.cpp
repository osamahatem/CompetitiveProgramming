#include<cstdio>

int main(){
    double a,b,c,d,p1,p2,prop;
    scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
    p1=b/a;
    p2=d/c;
    prop=p2/(p1+p2-1);
    printf("%.12lf\n",prop);
    return 0;
}
