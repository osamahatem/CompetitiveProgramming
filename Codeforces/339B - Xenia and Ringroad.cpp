#include<cstdio>

int main(){
    int n,m,last=1,x,i;
    long long ans=0;
    scanf("%d%d",&n,&m);
    for(i=0;i<m;i++){
        scanf("%d",&x);
        int temp=x-last;
        ans+=temp;
        if(temp<0)
            ans+=n;
        last=x;
    }
    printf("%I64d\n",ans);
	return 0;
}
