#include<cstdio>

int main(){
    int x,y,n;
    bool flag=0;
    while(1){
        scanf("%d",&n);
        if(n==0)
            break;
        flag=0;
        for(x=2;x<=58;x++){
            for(y=1;y<x;y++){
                if(x*x*x-y*y*y==n){
                    flag=1;
                    break;
                }
            }
            if(flag) break;
        }
        if(flag) printf("%d %d\n",x,y);
        else printf("No solution\n");
    }
    return 0;
}
