#include<cstdio>
#include<algorithm>

using namespace std;

typedef struct interval{
    int a,b,c;
}interval;

bool cmp(const interval &a,const interval &b){
    if(a.a!=b.a)
        return a.a<b.a;
    return a.b>b.b;
}

int main(){
    int t,n,i,a,b,c,ans,common;
    interval num[50005];
    scanf("%d",&t);
    while(t--){
        ans=0;
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%d%d%d",&a,&b,&c);
            num[i].a=a;
            num[i].b=b;
            num[i].c=c;
        }
        sort(num,num+n,cmp);
        for(i=0;i<n;i++){
            if(i>0){
                common=num[i-1].b-num[i].a+1;
                if(common<0)
                    common=0;
                common=min(num[i-1].c,common);
                num[i].c=max(num[i].c-common,0);
            }
            printf("%d %d %d\n",num[i].a,num[i].b,num[i].c);
            ans+=num[i].c;
        }
        printf("%d\n",ans);
    }
	return 0;
}
