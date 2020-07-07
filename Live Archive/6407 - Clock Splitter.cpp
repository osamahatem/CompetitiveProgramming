#include<bits/stdc++.h>

using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
	#endif

    long long n;
    while(scanf("%lld",&n),n){
        long long a=1,b=1,tot=n*(n+1)/2;
        long long mini=n*(n+1)/2,mini_s=1,mini_e=1;
        for(;a<=n;a++){
            long long temp=mini,last=tot;
            for(;b<=n;b++){
                long long temp=((b*(b+1)/2)-(a*(a-1)/2));
                if(llabs(tot-2*temp)>last){
                    b--;
                    break;
                }
                last=llabs(tot-2*temp);
                if(last<mini){
                    mini=last;
                    mini_s=a;
                    mini_e=b;
                }
            }
        }
        printf("%lld %lld\n",mini_s,mini_e);
    }
	return 0;
}
