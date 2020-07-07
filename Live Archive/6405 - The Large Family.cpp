#include<bits/stdc++.h>

using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
	#endif

    int n;
    while(scanf("%d",&n),n){
        n*=2;
        double g=0,d=n/7,m=n/7,c=n/7;
        n%=7;
        if(n>=5){
            c++;
            n-=5;
        }else if(n>=2){
            d++;
            m++;
            n-=2;
        }
        g+=n;
        g/=2;
        d/=2;
        m/=2;
        c/=2;
        printf("%.1f %.1f %.1f %.1f\n",g,d,m,c);
    }
	return 0;
}
