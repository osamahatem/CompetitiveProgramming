#include<bits/stdc++.h>

using namespace std;

struct letter{
    char c;
    vector<int> counts;
};

int main(){
    freopen("A. The Repeater.in","r",stdin);
    freopen("A. The Repeater.out","w",stdout);
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        bool flag=0;
        int n;
        char in[105];
        scanf("%d",&n);
        vector<letter> word;
        letter temp;
        scanf("%s",in);
        char last=in[0];
        int cnt=1,len=strlen(in);
        for(int i=1;i<len;i++){
            if(in[i]!=last){
                temp.c=last;
                temp.counts.clear();
                temp.counts.push_back(cnt);
                last=in[i];
                cnt=1;
                word.push_back(temp);
            }else
                cnt++;
        }
        temp.c=last;
        temp.counts.clear();
        temp.counts.push_back(cnt);
        word.push_back(temp);
        for(int i=1;i<n;i++){
            scanf("%s",in);
            len=strlen(in);
            int ind=0;
            for(int j=0;j<word.size();j++){
                int cnt=0;
                if(word[j].c!=in[ind]){
                    flag=1;
                    break;
                }
                while(ind<len && in[ind]==word[j].c)
                    ind++,cnt++;
                word[j].counts.push_back(cnt);
            }
            if(ind<len)
                flag=1;
            if(flag)
                break;
        }
        printf("Case #%d: ",t);
        if(flag){
            printf("Fegla Won\n");
            continue;
        }
        int ans=0;
        for(int i=0;i<word.size();i++){
            sort(word[i].counts.begin(),word[i].counts.end());
            int med=word[i].counts.size()/2;
            for(int j=0;j<word[i].counts.size();j++)
                ans+=abs(word[i].counts[j]-word[i].counts[med]);
        }
        printf("%d\n",ans);
    }
    return 0;
}
