#include<cstdio>
#include<cstring>

int getpress(char x){
    if(x=='a' || x=='d' || x=='g' || x=='j' || x=='m' || x=='p' || x=='t' || x=='w' || x==' ')
        return 1;
    if(x=='b' || x=='e' || x=='h' || x=='k' || x=='n' || x=='q' || x=='u' || x=='x')
        return 2;
    if(x=='s' || x=='z')
        return 4;
    return 3;
}

int main(){
    int t,T,len;
    char sms[105];
    scanf("%d",&T);
    gets(sms);
    for(t=1;t<=T;t++){
        gets(sms);
        len=strlen(sms);
        int ans=0;
        for(int i=0;i<len;i++)
            ans+=getpress(sms[i]);
        printf("Case #%d: %d\n",t,ans);
    }
    return 0;
}
