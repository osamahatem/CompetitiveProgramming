#include<bits/stdc++.h>

using namespace std;

#define EPS 1e-15

int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
	#endif

    long long x,y,n,minA,minB;
    scanf("%I64d%I64d%I64d",&x,&y,&n);
    double orig=(double)x/y,mini=orig*2.0;
    for(long long b=1;b<=n;b++){
        long long a=x*b/y;
        if(fabs(((double)a/b)-orig)+EPS<mini){
            mini=fabs(((double)a/b)-orig);
            minA=a;
            minB=b;
        }
        a++;
        if(fabs(((double)a/b)-orig)+EPS<mini){
            mini=fabs(((double)a/b)-orig);
            minA=a;
            minB=b;
        }
    }
    printf("%I64d/%I64d\n",minA,minB);
	return 0;
}
