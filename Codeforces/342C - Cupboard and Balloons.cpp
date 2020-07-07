#include<cstdio>

int main(){
    int r,h;
    scanf("%d%d",&r,&h);
    int ans=h/r*2;
    if((h%r)*2>=r)
        ans+=2;
    else
        ans++;
    printf("%d\n",ans);
	return 0;
}
