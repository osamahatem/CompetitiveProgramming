#include<cstdio>
#include<cstring>

int main(){
    char in[1000005];
    scanf("%s",in);
    int i,len=strlen(in);
    for(i=0;i<len;i++){
        if(in[i]=='r'){
            printf("%d\n",i+1);
        }
    }
    for(i=len-1;i>=0;i--){
        if(in[i]=='l'){
            printf("%d\n",i+1);
        }
    }
    return 0;
}
