#include<cstdio>

int main(){
    int n,x,y,i;
    bool flag;
    char last;
    scanf("%d",&n);
    printf("Lumberjacks:\n");
    while(n--){
        flag=0;
        scanf("%d%d",&x,&y);
        if(x<y){
            for(i=0;i<8;i++){
                x=y;
                scanf("%d",&y);
                if(y<x){
                    flag=1;
                }
            }
        }else{
            for(i=0;i<8;i++){
                x=y;
                scanf("%d",&y);
                if(x<y){
                    flag=1;
                }
            }
        }
        if(flag)
            printf("Unordered\n");
        else
            printf("Ordered\n");
    }
    return 0;
}
