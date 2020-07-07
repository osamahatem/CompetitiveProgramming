#include<cstdio>

int gcd(int x,int y){
    if(y==0) return x;
    return gcd(y,x%y);
}

int main(){
    int a,b,c,d,e,f,temp;
    double first,second;
    bool flag=0;
    scanf("%d%d%d%d",&a,&b,&c,&d);
    first=(double)a/b;
    second=(double)c/d;
    if(first<second)
        flag=1;
    if(flag){
        e=a*d;
        f=b*c;
    }else{
        e=c*b;
        f=a*d;
    }
    temp=gcd(e,f);
    e/=temp;
    f/=temp;
    printf("%d/%d\n",f-e,f);
	return 0;
}
