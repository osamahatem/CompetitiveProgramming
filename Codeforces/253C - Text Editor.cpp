#include<cstdio>
#include<cstdlib>
#include<algorithm>

using namespace std;

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,line[105],r1,c1,r2,c2,i,c,ans;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf("%d",&line[i]);
    scanf("%d%d%d%d",&r1,&c1,&r2,&c2);
    if(r1==r2){
        ans=abs(c1-c2);
        c=c1;
        for(i=r1;i<=n;i++){
            c=min(c,line[i]+1);
            ans=min(ans,2*abs(r1-i)+abs(c-c2));
        }
        c=c1;
        for(i=r1;i>0;i--){
            c=min(c,line[i]+1);
            ans=min(ans,2*abs(r1-i)+abs(c-c2));
        }
        printf("%d\n",ans);
        return 0;
    }
    c=c1;
    for(i=min(r1,r2);i<=max(r1,r2);i++)
        c=min(c,line[i]+1);
    c1=c;
    ans=abs(r1-r2)+abs(c-c2);
    for(i=r1;i<=n;i++){
        c=min(c,line[i]+1);
        ans=min(ans,abs(r1-i)+abs(r2-i)+abs(c-c2));
    }
    c=c1;
    for(i=r1;i>0;i--){
        c=min(c,line[i]+1);
        ans=min(ans,abs(r1-i)+abs(r2-i)+abs(c-c2));
    }
    printf("%d\n",ans);
    return 0;
}
