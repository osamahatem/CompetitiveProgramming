#include<cstdio>
#include<algorithm>

using namespace std;

int main(){
    int k,a,b,v,ans=0;
    scanf("%d%d%d%d",&k,&a,&b,&v);
    while(a){
        int sections=min(k-1,b);
        b-=sections;
        sections++;
        ans++;
        a-=min(a,sections*v);
    }
    printf("%d\n",ans);
    return 0;
}
