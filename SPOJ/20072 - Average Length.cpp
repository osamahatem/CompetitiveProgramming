#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,k,u,v,w,dist[105][105];
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            dist[i][j]= (i==j) ? 0 : 1<<29;
    for(int i=0;i<k;i++){
        scanf("%d%d%d",&u,&v,&w);
        dist[u][v]=w;
    }
    for(k=1;k<=n;k++)
        for(u=1;u<=n;u++)
            for(v=1;v<=n;v++)
                dist[u][v]=min(dist[u][v],dist[u][k]+dist[k][v]);
    double avg=0.0;
    int c=0;
    for(u=1;u<=n;u++)
        for(v=1;v<=n;v++)
            if(u==v)
                continue;
            else if(dist[u][v]<(1<<29))
                avg+=dist[u][v],c++;
    avg/=c;
    printf("%.6f\n",avg);
    return 0;
}
