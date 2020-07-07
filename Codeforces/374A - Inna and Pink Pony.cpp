#include<cstdio>
#include<cstdlib>
#include<algorithm>

using namespace std;

int check(int a,int b,int i,int j,int x,int y){
    int dx=abs(a-i),dy=abs(b-j);
    if(dx%x || dy%y)
        return 1<<30;
    dx/=x;
    dy/=y;
    if(dx%2!=dy%2)
        return 1<<30;
    return max(dx,dy);
}

int main(){
    int n,m,i,j,a,b,ret=1<<30;
    scanf("%d%d%d%d%d%d",&n,&m,&i,&j,&a,&b);
    ret=min(ret,check(1,1,i,j,a,b));
    ret=min(ret,check(1,m,i,j,a,b));
    ret=min(ret,check(n,1,i,j,a,b));
    ret=min(ret,check(n,m,i,j,a,b));
    if(ret==1<<30)
        printf("Poor Inna and pony!\n");
    else
        printf("%d\n",ret);
    return 0;
}
