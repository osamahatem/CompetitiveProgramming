#include<cstdio>
#include<cstring>

int main(){
    int n,last[100001],dif[100001],i,x,c=0;
    memset(last,-1,sizeof last);
    memset(dif,-1,sizeof dif);
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&x);
        if(last[x]==-2)
            continue;
        if(last[x]==-1){
            c++;
            last[x]=i;
        }else if(dif[x]==-1){
            dif[x]=i-last[x];
            last[x]=i;
        }else if(dif[x]!=i-last[x]){
            last[x]=-2;
            c--;
        }else
            last[x]=i;
    }
    printf("%d\n",c);
    for(i=1;i<=100000;i++){
        if(last[i]>=0){
            printf("%d ",i);
            if(dif[i]==-1)
                printf("0\n");
            else
                printf("%d\n",dif[i]);
        }
    }
	return 0;
}
