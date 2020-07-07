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
        vector<int> fail(len,0);
        cin>>needle>>haystack;
        int idx=1,pos=0;
        while(idx<len){
            if(needle[idx]==needle[pos])
                fail[idx++]=++pos;
            else if(pos>0)
                pos=fail[pos-1];
            else
                fail[idx++]=0;
        }
        pos=0;
        for(int i=0;i<haystack.length();i++){
            if(needle[pos]==haystack[i]){
                if(pos==len-1){
                    printf("%d\n",i-len+1);
                    pos=fail[pos];
                }else
                    pos++;
            }else{
                if(pos==0)
                    continue;
                pos=fail[pos-1];
                i--;
            }
        }
    }
    return 0;
}
