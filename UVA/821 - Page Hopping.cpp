#include<bits/stdc++.h>

using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
	#endif

    int tc=0,a,b,dist[101][101],N;
    while(scanf("%d%d",&a,&b),a){
        memset(dist,0x3f,sizeof dist);
        N=1;
        N=max(N,max(a,b)),dist[a][b]=1;
        while(scanf("%d%d",&a,&b),a)
            N=max(N,max(a,b)),dist[a][b]=1;

        for(int k=1;k<=N;k++)
            for(int i=1;i<=N;i++)
                for(int j=1;j<=N;j++)
                    dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);

        double sum=0.0;
        int c=0;
        for(int i=1;i<=N;i++)
            for(int j=1;j<=N;j++)
                if(dist[i][j]<=N && i!=j)
                    sum+=dist[i][j],c++;
        printf("Case %d: average length between pages = %.3f clicks\n",++tc,sum/c);
    }
	return 0;
}
