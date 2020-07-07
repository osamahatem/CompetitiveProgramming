#include<cstdio>

int gcd(int x,int y){
    if(y==0)
        return x;
    return gcd(y,x%y);
}

int lcm(int x,int y){
    return x*y/gcd(x,y);
}

int main(){
    int x,y,a,b;
    scanf("%d%d%d%d",&x,&y,&a,&b);
    int l=lcm(x,y);
    int ans=b/l-(a-1)/l;
    printf("%d\n",ans);
	return 0;
}
