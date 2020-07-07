#include<cstdio>
#include<cmath>
#include<algorithm>

using namespace std;

#define eps 1e-4

int main(){
    int n,i,c1=0,mini,maxi;
    double x,sum=0,ans=200000000;
    scanf("%d",&n);
    for(i=0;i<2*n;i++){
        scanf("%lf",&x);
        if(x-floor(x)>eps)
            c1++;
        sum+=x-floor(x);
    }
    mini=max(0,c1-n);
    maxi=min(n,c1);
    for(i=mini;i<=maxi;i++)
        ans=min(ans,fabs(sum-i));
    printf("%.3f\n",ans);
	return 0;
}
