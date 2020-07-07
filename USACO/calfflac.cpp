/*
ID: 19semse1
PROG: calfflac
LANG: C++
*/

#include<cstdio>
#include<iostream>
#include<string>

using namespace std;

int main(){
    freopen("calfflac.in","r",stdin);
    freopen("calfflac.out","w",stdout);
    string temp,full,modified;
    int idx[20010],i,j=0,maxlen=0,maxst,maxed,len,st,ed;
    while(getline(cin,temp)){
        full+=temp+'\n';
    }
    for(i=0;i<full.size();i++){
        if(full[i]>='A' && full[i]<='Z'){
            modified+=full[i]+32;
            idx[j]=i;
            j++;
        }else if(full[i]>='a' && full[i]<='z'){
            modified+=full[i];
            idx[j]=i;
            j++;
        }
    }
    for(i=0;i<modified.size();i++){
        st=i-1;
        ed=i;
        while(modified[st]==modified[ed] && st>=0 && ed<modified.size()){
            st--;
            ed++;
        }
        st++;
        ed--;
        len=ed-st+1;
        if(len>maxlen){
            maxlen=len;
            maxst=st;
            maxed=ed;
        }
        st=i;
        ed=i;
        while(modified[st]==modified[ed] && st>=0 && ed<modified.size()){
            st--;
            ed++;
        }
        st++;
        ed--;
        len=ed-st+1;
        if(len>maxlen){
            maxlen=len;
            maxst=st;
            maxed=ed;
        }
    }
    printf("%d\n%.*s\n",maxlen,idx[maxed]-idx[maxst]+1,full.c_str()+idx[maxst]);
    return 0;
}
