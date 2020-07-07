#include<cstdio>
#include<cmath>

int main(){
    int n,l;
    while(scanf("%d",&n)!=EOF){
        l=floor(log2(n))+1;
        printf("%d\n",l);
    }
    return 0;
}
