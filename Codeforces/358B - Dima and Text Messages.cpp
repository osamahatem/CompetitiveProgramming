#include<cstdio>
#include<cstring>
#include<string>
#include<vector>

using namespace std;

int main(){
    int n,i,j,k,len;
    char word[100005],msg[100005];
    bool flag;
    vector<string> words;

    scanf("%d",&n);
    while(n--){
        scanf("%s",word);
        words.push_back((string)word);
    }
    scanf("%s",msg);

    j=0;
    len=strlen(msg);
    for(i=0;i<words.size() && j<len;i++){
        flag=0;
        for(;j<len;j++){
            if(msg[j]=='<' && !flag)
                flag=1;
            if(msg[j]=='3' && flag)
                break;
        }
        k=0;
        while(k<words[i].size() && j<len)
            if(msg[j++]==words[i][k])
                k++;
    }

    if(i==words.size() && k==words[i-1].size()){
        flag=0;
        for(;j<len;j++){
            if(msg[j]=='<' && !flag)
                flag=1;
            if(msg[j]=='3' && flag){
                printf("yes\n");
                return 0;
            }
        }
    }
    printf("no\n");

    return 0;
}
