#include<cstdio>
#include<algorithm>

using namespace std;

typedef struct comp{
    char c;
    long long l;
}comp;

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        long long k,i,l,ans=0;
        char c;
        comp in[100000],cur;
        scanf("%lld ",&k);
        for(i=0;i<k;i++){
            scanf("%c%lld ",&c,&l);
            cur.c=c;
            cur.l=l;
            in[i]=cur;
            ans+=l*(l+1)/2;
        }
        for(i=0;i<k;i++){
            int b=i-1,a=i+1;
            while(b>=0 && a<k && in[b].c==in[a].c){
                ans+=min(in[b].l,in[a].l);
                if(in[b].l!=in[a].l)
                    break;
                b--;
                a++;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
