#include<cstdio>

int gcd(int x,int y){
    if(y==0) return x;
    return gcd(y,x%y);
}

int main(){
    int i,j,n,m,tickets[10000],total,g;
    while(1){
        scanf("%d%d",&n,&m);
        if(n==0 && m==0)
            break;
        total=0;
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                scanf("%d",&tickets[i]);
                if(j==m-1)
                    total+=tickets[i];
            }
        }
        for(i=0;i<n;i++){
            g=gcd(tickets[i],total);
            printf("%d / %d\n",tickets[i]/g,total/g);
        }
    }
    return 0;
}
