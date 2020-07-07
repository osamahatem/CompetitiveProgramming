#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int main(){
    char in[105];
    scanf("%s",in);
    int len=strlen(in),i,cnt[26],ans;
    memset(cnt,0,sizeof cnt);
    for(i=0;i<len;i++)
        cnt[in[i]-'a']++;
    ans=min(cnt['t'-'a'],cnt['i'-'a']);
    ans=min(ans,min((cnt['n'-'a']-1)/2,cnt['e'-'a']/3));
    printf("%d\n",ans);
    return 0;
}
