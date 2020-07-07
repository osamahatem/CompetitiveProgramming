#include<cstdio>
#include<cstring>

bool used[10];

bool unique_digits(int a){
    memset(used,0,sizeof used);
    int t;
    while(a>0){
        t=a%10;
        if(used[t])
            return false;
        used[t]=1;
        a/=10;
    }
    return true;
}

int main(){
    int n,m,i,ans;
    while(scanf("%d%d",&n,&m)!=EOF){
        ans=0;
        for(i=n;i<=m;i++)
            if(unique_digits(i))
                ans++;
        printf("%d\n",ans);
    }
	return 0;
}
