#include<cstdio>

int gcd(int x,int y){
    if(y==0)
        return x;
    return gcd(y,x%y);
}

int main(){
    int n,i,j,sum;
    while(1){
        scanf("%d",&n);
        if(n==0)
            break;
        sum=0;
        for(i=1;i<n;i++)
            for(j=i+1;j<=n;j++)
                sum+=gcd(i,j);
        printf("%d\n",sum);
    }
    return 0;
}
