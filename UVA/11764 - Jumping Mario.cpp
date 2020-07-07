#include<cstdio>

int main(){
    int t,T,n,hi,lo,cur,last;
    scanf("%d",&T);
    for(t=1;t<=T;t++){
        scanf("%d",&n);
        hi=0;
        lo=0;
        scanf("%d",&last);
        for(int i=0;i<n-1;i++){
            scanf("%d",&cur);
            if(cur>last)
                hi++;
            if(cur<last)
                lo++;
            last=cur;
        }
        printf("Case %d: %d %d\n",t,hi,lo);
    }
    return 0;
}
