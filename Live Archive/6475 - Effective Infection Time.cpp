#include<bits/stdc++.h>

using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
	#endif

    int t,sm,sy,tm,ty;
    double ans;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d%d",&sm,&sy,&tm,&ty);
        if(sy==ty)
            ans=0.5/(12-sm+1)*(tm-sm);
        else{
            ans=0.5;
            ans+=ty-sy-1;
            ans+=(tm-1)/12.0;
        }
        printf("%.4f\n",ans);
    }
	return 0;
}
