/*
ID: 19semse1
PROG: palsquare
LANG: C++
*/

#include<cstdio>
#include<cstring>

int b;
char num[20];

void convert(int n){
    int len=0,temp=1;
    while(temp<=n){
        temp*=b;
        len++;
    }
    num[len]='\0';
    while(len>0){
        len--;
        num[len]=n%b+'0';
        if(num[len]>'9')
            num[len]='A'+n%b-10;
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

int main(){
    freopen("palsquare.in","r",stdin);
    freopen("palsquare.out","w",stdout);
    int i;
    scanf("%d",&b);
    for(i=1;i<=300;i++){
        convert(i*i);
        if(checkpal()){
            convert(i);
            printf("%s ",num);
            convert(i*i);
            printf("%s\n",num);
        }
    }
    return 0;
}
