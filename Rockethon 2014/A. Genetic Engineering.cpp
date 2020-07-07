#include<cstdio>
#include<cstring>

int main(){
    int i,len,ans=0,cur_len=1;
    char in[105];
    scanf("%s",in);
    len=strlen(in);
    for(i=1;i<len;i++){
        if(in[i]==in[i-1])
            cur_len++;
        else{
            if(cur_len%2==0)
                ans++;
            cur_len=1;
        }
    }
    if(cur_len%2==0)
        ans++;
    printf("%d\n",ans);
    return 0;
}
