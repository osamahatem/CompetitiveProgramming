#include<bits/stdc++.h>

using namespace std;

int main(){
    bool vis[26];
    memset(vis,0,sizeof vis);
    char in[1005];
    gets(in);
    int len=strlen(in);
    for(int i=0;i<len;i++){
        if(isalpha(in[i]))
            vis[in[i]-'a']=1;
    }
    int ans=0;
    for(int i=0;i<26;i++)
        ans+=vis[i];
    cout<<ans<<endl;
    return 0;
}
