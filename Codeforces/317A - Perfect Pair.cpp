#include<cstdio>
#include<cstdlib>
#include<algorithm>

using namespace std;

int main(){
    long long x,y,m,mini=0;
    scanf("%I64d%I64d%I64d",&x,&y,&m);
    if(x>=m || y>=m) printf("0\n");
    else if(x<=0 && y<=0) printf("-1\n");
    else{
        if(x<0 || y<0){
            mini+=abs(x-y)/max(x,y);
            if(x==min(x,y))
                x+=abs(x-y)/max(x,y)*max(x,y);
            else
                y+=abs(x-y)/max(x,y)*max(x,y);
        }
        while(x<m && y<m){
            if(x==min(x,y))
                x+=y;
            else
                y+=x;
            mini++;
        }
        printf("%I64d\n",mini);
    }
    return 0;
}
