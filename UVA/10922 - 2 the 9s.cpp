#include<cstdio>
#include<cstring>

int sum(char in[],int len){
    int x=0,i;
    for(i=0;i<len;i++)
        x+=in[i]-'0';
    return x;
}

void re_in(char in[],int s){
    int i=0;
    while(s>0){
        in[i]='0'+s%10;
        i++;
        s/=10;
    }
    in[i]='\0';
}

int main(){
    char in[1005];
    int len,i,s,degree;
    while(1){
        scanf("%s",in);
        if(in[0]=='0')
            break;
        printf("%s is ",in);
        len=strlen(in);
        if(len==1){
            if(in[0]=='9')
                printf("a multiple of 9 and has 9-degree 1.\n");
            else
                printf("not a multiple of 9.\n");
            continue;
        }
        degree=0;
        while(len>1){
            s=sum(in,len);
            degree++;
            re_in(in,s);
            len=strlen(in);
        }
        if(in[0]=='9')
            printf("a multiple of 9 and has 9-degree %d.\n",degree);
        else
            printf("not a multiple of 9.\n");
    }
    return 0;
}
