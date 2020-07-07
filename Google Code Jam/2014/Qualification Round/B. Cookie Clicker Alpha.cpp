#include<bits/stdc++.h>

using namespace std;

int main(){
    freopen("B. Cookie Clicker Alpha.in","r",stdin);
    freopen("B. Cookie Clicker Alpha.out","w",stdout);
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        printf("Case #%d: ",t);
        double c,f,x,rate=2.0,time=0.0;
        scanf("%lf%lf%lf",&c,&f,&x);
        while(1){
            if(c/rate+x/(rate+f)>x/rate){
                time+=x/rate;
                break;
            }
            time+=c/rate;
            rate+=f;
        }
        printf("%.7f\n",time);
    }
    return 0;
}
