#include<cstdio>

int main(){
    int n,m,i,y=0,t,v,x,q,arr[100000],incr[100000],temp;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
        incr[i]=0;
    }
    for(i=0;i<m;i++){
        scanf("%d",&t);
        if(t==1){
            scanf("%d%d",&v,&x);
            incr[v-1]=x-arr[v-1]-y;
        }
        if(t==2){
            scanf("%d",&temp);
            y+=temp;
        }
        if(t==3){
            scanf("%d",&q);
            printf("%d\n",arr[q-1]+y+incr[q-1]);
        }
    }
    return 0;
}
