#include<cstdio>
#include<algorithm>

using namespace std;

int main(){
    int x,y,ans;
    scanf("%d%d",&x,&y);
    ans=min(x,y)+1;
    printf("%d\n",ans);
    for(int i=0;i<ans;i++)
        printf("%d %d\n",i,ans-i-1);
    return 0;
}
