#include<cstdio>
#include<cstring>
#include<string>

using namespace std;

string convert(char x){
    if(x=='>') return "1000";
    if(x=='<') return "1001";
    if(x=='+') return "1010";
    if(x=='-') return "1011";
    if(x=='.') return "1100";
    if(x==',') return "1101";
    if(x=='[') return "1110";
    if(x==']') return "1111";
}

int bintodec(string bin){
    int i,result=0,p=1;
    for(i=bin.size()-1;i>=0;i--){
        result+=(bin[i]-'0')*p;
        result%=1000003;
        p*=2;
        p%=1000003;
    }
    return result;
}

int main(){
    int len,i;
    string bin;
    char buffer[110];
    scanf("%s",buffer);
    len=strlen(buffer);
    for(i=0;i<len;i++)
        bin+=convert(buffer[i]);
    printf("%d\n",bintodec(bin));
    return 0;
}
