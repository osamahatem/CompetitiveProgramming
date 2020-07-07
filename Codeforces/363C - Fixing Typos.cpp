#include<cstdio>
#include<cstring>

int main(){
    char in[200000],last='#';
    int len,cur_cnt=0,last_cnt=0,i;

    scanf("%s",in);
    len=strlen(in);

    for(i=0;i<len;i++){
        if(in[i]==last)
            cur_cnt++;
        else{
            last_cnt=cur_cnt;
            cur_cnt=1;
        }
        last=in[i];
        if(cur_cnt==3 || (last_cnt==2 && cur_cnt ==2)){
            in[i]='#';
            cur_cnt--;
        }
    }

    for(i=0;i<len;i++){
        if(in[i]!='#')
            printf("%c",in[i]);
    }
    printf("\n");

    return 0;
}
