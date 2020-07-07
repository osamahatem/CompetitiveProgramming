#include<stdio.h>
#include<math.h>

#define eps 1e-9

int main(){
    int t,i;
    double r,b,m,temp;
    scanf("%d",&t);

    while(t--){
        scanf("%lf%lf%lf",&r,&b,&m);
        r/=100.0;

        for(i=1;i<=1200;i++){
            temp=b*r;
            temp*=100.0;
            temp=floor(temp+0.5+eps);
            temp/=100.0;
            /*printf("%3d => %f %f %f\n",i,b,temp,b+temp);*/
            b+=temp-m;
            if(b-0.0<eps)
                break;
        }

        if(i>1200)
            printf("impossible\n");
        else
            printf("%d\n",i);
    }
    return 0;
}
