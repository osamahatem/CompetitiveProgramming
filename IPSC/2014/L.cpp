#include<bits/stdc++.h>

using namespace std;

int main(){
    freopen("l1 - binary.in","r",stdin);
    freopen("l1 - binary.out","w",stdout);
    char in[15];
    while(scanf("%s",in)!=EOF){
        int len=strlen(in);
        if(len>8){
            printf(" %s ",in);
            continue;
        }
        char c=0;
        for(int i=0;i<len;i++)
            c+=(in[i]-'0')*(1<<(7-i));
        printf("%c",c);
    }
    return 0;
}
