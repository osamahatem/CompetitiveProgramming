#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    char s[100005],t[100005];
    vector<char> needed;
    scanf("%s%s",s,t);
    int len=strlen(s),i,j,Cs[26],Ct[26],z=0;
    memset(Cs,0,sizeof Cs);
    memset(Ct,0,sizeof Ct);
    for(i=0;i<len;i++){
        Cs[s[i]-'A']++;
        Ct[t[i]-'A']++;
    }
    for(i=0;i<26;i++)
        z+=abs(Ct[i]-Cs[i]);
    z/=2;
    printf("%d\n",z);
    for(i=0;i<len;i++){
        if(Cs[s[i]-'A']<=Ct[s[i]-'A'] && Cs[s[i]-'A']>0){
            Cs[s[i]-'A']--;
            Ct[s[i]-'A']--;
            continue;
        }
        for(j=0;j<26;j++){
            if(Cs[j]==Ct[j])
                continue;
            if(j+'A'!=s[i] && Cs[j]>Ct[j] && Ct[j]>0)
                continue;
            if(Ct[j]>0){
                Cs[s[i]-'A']--;
                Ct[j]--;
                s[i]='A'+j;
                break;
            }
        }
    }
    printf("%s\n",s);
    return 0;
}
