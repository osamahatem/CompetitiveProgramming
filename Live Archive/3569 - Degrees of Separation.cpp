#include<cstdio>
#include<map>
#include<string>

using namespace std;

int main(){
    int p,r,k,i,j,dist[55][55],t=1;
    char x[105],y[105];
    while(1){
        scanf("%d%d",&p,&r);
        if(p==0 && r==0)
            break;
        for(i=0;i<p;i++){
            for(j=0;j<p;j++)
                dist[i][j]=1<<29;
            dist[i][i]=0;
        }
        map<string,int> rnk;
        int idx=0;

        for(i=0;i<r;i++){
            scanf("%s%s",x,y);
            if(!rnk.count((string)x))
                rnk[(string)x]=idx++;
            if(!rnk.count((string)y))
                rnk[(string)y]=idx++;

            dist[rnk[(string)x]][rnk[(string)y]]=1;
            dist[rnk[(string)y]][rnk[(string)x]]=1;
        }

        for(k=0;k<p;k++)
            for(i=0;i<p;i++)
                for(j=0;j<p;j++)
                    dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);

        int maxi=0;
        for(i=0;i<p;i++)
            for(j=0;j<p;j++)
                maxi=max(maxi,dist[i][j]);

        printf("Network %d: ",t++);
        if(maxi==(1<<29))
            printf("DISCONNECTED");
        else
            printf("%d",maxi);
        printf("\n\n");
    }
    return 0;
}
