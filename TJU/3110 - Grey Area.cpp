#include<cstdio>
#include<cmath>
#include<algorithm>

using namespace std;

int main(){
    int n,w,v,i;
    double interval[15],cost,maxi,maxh;
    while(scanf("%d%d",&n,&w),n!=0){
        cost=0.01;
        maxi=0,maxh=0;
        for(i=0;i<15;i++)
            interval[i]=0;
        for(i=0;i<n;i++){
            scanf("%d",&v);
            interval[v/w]++;
            maxi=max(maxi,floor((double)v/w+0.5));
            maxh=max(maxh,interval[v/w]);
        }
        i=(int)floor(maxi+0.5);
        while(i>0){
            printf("%d %f\n",(int)floor(maxi+0.5)-i,interval[(int)floor(maxi+0.5)-i]);
            cost+=interval[(int)floor(maxi+0.5)-i]/maxh*i/maxi;
            i--;
        }
        printf("%.16g\n",cost);
    }
	return 0;
}
