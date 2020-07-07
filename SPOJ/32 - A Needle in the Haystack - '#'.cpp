#include<bits/stdc++.h>

using namespace std;

int main(){
    int len;
    string needle,haystack;
    bool flag=0;
    while(scanf("%d",&len)!=EOF){
        if(flag)
            printf("\n");
        flag=1;
        cin>>needle>>haystack;
        int idx=1,pos=0,nLen=len;
        needle+="#"+haystack+"#";
        len=needle.length();
        vector<int> fail(len,0);
        while(idx<len){
            if(needle[pos]=='#'){
                printf("%d\n",idx-pos-nLen-1);
                pos=fail[pos-1];
            }else if(needle[pos]==needle[idx]){
                fail[idx++]=++pos;
            }else if(pos==0)
                idx++;
            else
                pos=fail[pos-1];
        }
    }
    return 0;
}
