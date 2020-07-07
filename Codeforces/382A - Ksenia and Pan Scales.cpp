#include<cstdio>
#include<cstring>
#include<cstdlib>

int main(){
    int i,j,len1,len2,c=0;
    bool flag=0;
    char in[100],extra[100];
    gets(in);
    len1=strlen(in);
    for(i=0;i<len1;i++){
        if(in[i]=='|'){
            flag=1;
            continue;
        }
        if(flag)
            c--;
        else
            c++;
    }
    gets(extra);
    len2=strlen(extra);
    if((len2-abs(c))%2!=0 || len2<abs(c)){
        printf("Impossible\n");
        return 0;
    }
    j=0;
    if(c>=0){
        for(i=0;i<(len2-abs(c))/2;i++)
            printf("%c",extra[j++]);
        printf("%s",in);
        while(j<len2)
            printf("%c",extra[j++]);
    }else{
        for(i=0;i<(len2-abs(c))/2+abs(c);i++)
            printf("%c",extra[j++]);
        printf("%s",in);
        while(j<len2)
            printf("%c",extra[j++]);
    }
    printf("\n");
    return 0;
}
