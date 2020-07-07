#include<cstdio>
#include<cstring>

int main(){
    int n,m,u,l,r,d,i,j,len;
    char g[20][20],word[20];
    scanf("%d%d%d%d%d%d",&m,&n,&u,&l,&r,&d);
    for(i=0;i<m+u+d;i++){
        for(j=0;j<n+l+r;j++){
            if((i+j)%2==0)
                g[i][j]='#';
            else
                g[i][j]='.';
        }
        g[i][j]='\0';
    }
    for(i=0;i<m;i++){
        scanf("%s",word);
        len=strlen(word);
        for(j=0;j<len;j++)
            g[i+u][j+l]=word[j];
    }
    for(i=0;i<m+u+d;i++)
        printf("%s\n",g[i]);
    return 0;
}
