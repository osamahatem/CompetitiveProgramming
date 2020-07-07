#include<cstdio>
#include<cmath>

#define eps 1e-9

int main(){
    double y1,y2,yw,xb,yb,r;
    scanf("%lf%lf%lf%lf%lf%lf",&y1,&y2,&yw,&xb,&yb,&r);
    yw-=r;
    y2-=r;
    y1+=r;
    double lo=0.0,hi=xb,mid,ans,cross;
    while(lo+eps<hi){
        mid=(lo+hi)/2.0;
        ans=mid*(yw-yb)/(xb-mid);
        ans=yw-ans;
        cross=mid*(y2+r-ans);
        cross/=sqrt(mid*mid+(yw-ans)*(yw-ans));
        if(ans-eps<y2 && ans+eps>y1 && cross>r){
            printf("%.10f\n",mid);
            return 0;
        }
        if(ans<y1)
            hi=mid-eps;
        else
            lo=mid+eps;
    }
    printf("-1\n");
    return 0;
}
