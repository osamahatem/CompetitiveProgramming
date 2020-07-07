#include<cstdio>

int n,h;
char str[20];

void getstr(int i,int j){
    if(i==n && j==h){
        str[i]='\0';
        printf("%s\n",str);
        return;
    }
    if(i==n)
        return;
    str[i]='0';
    getstr(i+1,j);
    str[i]='1';
    getstr(i+1,j+1);
    return;
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&h);
        for(int i=0;i<20;i++)
            str[i]='0';
        getstr(0,0);
        if(t)
            printf("\n");
    }
    return 0;
}
