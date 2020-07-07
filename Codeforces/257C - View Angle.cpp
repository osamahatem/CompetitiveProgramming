#include<cstdio>
#include<cmath>
#include<algorithm>

using namespace std;

const double PI=acos(-1.0);

int main(){
    int n,i;
    double mini=360.0,all[100005],x,y;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%lf%lf",&x,&y);
        all[i]=atan2(y,x);
    }
    sort(all,all+n);
    all[n]=all[0]+2*PI;
    for(i=0;i<n;i++)
        mini=min(mini,2*PI-all[i+1]+all[i]);
    mini*=180.0/PI;
    printf("%.10lf\n",mini);
    return 0;
}
