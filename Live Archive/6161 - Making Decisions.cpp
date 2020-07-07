#include<cstdio>
#include<cstring>

int main(){
    int t,len;
    char in[1000000];

    scanf("%d",&t);
    while(t--){
        scanf("%s",in);
        len=strlen(in);

        printf("Do-it");
        if(in[len/2]!=in[len/2-1])
            printf("-Not");
        printf("\n");
    }
    return 0;
}
