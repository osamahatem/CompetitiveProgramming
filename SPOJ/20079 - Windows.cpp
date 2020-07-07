#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,cur_x1,cur_x2,cur_y1,cur_y2,x1,x2,y1,y2;
    scanf("%d",&n);
    scanf("%d%d%d%d",&cur_x1,&cur_y1,&cur_x2,&cur_y2);
    for(int i=1;i<n;i++){
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        if(x1>cur_x2){
            printf("0\n");
            return 0;
        }
        if(y1>cur_y2){
            printf("0\n");
            return 0;
        }
        cur_x1=max(x1,cur_x1);
        cur_x2=min(x2,cur_x2);
        cur_y1=max(y1,cur_y1);
        cur_y2=min(y2,cur_y2);
    }
    printf("%d\n",(cur_y2-cur_y1)*(cur_x2-cur_x1));
    return 0;
}
