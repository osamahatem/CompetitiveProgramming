#include<cstdio>

int main(){
    int n,birds[100],i,m,x,y;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&birds[i]);
    scanf("%d",&m);
    for(i=0;i<m;i++){
        scanf("%d%d",&x,&y);
        x--;
        if(x)
            birds[x-1]+=y-1;
        if(x<n-1)
            birds[x+1]+=birds[x]-y;
        birds[x]=0;
    }
    for(i=0;i<n;i++)
        printf("%d\n",birds[i]);
    return 0;
}
