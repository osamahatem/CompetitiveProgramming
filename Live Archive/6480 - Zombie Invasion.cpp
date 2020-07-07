#include<bits/stdc++.h>

using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
	#endif

    int t,arr[20];
    scanf("%d",&t);
    while(t--){
        for(int i=0;i<20;i++)
            scanf("%d",&arr[i]);
        for(int i=20;i>0;i--)
            for(int j=1;j<i;j++)
                arr[j-1]+=arr[j]/2,arr[j]%=2;
        for(int i=0;i<20;i++)
            printf("%d%c",arr[i]," \n"[i==19]);
    }
	return 0;
}
