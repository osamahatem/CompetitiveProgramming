#include<bits/stdc++.h>

using namespace std;

char pattern[100005],text[100005];
int pLen,tLen;
map<pair<int,int>,bool> memo;

bool solve(int pIdx,int tIdx){
    if(pIdx==pLen && tIdx==tLen)
        return true;
    if(pIdx==pLen || tIdx==tLen)
        return false;
    if(memo.count(make_pair(pIdx,tIdx)))
        return memo[make_pair(pIdx,tIdx)];
    bool ret=(pattern[pIdx]==text[tIdx]);
    if(!ret && isdigit(pattern[pIdx]))
        return memo[make_pair(pIdx,tIdx)]=ret;
    if(ret)
        return memo[make_pair(pIdx,tIdx)]=solve(pIdx+1,tIdx+1);
    int c=(pattern[pIdx]=='#');
    for(;c<tLen;c+=2){
        ret|=solve(pIdx+1,tIdx+c);
        if(ret)
            break;
    }
    return memo[make_pair(pIdx,tIdx)]=ret;
}

int main(){
    for(int t=1;scanf("%s",pattern)!=EOF;t++){
        pLen=strlen(pattern);
        for(int i=1;scanf("%s",text),text[0]!='E' && text[0]!='Q';i++){
            memo.clear();
            tLen=strlen(text);
            printf("%d.%d. %s\n",t,i,solve(0,0)?"match":"not");
        }
    }
    return 0;
}
