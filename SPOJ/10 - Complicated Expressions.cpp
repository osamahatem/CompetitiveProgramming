#include<bits/stdc++.h>

using namespace std;

int len;
char in[255];
map<char,int> pr;

char solve(int s,int e){
    while(s<len && in[s]!='(')
        s++;
    while(e && in[e]!=')')
        e--;
    if(e<s)
        return '*';
    char inside=solve(s+1,e-1);
    char before,after;
    if(s==0)
        before='(';
    else
        before=in[s-1];
    if(e==len-1)
        after=')';
    else
        after=in[e+1];
    if(before=='-' || before=='/')
        return (pr[before]<pr[after]) ? before : after;
    if(pr[inside]>=pr[before] && pr[inside]>=pr[after])
        in[s]=in[e]='#';
    return (pr[before]<pr[after]) ? before : after;
}

int main(){
    pr['*']=pr['/']=2;
    pr['+']=pr['-']=1;
    pr['(']=pr[')']=0;
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%s",in);
        len=strlen(in);
        solve(0,len-1);
        for(int i=0;i<len;i++)
            if(in[i]!='#')
                printf("%c",in[i]);
        printf("\n");
    }
    return 0;
}
