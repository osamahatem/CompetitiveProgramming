#include<cstdio>

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,k;
        double e[1001];
        scanf("%d",&n);
        e[n]=0;
        for(k=n-1;k>=0;k--)
            e[k]=((double)n/(n-k))+e[k+1];
        printf("%.2f\n",e[0]);
    }
	return 0;
}
