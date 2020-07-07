#include<cstdio>

int main(){
    int n;
    while(scanf("%d",&n)!=EOF)
        if(n%6)
            printf("N\n");
        else
            printf("Y\n");
	return 0;
}
