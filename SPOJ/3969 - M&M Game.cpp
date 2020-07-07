#include<cstdio>

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,i,x,ans=0,one_count=0;
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%d",&x);
            ans^=x;
            if(x==1)
                one_count++;
        }
        if(one_count==n)
            if(n%2)
                ans=0;
            else
                ans=1;
        if(ans)
            printf("John\n");
        else
            printf("Brother\n");
    }
	return 0;
}
