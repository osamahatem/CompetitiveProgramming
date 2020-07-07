#include<cstdio>
#include<cstring>

int main(){
    int n,i,len,ans=0;
    char game[2005];
    scanf("%d ",&n);
    gets(game);
    len=strlen(game);
    for(i=n;i<len;i+=n){
        if(i>3){
            char c=game[i-1];
            if(game[i-2]==c && game[i-3]==c)
                ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
}
