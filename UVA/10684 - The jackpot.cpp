#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    while(scanf("%d",&n),n){
        int max_here=0,max_so_far=0,x;
        for(int i=0;i<n;i++){
            scanf("%d",&x);
            max_here=max(0,max_here+x);
            max_so_far=max(max_so_far,max_here);
        }
        if(max_so_far>0)
            printf("The maximum winning streak is %d.\n",max_so_far);
        else
            printf("Losing streak.\n");
    }
    return 0;
}
