#include<cstdio>
#include<cstring>

int main(){
    char in[5005],bear[]="bear";
    int ans=0,i,j,last=0;
    scanf("%s",in);
    int len=strlen(in);
    for(i=0;i+3<len;i++){
        for(j=0;j<4;j++)
            if(in[i+j]!=bear[j])
                break;
        if(j==4)
            ans+=(i-last+1)*(len-i-3),last=i+1;
    }
    printf("%d\n",ans);
    return 0;
}
