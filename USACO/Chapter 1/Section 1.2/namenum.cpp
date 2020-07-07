/*
ID: 19semse1
PROG: namenum
LANG: C++
*/

#include<cstdio>
#include<cstring>
#include<map>
#include<string>
#include<vector>

using namespace std;

int getnum(char x){
    if(x=='A' || x=='B' || x=='C') return 2;
    if(x=='D' || x=='E' || x=='F') return 3;
    if(x=='G' || x=='H' || x=='I') return 4;
    if(x=='J' || x=='K' || x=='L') return 5;
    if(x=='M' || x=='N' || x=='O') return 6;
    if(x=='P' || x=='R' || x=='S') return 7;
    if(x=='T' || x=='U' || x=='V') return 8;
    if(x=='W' || x=='X' || x=='Y') return 9;
}

long long convert(char name[]){
    int len=strlen(name),i;
    long long num=0;
    for(i=0;i<len;i++)
        num=num*10+getnum(name[i]);
    return num;
}

int main(){
    FILE* in=fopen("dict.txt","r");
    FILE* out=fopen("namenum.out","w");
    long long n;
    int i;
    char temp[15];
    map<long long,vector<string> > dict;
    while(fscanf(in,"%s",temp)!=EOF)
        dict[convert(temp)].push_back(string(temp));
    fclose(in);
    in=fopen("namenum.in","r");
    fscanf(in,"%lld",&n);
    if(dict.count(n)){
        for(i=0;i<dict[n].size();i++)
            fprintf(out,"%s\n",dict[n][i].c_str());
    }else
            fprintf(out,"NONE\n");
    return 0;
}
