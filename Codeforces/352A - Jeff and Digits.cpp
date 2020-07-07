#include<cstdio>

int main(){
    int n,c0=0,c5=0,i,x;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&x);
        if(x==5)
            c5++;
        else
            c0++;
    }
    c5/=9;
    if(c0==0)
        printf("-1\n");
    else if(c5==0)
        printf("0\n");
    else{
        for(i=0;i<c5;i++)
            printf("555555555");
        for(i=0;i<c0;i++)
            printf("0");
        printf("\n");
    }
	return 0;
}
