#include<bits/stdc++.h>

using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
	#endif

    int n,t=0;
    while(scanf("%d",&n),n>0){
        double sum_mass=0,sum_x=0,sum_y=0,x,y,m;
        while(n--){
            scanf("%lf%lf%lf",&x,&y,&m);
            sum_x+=x*m,sum_y+=y*m,sum_mass+=m;
        }
        printf("Case %d: %.2f %.2f\n",++t,sum_x/sum_mass,sum_y/sum_mass);
    }
	return 0;
}
