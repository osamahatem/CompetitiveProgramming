#include<bits/stdc++.h>

using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
	#endif

    int T,n,m,inM[5005],inN[10005];
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        memset(inM,0,sizeof inM);
        memset(inN,0,sizeof inN);
        scanf("%d%d",&m,&n);
        int temp=m;
        for(int i=2;i<=temp/i;i++){
            while(temp%i==0){
                inM[i]++;
                temp/=i;
            }
        }
        inM[temp]++;
        for(int i=2;i<=n;i++){
            temp=i;
            for(int j=2;j<=temp/j;j++){
                while(temp%j==0){
                    inN[j]++;
                    temp/=j;
                }
            }
            inN[temp]++;
        }
        int ans=(1<<30);
        bool imp=0;
        for(int i=2;i<=m;i++){
            if(inM[i]>inN[i]){
                imp=1;
                break;
            }
            if(!inM[i])
                continue;
            ans=min(ans,inN[i]/inM[i]);
        }
        printf("Case %d:\n",t);
        if(imp)
            puts("Impossible to divide");
        else
            printf("%d\n",ans);
    }
	return 0;
}
