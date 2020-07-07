#include<cstdio>
#include<cstring>

int main(){
    int len,del,i;
    char in[100005];
    scanf("%s",in);
    len=strlen(in);
    del=len-1;
    for(i=0;i<len;i++){
        if(in[i]=='0'){
            del=i;
            break;
        }
    }
    for(i=0;i<len;i++){
        if(i==del)
            continue;
        printf("%c",in[i]);
    }
    printf("\n");
    return 0;
}
