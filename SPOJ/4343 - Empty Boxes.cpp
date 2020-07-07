#include<cstdio>

int main(){
    int tc;
    scanf("%d",&tc);
    while(tc--){
        int n,k,t,f;
        scanf("%d%d%d%d",&n,&k,&t,&f);
        printf("%d\n",(f-n)/(k-1)+f);
    }
	return 0;
}
