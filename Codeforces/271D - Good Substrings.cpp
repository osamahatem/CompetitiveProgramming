#include<bits/stdc++.h>

using namespace std;

int trie[1250000][26],node=0;

int main(){
    memset(trie,-1,sizeof trie);
    int bad[26],i,j,k,len,cur,sum;
    char in[1505];
    scanf("%s",in);
    for(i=0;i<26;i++){
        scanf("%1d",&bad[i]);
        bad[i]=1-bad[i];
    }
    scanf("%d",&k);
    len=strlen(in);
    for(i=0;i<len;i++){
        sum=cur=0;
        for(j=i;j<len;j++){
            sum+=bad[in[j]-'a'];
            if(sum>k)
                break;
            if(trie[cur][in[j]-'a']!=-1)
                cur=trie[cur][in[j]-'a'];
            else
                cur=trie[cur][in[j]-'a']=++node;
        }
    }
    printf("%d\n",node);
    return 0;
}
