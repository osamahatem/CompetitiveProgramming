/*
ID: 19semse1
PROG: dualpal
LANG: C++
*/

#include<cstdio>
#include<cstring>

char num[35];

void convert(int n,int b){
    int len=0,temp=1;
    while(temp<=n){
        temp*=b;
        len++;
    }
    num[len]='\0';
    while(len>0){
        len--;
        num[len]=n%b+'0';
        n/=b;
    }
    return;
}

bool checkpal(){
    int len=strlen(num),i;
    for(i=0;i<len;i++)
        if(num[i]!=num[len-1-i])
            return false;
    return true;
}

bool isdualpal(int n){
    int i;
    bool flag=0;
    for(i=2;i<=10;i++){
        convert(n,i);
        if(checkpal() && flag)
            return true;
        if(checkpal())
            flag=1;
    }
    return false;
}

int main(){
    freopen("dualpal.in","r",stdin);
    freopen("dualpal.out","w",stdout);
    int n,s;
    scanf("%d%d",&n,&s);
    while(n>0){
        s++;
        if(isdualpal(s)){
            printf("%d\n",s);
            n--;
        }
    }
    return 0;
}
