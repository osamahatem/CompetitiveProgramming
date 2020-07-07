#include<cstdio>
#include<cstdlib>

int main(){
    int x,y,x1,x2=0,y1=0,y2;
    scanf("%d%d",&x,&y);
    x1=abs(x)+abs(y);
    y2=abs(x)+abs(y);
    if(x<0)
        x1*=-1;
    if(y<0)
        y2*=-1;
    if(x1<x2)
        printf("%d %d %d %d\n",x1,y1,x2,y2);
    else
        printf("%d %d %d %d\n",x2,y2,x1,y1);
	return 0;
}
