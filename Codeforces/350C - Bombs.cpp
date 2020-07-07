#include<cstdio>
#include<cstdlib>
#include<algorithm>

using namespace std;

typedef struct coor{
    int x,y;
}coor;

bool cmp(const coor &a,const coor &b){
    if(abs(a.x)!=abs(b.x))
        return abs(a.x)<abs(b.x);
    return abs(a.y)<abs(b.y);
}

int main(){
    int n,i,k=0;
    coor in[100000];
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d%d",&in[i].x,&in[i].y);
        k+=2+2*(bool)(abs(in[i].x)>0)+2*(bool)(abs(in[i].y)>0);
    }
    sort(in,in+n,cmp);
    printf("%d\n",k);
    for(i=0;i<n;i++){
        if(abs(in[i].x)>0){
            printf("1 %d ",abs(in[i].x));
            if(in[i].x>0)
                printf("R\n");
            else
                printf("L\n");
        }
        if(abs(in[i].y)>0){
            printf("1 %d ",abs(in[i].y));
            if(in[i].y>0)
                printf("U\n");
            else
                printf("D\n");
        }
        printf("2\n");
        if(abs(in[i].x)>0){
            printf("1 %d ",abs(in[i].x));
            if(in[i].x>0)
                printf("L\n");
            else
                printf("R\n");
        }
        if(abs(in[i].y)>0){
            printf("1 %d ",abs(in[i].y));
            if(in[i].y>0)
                printf("D\n");
            else
                printf("U\n");
        }
        printf("3\n");
    }
	return 0;
}
