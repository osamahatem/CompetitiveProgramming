#include<cstdio>

int main(){
    int n,can_be_used=0,i,x,y,sum_up=0,sum_down=0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d%d",&x,&y);
        sum_up+=x;
        sum_down+=y;
        if((x%2==1 && y%2==0) || (x%2==0 && y%2==1))
            can_be_used++;
    }
    if(sum_up%2==0 && sum_down%2==0)
        printf("0\n");
    else if(can_be_used>0 && sum_up%2==1 && sum_down%2==1)
        printf("1\n");
    else
        printf("-1\n");
	return 0;
}
